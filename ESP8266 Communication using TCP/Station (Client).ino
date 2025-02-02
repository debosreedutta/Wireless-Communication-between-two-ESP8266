#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>

WiFiServer server(80);
const char* ssid = "Your SSID";
const char* password = "Your Password";

//Your IP address or domain name with URL path
const char* serverName = "192.168.4.1";
const char* message = "http://192.168.4.1/message";

void setup() {
  Serial.begin(9600);
  Serial.println();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while((WiFi.status() == WL_CONNECTED)) 
  { 
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("Connected to WiFi IP:");
  Serial.println(WiFi.localIP());
}

WiFiClient client;

void loop()
{  
  if(client.connect(serverName, 80))
  {
    client.print(" --A message as per your choice-- \n");
    client.stop();
    String c = client.readStringUntil('\n');
    Serial.println(c);
    }
}


