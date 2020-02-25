#include <Arduino.h>

/* lib a ser instalada:
    http://www.airspayce.com/mikem/arduino/VirtualWire/
*/

//Programa : Módulo RF Transmissor com Arduino

#include <VirtualWire.h>

String mensagem;
char data[40];
int numero;

void send (char *message)
{
  vw_send((uint8_t *)message, strlen(message));
  Serial.print("Enviado: ");
  Serial.println(*message);
  vw_wait_tx(); // Aguarda o envio de dados
}

void setup() {
  Serial.begin(9600);
  //Define o pino 8 do Arduino como
  //o pino de dados do transmissor
  vw_set_tx_pin(8);
  vw_setup(2000);   // Bits per sec
  Serial.println("Digite o texto e clique em ENVIAR...");
}

void loop() {
  if (Serial.available() > 0)
  {
    numero = Serial.readBytesUntil (13, data, 40);
    data[numero] = 0;
    //Envia a mensagem para a rotina que
    //transmite os dados via RF
    send(data);
  }
}
