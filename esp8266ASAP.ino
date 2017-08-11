// Code to make esp8266 an access point with webserver 

#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ESP8266WebServer.h>

const char* ssid ="Ira"; 
const char* password ="12345678";

ESP8266WebServer server(80); 

void handleRoot(void)
{
  server.send(200, "text/plain", "hello from esp8266!");
}

void setup(void)
{
  Serial.begin(115200); 
  Serial.print(""); 
  WiFi.mode(WIFI_AP); 
  WiFi.softAP(ssid, password); 
  IPAddress myIP = WiFi.softAPIP(); 
  Serial.print("My Ip:"); 
  Serial.println(myIP); 
  server.on("/", handleRoot);
  server.begin(); 
  Serial.println("HTTP Server started");
}

void loop(void)
{
  server.handleClient();
}
