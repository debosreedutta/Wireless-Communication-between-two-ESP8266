#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>

WiFiServer server(80);
const char* ssid = "ESP8266-Access-Point";
const char* password = "123456789";

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
    // Coin Toss function to randomly select a device
    int rand_data = rand() % 2;                 //Generating Random int data between 0 and 1
    client.print((String)rand_data + "\n");     // Sending the generated data to the other device
    String compare_data = client.readStringUntil('\n');           //Receiving the random int generated by the other device
    Serial.println("Data_recieved = " + (String)compare_data);    // Printing the data received from the other deivce to serial monitor
    
    if(rand_data > compare_data.toInt()) {            // When we win the toss
      Serial.println("YESS");                            //Prints Yes to the serial monitor, means this device won
      client.print("This !");                            // Sends a string called "This" to the other device, There was no real use I was just experimenting
      }
    else if(rand_data == compare_data.toInt()) {
      Serial.println("Both EQUAL");
      }
    else {  
      String compare =  client.readStringUntil('!');        // Revieveing the "This" string from the other device if we lose
      Serial.println(compare);                               // Prints "This" to make sure we recieved it
      Serial.println("NOO");                               // Prints noo to serial monitor means this device lost
      } 
      client.stop();                                      //Need to stop the client only once
  }
}

