public class GeoCoordinate
{
  GeoCoordinate(float latitude, float longitude)
  {
    this.latitude = latitude;
    this.longitude = longitude;
  }

  float latitude;
  float longitude;

  String toString() 
  {
    return latitude + ", " + longitude;
  }
}