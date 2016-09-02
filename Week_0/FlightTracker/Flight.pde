
public class Flight
{
  String id; // A unique id.

  GeoCoordinate position;
  float heading; // Degrees
  float altitude; // Feet
  float speed; // Knots

  Flight()
  {
  }

  Flight(JSONArray json)
  {
    id = json.getString(0);
    position = new GeoCoordinate(json.getFloat(1), json.getFloat(2));
    heading = json.getFloat(3);
    altitude = json.getFloat(4);
    speed = json.getFloat(5);
  }

  public String toString() 
  {  
    return id + " " + position + " " + heading + " " + altitude +  " " + speed;
  }
}