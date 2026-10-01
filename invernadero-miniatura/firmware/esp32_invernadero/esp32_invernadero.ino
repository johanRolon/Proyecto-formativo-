// Invernadero miniatura - ESP32
// Versión inicial: servidor web con datos de ejemplo y control de salidas.

#include <WiFi.h>
#include <WebServer.h>

const char* WIFI_SSID = "TU_RED";
const char* WIFI_CLAVE = "TU_CLAVE";

// Pines (ajustar según el montaje)
const int PIN_SUELO = 34;
const int PIN_BOMBA = 26;
const int PIN_VENTILADOR = 27;
const int PIN_LUZ = 25;

WebServer servidor(80);

void enviarDatos() {
  // TODO: leer el DHT y la fotorresistencia
  float temperatura = 0;
  float humedadAire = 0;
  int humedadSuelo = analogRead(PIN_SUELO);
  int luz = 0;

  String json = "{";
  json += "\"temperatura\":" + String(temperatura) + ",";
  json += "\"humedadAire\":" + String(humedadAire) + ",";
  json += "\"humedadSuelo\":" + String(humedadSuelo) + ",";
  json += "\"luz\":" + String(luz) + ",";
  json += "\"bomba\":" + String(digitalRead(PIN_BOMBA)) + ",";
  json += "\"ventilador\":" + String(digitalRead(PIN_VENTILADOR)) + ",";
  json += "\"luzLed\":" + String(digitalRead(PIN_LUZ));
  json += "}";

  servidor.sendHeader("Access-Control-Allow-Origin", "*");
  servidor.send(200, "application/json", json);
}

// Ejemplo de uso: /control?dispositivo=bomba&estado=1
void controlar() {
  String dispositivo = servidor.arg("dispositivo");
  int estado = servidor.arg("estado").toInt();

  if (dispositivo == "bomba") digitalWrite(PIN_BOMBA, estado);
  if (dispositivo == "ventilador") digitalWrite(PIN_VENTILADOR, estado);
  if (dispositivo == "luz") digitalWrite(PIN_LUZ, estado);

  servidor.sendHeader("Access-Control-Allow-Origin", "*");
  servidor.send(200, "text/plain", "OK");
}

void setup() {
  Serial.begin(115200);

  pinMode(PIN_BOMBA, OUTPUT);
  pinMode(PIN_VENTILADOR, OUTPUT);
  pinMode(PIN_LUZ, OUTPUT);

  WiFi.begin(WIFI_SSID, WIFI_CLAVE);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("IP del ESP32: ");
  Serial.println(WiFi.localIP());

  servidor.on("/datos", enviarDatos);
  servidor.on("/control", controlar);
  servidor.begin();
}

void loop() {
  servidor.handleClient();
}
