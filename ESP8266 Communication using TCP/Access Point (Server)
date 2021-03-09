#include <ESP8266WiFi.h>   
#include <ESP8266WebServer.h>  
#include <ArduinoJson.h>   
#include<WiFiClient.h>


const char* ssid = "your SSID";
const char* password = "your Password";

WiFiServer server(80);

void setup(){
  // Serial port for debugging purposes
  Serial.begin(9600);
  Serial.println();
  
  // Setting the ESP as an access point
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();  
  Serial.print("AP IP address: ");
  Serial.println(IP);  

  // Start server
  server.begin();
}

void loop(){
  // listen for incoming clients
  WiFiClient client = server.available();
  if (client && client.connected()) {
    client.print(" --A message as per your choice-- \n");
    String data = client.readStringUntil('\n');
    Serial.println(data);
    client.stop();
    } 
}
