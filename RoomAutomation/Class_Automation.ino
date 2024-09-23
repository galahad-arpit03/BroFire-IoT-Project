#include <ESP8266WiFi.h>
#define trigPin 1
#define echoPin 3
#define motioPin D8



const char* ssid = "Server Room";  
const char* password = "@#ServerRoom@#";   
WiFiServer server(80);

void setup() {
  Serial.begin(9600);

  //Relay Switch Pins
  pinMode(D0, OUTPUT);  
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);  
  pinMode(D5, OUTPUT);  
  pinMode(D6, OUTPUT);  
  pinMode(D7, OUTPUT);
  //Relay Switch Pins Ends here

  //Ultrasonic Sensor Pins
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  //Ultrasonic Sensor Pins Ends Here

  //Motion Detector Pins
  pinMode(motionPin,INPUT);
   

  // Connect to hotspot
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("Hotspot IP address: ");
  Serial.println(myIP);
  // Start server
  server.begin();


}

void loop() {
  WiFiClient client = server.available();
  String currentLine = "";
  if (client) {
    Serial.println("New client connected");
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.println("<html>");
            client.println("<head><meta name=""viewport"" content=""width=device-width, initial-scale=1.0><title>NodeMCU Light Control</title></head>");
            client.println("<body>");
            client.println("<h1>104-Control Panel</h1>");
            client.println("<form method='get'>");
            client.println("<label>Light 1</label><input type='submit' name='l1off' value='Turn Off'> ");
            client.println("<input type='submit' name='l1on' value='Turn On'><br><br><br>");
            client.println("<label>Light 2</label><input type='submit' name='l2off' value='Turn Off'>");
            client.println("<input type='submit' name='l2on' value='Turn On'><br><br><br>");

            client.println("<label>Fan 1</label><input type='submit' name='f1off' value='Turn Off'>");
            client.println("<input type='submit' name='f1on' value='Turn On'><br><br><br>");
            client.println("<label>Fan 2</label><input type='submit' name='f2off' value='Turn Off'>");
            client.println("<input type='submit' name='f2on' value='Turn On'><br><br><br>");
            
            client.println("</form>");
            client.println("</body>");
            client.println("</html>");
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
        
        if (currentLine.endsWith("GET /?l1off")) {
          Serial.println("Light turned on");
          digitalWrite(D2, HIGH);
          client.println("HTTP/1.1 302 Found");
          client.println("Location: /");
          client.println();
        }
        else if (currentLine.endsWith("GET /?l1on")) {
          Serial.println("Light turned off");
          digitalWrite(D2, LOW);
          client.println("HTTP/1.1 302 Found");
          client.println("Location: /");
          client.println();
        }
        else if (currentLine.endsWith("GET /?l2off")) {
          Serial.println("Light turned off");
          digitalWrite(D1, HIGH);
          client.println("HTTP/1.1 302 Found");
          client.println("Location: /");
          client.println();
        
        } 
        else if (currentLine.endsWith("GET /?l2on")) {
          Serial.println("Light turned off");
          digitalWrite(D1, LOW);
          client.println("HTTP/1.1 302 Found");
          client.println("Location: /");
          client.println();
        }
        else if (currentLine.endsWith("GET /?f1off")) {
          Serial.println("Light turned off");
          digitalWrite(D3, HIGH);
          client.println("HTTP/1.1 302 Found");
          client.println("Location: /");
          client.println();
        
        } 
        else if (currentLine.endsWith("GET /?f1on")) {
          Serial.println("Light turned off");
          digitalWrite(D3, LOW);
          client.println("HTTP/1.1 302 Found");
          client.println("Location: /");
          client.println();
        }
        else if (currentLine.endsWith("GET /?f2off")) {
          Serial.println("Light turned off");
          digitalWrite(D4, HIGH);
          client.println("HTTP/1.1 302 Found");
          client.println("Location: /");
          client.println();
        
        } 
        else if (currentLine.endsWith("GET /?f2on")) {
          Serial.println("Light turned off");
          digitalWrite(D4, LOW);
          client.println("HTTP/1.1 302 Found");
          client.println("Location: /");
          client.println();
        }
      }
    }
    client.stop();
    Serial.println("Client disconnected");
  }
}