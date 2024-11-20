
#include <WiFi.h>
#include <WebServer.h>
#include <FastLED.h>

#define WIFI_SSID "LSG-CFGS" 
#define WIFI_PASSWORD "CFGS-L@S@lleGr@ci@"

WebServer server(80);

void handleRoot() {
  // Obtener la cadena del array de la solicitud
  String cadena_array;
  if (server.method() == HTTP_GET) {
    cadena_array = server.arg(0);
  } else if (server.method() == HTTP_POST) {
    cadena_array = server.arg("datos");
  }

  // Convertir la cadena en un array de enteros
  int valores[NUM_LEDS];
  int indice = 0;
  for (int i = 0; i < cadena_array.length(); i++) {
    if (cadena_array.charAt(i) == ',') {
      indice++;
    } else {
      valores[indice] = valores[indice] * 10 + (cadena_array.charAt(i) - '0');
    }
  }

  // Actualizar la matriz de LEDs con los valores del array
  for (int i = 0; i < NUM_LEDS; i++) {
    if (valores[i]!=0){
      leds[i]=CRGB::White;
    }
    else{
      leds[i]=CRGB::Black
    }
  }
  FastLED.show();

  // Enviar una respuesta al cliente
  server.send(200, "text/plain", "Array recibido correctamente");
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

    // Definim la ruta per si ens ve una petició via get o post.
  server.on("/", HTTP_GET, handleRoot);
  server.on("/", HTTP_POST, handleRoot);
  //server.on("/", handleRoot);
  server.begin();
  Serial.println("Servidor HTTP iniciado");
}

void loop() {
  
  server.handleClient(); 
}
