/*Write a code in Arduino C for nodemcu to connect 
 to wifi and then after fetching the gateway IP,
 make your assigned IP address static
 -----------------------------------------------------------------------
 NISHANTH SHASTRY - Q1
 -----------------------------------------------------------------------
 */

#include <ESP8266WiFi.h>

int status = WL_IDLE_STATUS;     


char ssid[] = "WIFI_SSID";                 //SSID

char pass[] = "PASS_KEY";                 //PASSWORD

IPAddress gateway;
IPAddress new_IP(192,168,0,115);          // Required static IP
IPAddress subnet(255,255,255,0);          //SUBNET

void setup()
{
  Serial.begin(115200);

 WiFi.begin(ssid, pass);                //Connection request

  while ( WiFi.status() != WL_CONNECTED )
{
  delay(500);
  Serial.print(".");
}
  Serial.println("connected");
 
  // print your gateway address:
  gateway = WiFi.gatewayIP();
  Serial.print("GATEWAY: ");
  Serial.println(gateway);                  //Gateway IP
  delay(1000);
  
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());          //Current IP

  
  //------------------------------Initial connection to fetch Gateway ends----------

  
  WiFi.config(new_IP,gateway,subnet);      //New static IP configuration
                                                        
  
  Serial.print("Attempting to connect to SSID: ");
  while ( status != WL_CONNECTED) {
    
    Serial.println(ssid);    
    status = WiFi.begin(ssid, pass);       //Reconnection

    // wait 10 seconds for connection:
      delay(10000);
      Serial.print("wait..");
    }
  Serial.println("connected");

  // print your WiFi shield's IP address:
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());          //The new assigned IP

  
  }


void loop () {}
