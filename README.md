# Sistema de monitorización y riego automático con ESP32.
Sistema de Riego Automático para gestionar y controlar el riego remoto de jardines, con monitoreo de temperatura y humedad usando ESP32 y MQTT.
## Qué hace el proyecto:
El proyecto utiliza un ESP32 para gestionar un sistema de riego automático, integrando sensores DHT11 y FC-28, un módulo de relé y una pantalla LCD. El ESP32 se conecta a un servidor MQTT, publica datos de sensores y recibe comandos para controlar el riego. Además, se implementa una aplicación en Node-RED para visualizar y controlar el sistema a través de interfaz gráfica.
## Por qué el proyecto es útil:
El proyecto permite automatizar el riego de un jardín de manera eficiente y remota. Monitorea la temperatura y la humedad del suelo, ajustando el riego en tiempo real. La conexión por MQTT facilita la gestión desde cualquier ubicación.

## Cómo construir el proyecto (No se presenta una guía detallada del armado físico): 
1. Adquirir los siguientes componentes:
    - ESP32-WROOM-32 38-PIN
    - Sensor de temperatura y humedad DHT11.
    - Sensor de humedad de suelo FC-28
    - Módulo de relé.
    - Pantalla LCD.
    - Cables.
    - Protoboard.
2. Descargar el código del proyecto desde GitHub.
4. Instalar las bibliotecas necesarias para los sensores, conexión segura a wifi y MQTT.
5. Configurar sus credenciales WIFI, MQTT y cargar al ESP32.
6. Implementar el hardware del sistema.
    - Sensor de humedad y temperatura DHT11 – Pin 26.
    - Pantalla LCD – RS en el Pin 22, Enable en el Pin 23, y los pines de datos en 5, 18, 19 y 21.
    - Relé – Pin 0.
    - Sensor de humedad - Pin 33.
7. Importar el flujo de datos en Node-Red, configurar el MQTT.
8. Ejecutar la aplicación Node-Red para visualizar y controlar el riego de manera intuitiva.

> [!IMPORTANT]
> - Asegúrese de personalizar el código con sus propias credenciales de conexión WiFi y MQTT..
> - Modifica el flujo de datos en Node-RED con tus propias credenciales de MQTT.

> [!TIP]
> - Los relés operan con lógica inversa: un LOW activa el relé, mientras que HIGH lo desactiva.
> -  Si necesitas un broker MQTT gratuito, puedes obtenerlo en: [HiveMQ Cloud](https://docs.hivemq.com/hivemq-cloud/quick-start-guide.html).
