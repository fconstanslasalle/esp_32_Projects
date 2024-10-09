
#include <WiFi.h>
#include <WebServer.h>

#define WIFI_SSID "LSG-CFGS" 
#define WIFI_PASSWORD "CFGS-L@S@lleGr@ci@"

WebServer server(80);

void handleRoot() {
  server.send(200, "text/plain", "Servidor ESP32 funcionando"); 
}

void setup() {
  delay(1000); 
  Serial.begin(115200);
  Serial.println("Iniciando sistema...");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }
  Serial.println("Conectado a WiFi");

  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
  Serial.println("Servidor HTTP iniciado");
}

void loop() {
  
  server.handleClient(); 
}
