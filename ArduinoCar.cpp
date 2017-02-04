#include "ArduinoCar.h"
#include <SoftwareSerial.h>
#include "notas.h"
#define PWM_A_Pin 3                              // PWM se conecta al pin 1 del puente-H
#define Motor_A_Pin1 2                         // Entrada 2 del puente-H 
#define Motor_A_Pin2 4                          // Entrada 7 del puente-H 

#define PWM_B_Pin 5                               // PWM se conecta al pin 1 del puente-H
#define Motor_B_Pin1 A1                          // Entrada 2 del puente-H 
#define Motor_B_Pin2 7                        // Entrada 7 del puente-H 
#define Intermitente_Izq_Del 13
#define Intermitente_Izq_Tra A3
#define Intermitente_Der_Del 10
#define Intermitente_Der_Tra 12
#define Luz_Frontal_1 9
#define Luz_Frontal_2 6
#define SPEAKER 11

// default constructor
ArduinoCar::ArduinoCar()
{
	  pinMode(Motor_A_Pin1, OUTPUT);                     //Configura Motor_A_Pin1 como salida 
    pinMode(Motor_A_Pin2, OUTPUT);                     //Configura Motor_A_Pin2 como salida 
	  pinMode(Motor_B_Pin1, OUTPUT);                     //Configura Motor_A_Pin1 como salida 
    pinMode(Motor_B_Pin2, OUTPUT);                     //Configura Motor_A_Pin2 como salidaç
    pinMode(PWM_A_Pin, OUTPUT);                     //Configura Motor_A_Pin2 como salida
    pinMode(PWM_B_Pin, OUTPUT);                     //Configura Motor_A_Pin2 como salida   
    
    pinMode(Intermitente_Izq_Tra, OUTPUT); 
    pinMode(Intermitente_Izq_Del, OUTPUT);
    pinMode(Intermitente_Der_Tra, OUTPUT);
    pinMode(Intermitente_Der_Del, OUTPUT); 

    pinMode(Luz_Frontal_1, OUTPUT);
    pinMode(Luz_Frontal_2, OUTPUT);
    
   pinMode(SPEAKER, OUTPUT);  

} //ArduinoCar

// default destructor
ArduinoCar::~ArduinoCar()
{
	
} //~ArduinoCar

void ArduinoCar::marchaAdelante()
{
    analogWrite(PWM_B_Pin, 127);
    digitalWrite(Motor_B_Pin1,HIGH);
    digitalWrite(Motor_B_Pin2,LOW);   
}

void ArduinoCar::marchaAdelantePlus()
{
    analogWrite(PWM_B_Pin, 255);
    digitalWrite(Motor_B_Pin1,HIGH);
    digitalWrite(Motor_B_Pin2,LOW); 
}

void ArduinoCar::marchaAtras()
{
    analogWrite(PWM_B_Pin, 255);
    digitalWrite(Motor_B_Pin1,LOW);
    digitalWrite(Motor_B_Pin2,HIGH); 
}

void ArduinoCar::girarDerecha()
{
    analogWrite(PWM_A_Pin, 255);
    digitalWrite(Motor_A_Pin1,HIGH);
    digitalWrite(Motor_A_Pin2,LOW);   
}

void ArduinoCar::girarIzquierda()
{
    analogWrite(PWM_A_Pin, 255);
    digitalWrite(Motor_A_Pin1,LOW);
    digitalWrite(Motor_A_Pin2,HIGH);  
}

void ArduinoCar::pararGiro()
{
    digitalWrite(Motor_A_Pin1,LOW);
    digitalWrite(Motor_A_Pin2,LOW);
}

void ArduinoCar::parar()
{
	  digitalWrite(Motor_B_Pin1,LOW);
    digitalWrite(Motor_B_Pin2,LOW);
}

void ArduinoCar::tocarBocina()
{
  tone(SPEAKER, NOTE_C4);
}

void ArduinoCar::pararBocina()
{
   noTone(SPEAKER);
}
void ArduinoCar::encenderIntermitenteIzquierdo()
{
	digitalWrite(Intermitente_Izq_Del,HIGH);
  digitalWrite(Intermitente_Izq_Tra,HIGH);
}

void ArduinoCar:: apagarIntermitenteIzquierdo()
{
  digitalWrite(Intermitente_Izq_Del,LOW);
  digitalWrite(Intermitente_Izq_Tra, LOW);
}

void ArduinoCar::encenderIntermitenteDerecho()
{
  digitalWrite(Intermitente_Der_Del,HIGH);
  digitalWrite(Intermitente_Der_Tra,HIGH);
}

void ArduinoCar::apagarIntermitenteDerecho()
{
  digitalWrite(Intermitente_Der_Del,LOW);
  digitalWrite(Intermitente_Der_Tra,LOW);
}

void ArduinoCar::apagarLucesDelanteras()
{
  analogWrite(Luz_Frontal_1,0);
  analogWrite(Luz_Frontal_2,0);
}
void ArduinoCar::encenderLucesDelanteras()
{
	analogWrite(Luz_Frontal_1,75);
  analogWrite(Luz_Frontal_2,150);
  Serial.println("luz");
}
void ArduinoCar::encenderLucesDelanterasPlus()
{
  Serial.println("luz plus");
  analogWrite(Luz_Frontal_1,255);
  analogWrite(Luz_Frontal_2,255);
}

void ArduinoCar::tocarMelodiaEncendido()
{
  // notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };

  for (int thisNote = 0; thisNote < 8; thisNote++)
  {
    int noteDuration = 1000/noteDurations[thisNote];
    tone(SPEAKER, melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(SPEAKER);
  }
}
