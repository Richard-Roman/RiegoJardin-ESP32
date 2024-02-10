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

// Bloque para mostrar datos en el LCD
void mostrar(float temp, float hum1, int hum2){
  lcd.setCursor(0, 0);
  lcd.print("H. Suelo: ");
  lcd.print(hum2);
  lcd.print(" % ");
  lcd.setCursor(0, 1);
  lcd.print("T: ");
  lcd.print(temp);
  lcd.print("   ");
  lcd.print("H.");
  lcd.print(hum1);
}