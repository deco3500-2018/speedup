#include <SPI.h>
#include <Ethernet.h> 
int greenled = 4;
int blueled = 5;
int whiteled = 6;
int redled = 7;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };   //mac address
byte ip[] = { 169, 254, 235, 159 };                      // Lan IP
byte gateway[] = { 10, 89, 180, 1 };                   // gateway IP
byte subnet[] = { 255, 255, 0, 0 };                  
EthernetServer server(80);                             
String buffer;

void setup() {
 Serial.begin(9600);
 pinMode(greenled, OUTPUT);
 pinMode(whiteled, OUTPUT);
 pinMode(redled, OUTPUT);
 pinMode(blueled, OUTPUT);
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  EthernetClient ethernet_shield = server.available();
  if (ethernet_shield) {
    while (ethernet_shield.connected()) {   
      if (ethernet_shield.available()) {
        char c = ethernet_shield.read();
        if (buffer.length() < 100) {
          buffer += c;
           }

           if (c == '\n') {          
           Serial.println(buffer); 
           ethernet_shield.println("HTTP/1.1 200 OK"); 
           ethernet_shield.println("Content-Type: text/html");
           ethernet_shield.println();     
           ethernet_shield.println("");
           ethernet_shield.println("");
           ethernet_shield.println("Leds Controlled by webpage");
           ethernet_shield.println("");
           ethernet_shield.println(""); 
           ethernet_shield.println("</pre> <h2>Controlling Leds through Webpage</h2>");
ethernet_shield.println("<h4>White LED</h4>");
ethernet_shield.println("<a href='?whiteledon'><button style='border-radius: 12px;'> ON</button></a>");
ethernet_shield.println("<a href='?whiteledoff'><button style='border-radius: 12px;'> OFF</button></a>");
ethernet_shield.println(" ");
ethernet_shield.println("<h4 style='color: red;'>Red LED</h4>");
ethernet_shield.println("<a href='?redledon'><button style='background-color: red; border-radius: 12px;'> ON</button></a>");
ethernet_shield.println("<a href='?redledoff'><button style='background-color: red; border-radius: 12px;'> OFF</button></a>");
ethernet_shield.println(" ");
ethernet_shield.println("");
ethernet_shield.println("<h4 style='color: #1f5ec4;'>Blue LED</h4>");
ethernet_shield.println("<a href='?blueledon'><button style='background-color: #1f5ec4; border-radius: 12px;'> ON</button></a>");
ethernet_shield.println("<a href='?blueledoff'><button style='background-color: #1f5ec4; border-radius: 12px;'> OFF</button></a>");
ethernet_shield.println("<pre>");
           ethernet_shield.println("");
     
           delay(1);
           ethernet_shield.stop();
           
           if (buffer.indexOf("?greenledon")>0){
               digitalWrite(greenled, HIGH);
           }
            if (buffer.indexOf("?greenledoff")>0){
               digitalWrite(greenled, LOW);
           }
            if (buffer.indexOf("?blueledon")>0){
               digitalWrite(blueled, HIGH);
           }
            if (buffer.indexOf("?blueledoff")>0){
               digitalWrite(blueled, LOW);
           }
            if (buffer.indexOf("?whiteledon")>0){
               digitalWrite(whiteled, HIGH);
           }
            if (buffer.indexOf("?whiteledoff")>0){
               digitalWrite(whiteled, LOW);
           }
            if (buffer.indexOf("?redledon")>0){
               digitalWrite(redled, HIGH);
           }
            if (buffer.indexOf("?redledoff")>0){
               digitalWrite(redled, LOW);
           }
            //clearing string for next read
            buffer="";  
           
         }
       }
    }
  }
}
