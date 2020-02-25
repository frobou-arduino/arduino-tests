#include <Arduino.h>

/* lib a ser instalada:
    http://www.airspayce.com/mikem/arduino/VirtualWire/
*/

#include <VirtualWire.h>

//Programa : Receptor RF com Arduino

int ledData = 4;
String msg = "";

void setup() {
  pinMode(ledData, OUTPUT);
  Serial.begin(9600);
  vw_set_rx_pin(5); // Define o pino 5 do Arduino como entrada
  //de dados do receptor
  vw_setup(2000);             // Bits por segundo
  vw_rx_start();              // Inicializa o receptor
  delay(2000);
}

void loop() {
  uint8_t message[VW_MAX_MESSAGE_LEN];
  uint8_t msgLength = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(message, &msgLength)) // Non-blocking
  {
    for (int i = 0; i < msgLength; i++) {
      msg = msg + char(message[i]);
    }
//    Serial.println(msg);
    if (msg == "liga") {
      digitalWrite(ledData, HIGH);
    } else if (msg == "desliga") {
      digitalWrite(ledData, LOW);
    }
    msg = "";
  }
}