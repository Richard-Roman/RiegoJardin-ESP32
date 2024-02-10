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

// Bloque que controla motor de riego
void ControlRegado(int humedad, int temperatura){
  if(Accionador == 1) { // Valor recibido del Broker
    if (humedad <= 60) {
      digitalWrite(MOTOR, LOW); // los reles funcionan con logica inversa
      Serial.println("Motor Encendido...");
    } else {
      digitalWrite(MOTOR, HIGH);
      Serial.println("Motor Apagado...");
      Accionador = 0;
    }
  } else {
    if(humedad <= 30){
      digitalWrite(MOTOR, LOW);
      Serial.println("Motor Encendido...");
    } else if (humedad <= 60) {
      if (temperatura >= 33) {
        digitalWrite(MOTOR, LOW);
        Serial.println("Motor Encendido...");
      } else {
        digitalWrite(MOTOR, HIGH);
        Serial.println("Motor Apagado...");
      }
    } else {
      digitalWrite(MOTOR, HIGH);
      Serial.println("Motor Apagado...");
    }
  }
}