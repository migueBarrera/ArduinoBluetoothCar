#include "ArduinoCar.h"
#include <SoftwareSerial.h>
#include "notas.h"
#define PWM_A_Pin 5                              // PWM se conecta al pin 1 del puente-H
#define Motor_A_Pin1 7                         // Entrada 2 del puente-H 
#define Motor_A_Pin2 8                          // Entrada 7 del puente-H 

#define PWM_B_Pin 6                               // PWM se conecta al pin 1 del puente-H
#define Motor_B_Pin1 9                          // Entrada 2 del puente-H 
#define Motor_B_Pin2 10                        // Entrada 7 del puente-H 


// default constructor
ArduinoCar::ArduinoCar()
{
	pinMode(Motor_A_Pin1, OUTPUT);                     //Configura Motor_A_Pin1 como salida 
    pinMode(Motor_A_Pin2, OUTPUT);                     //Configura Motor_A_Pin2 como salida 
	pinMode(Motor_B_Pin1, OUTPUT);                     //Configura Motor_A_Pin1 como salida 
    pinMode(Motor_B_Pin2, OUTPUT);                     //Configura Motor_A_Pin2 como salida 
} //ArduinoCar

// default destructor
ArduinoCar::~ArduinoCar()
{
	
} //~ArduinoCar

void ArduinoCar::marchaAdelante()
{
	analogWrite(PWM_A_Pin, 127);
    digitalWrite(Motor_A_Pin1,LOW);
    digitalWrite(Motor_A_Pin2,HIGH);     
}

void ArduinoCar::marchaAdelantePlus()
{
  	analogWrite(PWM_A_Pin, 255);
    digitalWrite(Motor_A_Pin1,LOW);
    digitalWrite(Motor_A_Pin2,HIGH); 
}

void ArduinoCar::marchaAtras()
{
	analogWrite(PWM_A_Pin, 255);
    digitalWrite(Motor_A_Pin1,HIGH);
    digitalWrite(Motor_A_Pin2,LOW);
}

void ArduinoCar::girarDerecha()
{
    analogWrite(PWM_B_Pin, 255);
    digitalWrite(Motor_B_Pin1,LOW);
    digitalWrite(Motor_B_Pin2,HIGH);  
}

void ArduinoCar::girarIzquierda()
{
	analogWrite(PWM_B_Pin, 255);
    digitalWrite(Motor_B_Pin1,HIGH);
    digitalWrite(Motor_B_Pin2,LOW);  
}

void ArduinoCar::pararGiro()
{
    digitalWrite(Motor_B_Pin1,LOW);
    digitalWrite(Motor_B_Pin2,LOW);
}

void ArduinoCar::parar()
{
	digitalWrite(Motor_A_Pin1,LOW);
    digitalWrite(Motor_A_Pin2,LOW);
}

void ArduinoCar::tocarBocina()
{
	
}

void ArduinoCar::pararBocina()
{
  
}
void ArduinoCar::encenderIntermitenteIzquierdo()
{
	
}

void ArduinoCar:: apagarIntermitenteIzquierdo()
{
  
}

void ArduinoCar::encenderIntermitenteDerecho()
{
	
}

void ArduinoCar::apagarIntermitenteDerecho()
{
  
}

void ArduinoCar::apagarLucesDelanteras()
{
  
}
void ArduinoCar::encenderLucesDelanteras()
{
	
}
