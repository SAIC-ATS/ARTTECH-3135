import processing.data.*;
import processing.core.*;
import java.util.*;
import java.io.*;
import java.util.concurrent.*;
import java.util.List;
import java.lang.reflect.Method;
import java.net.*;
import java.io.IOException;


public class FlightClient
  extends TimerTask
{
  public int totalTracked;
  GeoCoordinate minPosition;
  GeoCoordinate maxPosition;

  Method onFlightAdded;
  Method onFlightUpdated;
  Method onFlightRemoved;

  PApplet parent;
  Timer timer;

  // The last set of flights.
  ConcurrentHashMap<String, Flight> flightMap;
  ConcurrentHashMap<String, Flight> addedFlights;
  ConcurrentHashMap<String, Flight> updatedFlights;
  Vector<String> removedFlights;

  public FlightClient(PApplet parent, GeoCoordinate minPosition, GeoCoordinate maxPosition)
  {
    this.parent = parent;
    this.flightMap = new ConcurrentHashMap<String, Flight>();

    // Emit events right before draw.
    parent.registerMethod("pre", this);

    try {
      onFlightAdded = parent.getClass().getMethod("onFlightAdded", new Class[] { String.class, Flight.class });
      onFlightUpdated = parent.getClass().getMethod("onFlightUpdated", new Class[] { String.class, Flight.class });
      onFlightRemoved = parent.getClass().getMethod("onFlightRemoved", new Class[] { String.class });
      timer = new Timer();
    } 
    catch (Exception e) {
    }

    timer = new Timer();
    setBounds(minPosition, maxPosition);
    setRefresh(3000);
  }

  void setRefresh(int milliseconds)
  {
    timer.schedule(this, new Date(), milliseconds);
  }

  @Override
    public void run() 
  {
    try {

      update();
    }
    catch (Exception e)
    {
      e.printStackTrace();
    }
  }

  public void setBounds(GeoCoordinate minPosition, GeoCoordinate maxPosition)
  {
    this.minPosition = minPosition;
    this.maxPosition = maxPosition;
  }

  public void update() throws Exception
  {
    String _url = "https://data-live.flightradar24.com/zones/fcgi/feed.js?bounds={maxLat},{minLat},{minLon},{maxLon}&faa=1&mlat=1&flarm=1&adsb=1&gnd=1&air=1&vehicles=1&estimated=1&maxage=7200&gliders=1&stats=1";
    _url = _url.replaceAll("\\{minLat\\}", Float.toString(minPosition.latitude));
    _url = _url.replaceAll("\\{minLon\\}", Float.toString(minPosition.longitude));
    _url = _url.replaceAll("\\{maxLat\\}", Float.toString(maxPosition.latitude));
    _url = _url.replaceAll("\\{maxLon\\}", Float.toString(maxPosition.longitude));

  println(_url);

    URL url= new URL(_url);
    URLConnection connection = url.openConnection();
    // Use the current chrome user agent.
    connection.setRequestProperty("User-Agent", "Mozilla/5.0 AppleWebKit/537.36 (KHTML, like Gecko; compatible; Googlebot/2.1; +http://www.google.com/bot.html) Safari/537.36" );

    InputStream inputStream = connection.getInputStream();
    ByteArrayOutputStream result = new ByteArrayOutputStream();

    byte[] buffer = new byte[1024];
    int length;
    while ((length = inputStream.read(buffer)) != -1) {
      result.write(buffer, 0, length);
    }

    JSONObject json = parent.parseJSONObject(result.toString("UTF-8"));
    // Copy the set.  Accessing keySet directly modifies the backing map!
    Set<String> ids = new HashSet<String>(flightMap.keySet().size());
    for (String id : flightMap.keySet()) ids.add(id);

    // We seperate these to prevent thread sync problems on the client side.
    addedFlights = new ConcurrentHashMap<String, Flight>();
    updatedFlights = new ConcurrentHashMap<String, Flight>();
    removedFlights = new Vector<String>();

    for (Object _id : json.keys())
    {
      String id = (String)_id;
      if (id.equals("full_count")) {
        totalTracked = json.getInt("full_count");
      } else if (id.equals("version")) {
        // skip
      } else if (id.equals("stats")) {
        // skip
      } else 
      {
        Flight flight = new Flight(json.getJSONArray(id)); 

        if (ids.contains(id))
        {
          updatedFlights.put(id, flight);
        } else 
        {
          addedFlights.put(id, flight);
        }

        flightMap.put(id, flight);
        ids.remove(id);
      }
    }

    for (String id : ids)
    {
      flightMap.remove(id);
      removedFlights.add(id);
    }
  }

  void pre()
  {
    // We jump on the pre callback to prevent the client from needing to do thread sync or use thread-safe containers.
    if (onFlightAdded != null && addedFlights != null)  
    {
      Iterator<Map.Entry<String, Flight>> it = addedFlights.entrySet().iterator();
      while (it.hasNext()) {
        Map.Entry<String, Flight> entry = it.next();
        try 
        {
          onFlightAdded.invoke(parent, entry.getKey(), entry.getValue());
        }
        catch (Exception e) {
        }
        it.remove();
      }
      addedFlights.clear();
    }

    if (onFlightUpdated != null && updatedFlights != null)  
    {
      Iterator<Map.Entry<String, Flight>> it = updatedFlights.entrySet().iterator();
      while (it.hasNext()) {
        Map.Entry<String, Flight> entry = it.next();
        try 
        {
          onFlightUpdated.invoke(parent, entry.getKey(), entry.getValue());
        }
        catch (Exception e) {
        }
        it.remove();
      }
      updatedFlights.clear();
    }

    if (onFlightRemoved != null && removedFlights != null)  
    {
      for (String id : removedFlights) {
        try {
          onFlightRemoved.invoke(parent, id);
        }
        catch (Exception e) {
        }
      }
      removedFlights.clear();
    }
  }
}