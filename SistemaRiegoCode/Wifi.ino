/*
===============================================================================
Sistema de monitorización y riego automático con ESP32
===============================================================================

Código del proyecto desarrollado con ESP32. Permite gestionar
sensores de humedad y temperatura, controlar el riego mediante un
módulo de relé y se conecta a MQTT para la transmisión y recepción de datos.

Autor: [Richard Adan Roman Tocto]
Fecha: [3/02/2024]
Licencia: [GPL - 3.0]

===============================================================================
*/

void setup_wifi() {

  delay(10);
  Serial.println();
  Serial.print("Conectando a  ");
  Serial.println(ssid);

// La ESP32 se conecta a wifi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Direccion IP: ");
  Serial.println(WiFi.localIP());
}