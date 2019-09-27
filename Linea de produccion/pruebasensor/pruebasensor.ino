#include "Stepper.h"

#define STEPS  32   // numero de pasos por revolución
int  Steps2Take;  // 2048 = 1 revolución


const int foto = 0;

int valorLDR = 0;


// Configuración de la secuencia correcta para los pines del controlador del motor
// In1, In2, In3, In4 en la secuencia 1 - 3 - 2 - 4

Stepper small_stepper(STEPS, 8, 10, 9, 11);

void setup() {
 
  Serial.begin(9600);
}

void loop() {
   valorLDR = analogRead(foto);
  Serial.println(valorLDR);

  while (valorLDR >= 620) {
    valorLDR = analogRead(foto);
    Serial.println(valorLDR);

    small_stepper.setSpeed(500);
    Steps2Take  =  200;  // rota en sentido contrario al reloj
    small_stepper.step(Steps2Take);
    
  }

  while (valorLDR < 620) {
    valorLDR = analogRead(foto);
    Serial.println(valorLDR);

    small_stepper.setSpeed(500);
    Steps2Take  =  0;  // rota en sentido contrario al reloj
    small_stepper.step(Steps2Take);

      
  } //se cierra  while 

}
