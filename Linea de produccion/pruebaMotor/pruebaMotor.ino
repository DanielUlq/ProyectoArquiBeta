/*librerias*/
#include "Stepper.h"


/*----- Variables, Pins -----*/
#define STEPS  32   // numero de pasos por revolución
int  Steps2Take;  // 2048 = 1 revolución

const int foto = 0;
int valorLDR = 0;

const int fotoContar = 1;
int valorLDRContar = 0;
int val = 0;


/*-----( Declare objects )-----*/
// Configuración de la secuencia correcta para los pines del controlador del motor
// In1, In2, In3, In4 en la secuencia 1 - 3 - 2 - 4

Stepper small_stepper(STEPS, 8, 10, 9, 11);


void setup()
{
  Serial.begin(9600);
}

void loop()
{
  valorLDR = analogRead(foto);
  Serial.println(valorLDR);

  while (valorLDR < 620) {
    valorLDR = analogRead(foto);
    Serial.println(valorLDR);

    small_stepper.setSpeed(500);
    Steps2Take  =  -200;  // rota en sentido contrario al reloj
    small_stepper.step(Steps2Take);
    val = 0;
  }


  while (valorLDR >= 620 && val < 5) {
    valorLDR = analogRead(foto);
    //Serial.println(valorLDR);

    small_stepper.setSpeed(500);
    Steps2Take  =  0;  // rota en sentido contrario al reloj
    small_stepper.step(Steps2Take);

      valorLDRContar = analogRead(fotoContar);
      Serial.println(valorLDRContar);

      if (valorLDRContar >= 620) {
        val++;
        delay(2000);
      }//cierre de if
      
      Serial.println(val);
  } //se cierra primer while de LDR

  while (valorLDR >=620 && val == 5) {  //para salir de la sombra de la caja
    valorLDR = analogRead(foto);
    Serial.println(valorLDR);

    small_stepper.setSpeed(500);
    Steps2Take  =  -200;  // rota en sentido contrario al reloj
    small_stepper.step(Steps2Take);  
  }


}
