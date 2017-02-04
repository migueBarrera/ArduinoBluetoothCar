#include "notas.h"
#include "ArduinoCar.h"
#include <SoftwareSerial.h>
#define TXD 8
#define RXD A0


SoftwareSerial BTSerial(RXD, TXD); // RX | TX
ArduinoCar * coche = new ArduinoCar();

int contadorCaracteres = 0;
  
char datosRecibidos = '0';
int datosEnviados = '0';
boolean andar = false ,andarPlus = false, giroDr = false , giroIzq = false , intermitenteIzq = false , intermitenteDr = false;


void setup()
{
  //coche->tocarMelodiaEncendido();
	Serial.begin(115200);
	BTSerial.begin(115200);
}

void loop()
{
	// Leia la salida del HC-05 and envie al Monitor Serial del Arduino
	if (BTSerial.available())
	{
		datosRecibidos = BTSerial.read();
    Serial.write(datosRecibidos);
    Serial.println();
	}
 
	if ( datosRecibidos != 0 )
	{   

    //AndarPlus
    if(datosRecibidos == 'p' && andar == false)
    {
        coche->marchaAdelantePlus();
        andar = true;
        Serial.println("andarPlus");
    }

    //Parar
    if(datosRecibidos == 's' && andar == true)
    {
        coche->parar();
        andar = false;
        Serial.println("parar");
    }

    //MarchaAtras
    if(datosRecibidos == 'x' && andar == false)
    {
      coche->marchaAtras();
      andar = true;
      Serial.println("marchaAtras");
    }

    //GiroDerecha
    if(datosRecibidos == 'd' && giroDr == false)
    {
      coche->girarDerecha();
      giroDr = true;
      Serial.println("dre");
    }

    //GiroIzquierda
    if(datosRecibidos == 'a' && giroIzq == false)
    {
      coche->girarIzquierda();
      giroIzq = true;
      Serial.println("izq");
      
    }

    //Parar Giro
    if(giroIzq == true || giroDr == true)
    {
      Serial.println("girando a cualquier lado");
      if(datosRecibidos == 'k')
      {
        Serial.println("paro");
        coche->pararGiro();
        giroIzq = false;
        giroDr = false; 

          if(intermitenteIzq == true)
          {
            Serial.println("imnt");
            coche->apagarIntermitenteIzquierdo();
          }
          if(intermitenteDr == true)
          {
            coche->apagarIntermitenteDerecho();
          }
          
        }
    }

    //IntermitenteDer
    if(datosRecibidos == '6' )
    {
      coche->encenderIntermitenteDerecho();
      intermitenteDr = true;
    }

    //IntermitenteIzq
    if(datosRecibidos ==  '5')
    {
      coche->encenderIntermitenteIzquierdo();
      intermitenteIzq = true;
    }
    

    //Encender Luces
    if(datosRecibidos == '3')
    {
      coche->encenderLucesDelanteras();
    }
    //Encender Luces Plus
    if(datosRecibidos == '7')
    {
      coche->encenderLucesDelanterasPlus();
    }

    //Apagar Luces
    if(datosRecibidos == '4')
    {
      coche->apagarLucesDelanteras();
    }
    if(datosRecibidos == '1')
    {
        coche->tocarBocina();
    }
    if(datosRecibidos == '2')
    {
        coche->pararBocina();
    }
	}

  delay(1);
  datosRecibidos = 0;
	
}

