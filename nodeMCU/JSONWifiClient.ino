#include <ArduinoJson.h>
#include <ESP8266WiFi.h>

/*
 *  This will be a basic sketch for a FloraSync water sensor
 *
 */



const char* ssid     = "yourAP_SID";
const char* password = "yourWiFiPassword";

const char* host = "florasync.org";
const char* streamId   = "....................";
const char* privateKey = "....................";

void setup() {
  Serial.begin(115200);
  delay(10);
  
  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

int value = 0;

void loop() {
  // Check every 30 seconds
  delay(30000);
  ++value;

  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  // We now create a URI for the request
  String url = "/Nodes/test.json";
  /*url += streamId;
  url += "?private_key=";
  url += privateKey;
  url += "&value=";
  url += value;*/
  
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    // This will grab our dummy json object that looks like this
    // {"sensor":"gps","time":1351824120,"data":[48.756080,2.302038]}
    String line = client.readStringUntil('\r');
    Serial.print(line);
    DynamicJsonBuffer jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(line);
  
    long time = root[String("time")];
    String sensor = root["sensor"];
    // Lastly, you can print the resulting JSON to a String
    String output;
    root.printTo(output);
    Serial.println(output);
    if(sensor.length() > 1){
    Serial.print("This is a test part of the string " + sensor);
    }
  }
  
  Serial.println();
  Serial.println("closing connection");
}
