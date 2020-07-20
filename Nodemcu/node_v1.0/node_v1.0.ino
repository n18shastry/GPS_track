#include <TinyGPS++.h> // library for GPS module
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SPI.h>

TinyGPSPlus gps;  // The TinyGPS++ object


SoftwareSerial ss(4, 5); 
const char* ssid = "Shastry"; 
const char* password = "9480761391"; 
char server[] = "192.168.0.105";
float latitude , longitude;
String  lat_str , lng_str;
//WiFiServer server(80);
WiFiClient client;    

void setup()
{
  Serial.begin(115200);
  ss.begin(9600);
  delay(1000);

  WiFi.begin(ssid, password);
 
  Serial.print("Connecting.");

  while ( WiFi.status() != WL_CONNECTED )
{
  delay(500);
  Serial.print(".");
}
  Serial.println("connected");
  delay(1000);
}


void loop()
{
  while (ss.available() > 0) //while data is available
    if (gps.encode(ss.read())) //read gps data
    {
      if (gps.location.isValid()) //check whether gps location is valid
      {
        latitude = gps.location.lat();
        lat_str = String(latitude , 6); // latitude location is stored in a string
        longitude = gps.location.lng();
        lng_str = String(longitude , 6); //longitude location is stored in a string
             
      }
     }
     Sending_To_phpmyadmindatabase(12.768, 75.182);
     delay(60000);
    }

 void Sending_To_phpmyadmindatabase(float latitude,float longitude)   
 {
   if (client.connect(server, 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    Serial.print("GET /info_node.php?lat=");
    client.print("GET /info_node.php?lat=");     
    Serial.println(latitude);
    client.print(latitude);
    client.print("&lon=");
    Serial.println("&lon=");
    client.print(longitude);
    Serial.println(longitude);
    client.print(" ");      
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: 192.168.0.105");
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
   
  }
 }
