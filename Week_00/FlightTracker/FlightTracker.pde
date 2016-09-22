import java.util.*;

//GeoCoordinate minPosition = new GeoCoordinate(41.90, -88.10);
//GeoCoordinate maxPosition = new GeoCoordinate( 42.09, -87.72);

GeoCoordinate minPosition = new GeoCoordinate(41.45, -89.45);
GeoCoordinate maxPosition = new GeoCoordinate(42.57, -86.42);

//GeoCoordinate minPosition = new GeoCoordinate(-85, -180);
//GeoCoordinate maxPosition = new GeoCoordinate( 85,  180);

HashMap<String, Vector<GeoCoordinate>> tracks;

FlightClient client;

void setup()
{
  size(800, 800);
  client = new FlightClient(this, minPosition, maxPosition);
  tracks = new HashMap<String, Vector<GeoCoordinate>>();
}


void draw()
{
  background(0);
  fill(255, 127);
  for (Vector<GeoCoordinate> waypoints : tracks.values())
  {
    beginShape();
    strokeWeight(2);
    noFill();
    stroke(255);
    for (int i = 0; i < waypoints.size(); ++i)
    {  
      float x = getX(waypoints.get(i).longitude);
      float y = getY(waypoints.get(i).latitude);

      stroke(255);

      //map(i, 0, waypoints.size(), 0, 255));
      strokeWeight(2);

      curveVertex(x, y);       
      if (i == 0 || i == waypoints.size() - 1)
        curveVertex(x, y);

      if (i == 0) 
      {
        noFill();
        stroke(127);
        ellipse(x, y, 10, 10);
      }
    }
    endShape();
  }
}


void onFlightAdded(String id, Flight flight)
{
  Vector<GeoCoordinate> track = new Vector<GeoCoordinate>();
  track.add(flight.position);
  tracks.put(id, track);
}

void onFlightUpdated(String id, Flight flight)
{
  tracks.get(id).add(flight.position);
}

void onFlightRemoved(String id)
{
  tracks.remove(id);
}

float getX(float longitude)
{
  // An arbitrary flattening of the earth, probably only valid for small longitudinal angles.
  // Should use a real projection e.g. mercator.
  return map(longitude, minPosition.longitude, maxPosition.longitude, 0, width);
}

float getY(float latitude)
{
  // An arbitrary flattening of the earth, probably only valid for small latitudinal angles.
  // Should use a real projection e.g. mercator.
  return map(latitude, minPosition.latitude, maxPosition.latitude, 0, height);
}