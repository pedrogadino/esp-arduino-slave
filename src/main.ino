#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

const char* ssid = "Central";
const char* password = "123456789";

WiFiEventHandler gotIpEventHandler, disconnectedEventHandler;

void setup(){
    Serial.begin(115200);
    Serial.println();

    pinMode(D7, OUTPUT);

    WiFi.mode(WIFI_STA);
    
    Serial.println("Slave Ready!");

    gotIpEventHandler = WiFi.onStationModeGotIP([](const WiFiEventStationModeGotIP& event)
    {
        Serial.print("Station connected, IP: ");
        Serial.println(WiFi.localIP());
    });

    disconnectedEventHandler = WiFi.onStationModeDisconnected([](const WiFiEventStationModeDisconnected& event)
    {
        Serial.println("Station disconnected");
    });

    Serial.printf("Connecting to %s ...\n", ssid);

    WiFi.begin(ssid, password);

    server.on("/cmd", cmdPage);
    server.begin();
}

void loop(){
    server.handleClient();
}


void cmdPage(){
    String status = server.arg("status");

    if(status == "1"){
        digitalWrite(D7, HIGH);
    }

    if(status == "0"){
        digitalWrite(D7, LOW);
    }

    Serial.println("Comando recebido: " + status);

    server.send(200, "application/json", "{'success': 'Executed!'}");
}
