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

// Bloque para la reconeccion a MQTT
void reconnect() {
  while (!client.connected()) {
    Serial.print("Conexion MQTT perdida...");
    String clientId = "ESP32";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str(), usernameMQTT, passwordMQTT) ) {
      Serial.println("conectado");
      client.subscribe("regado/motor");
    } else {
      Serial.print(" Error de conexión, rc=");
      Serial.print(client.state());
      Serial.println("Intentando de nuevo en 5s...");
      delay(5000);
    }
  }
}

// Bloque para recibir datos del MQTT

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensaje recibido [");
  Serial.print(topic);
  Serial.print("] ");

  
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    Estado += (char)payload[i];
  }
  Serial.println();

  Serial.print("Contenido del mensaje: ");
  Serial.println(Estado);
  
  if (Estado == "R") {
    Accionador = 1;
    Estado = "";
  }
}