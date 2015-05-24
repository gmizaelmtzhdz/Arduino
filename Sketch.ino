/*
*  Sketch.ino
*
*  Created on: 24/05/2015
*  Author: Mizael Martinez
*/
#include "SIM900.h"
#include <SoftwareSerial.h>
#include "sms.h"
#include "inetGSM.h"
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <Bmp_180_T.h>
#include <TinyGPS.h>
#include <_Transportadora_Gps.h>
#include <Gprs_T.h>
#include <Coordenadas_T.h>
#include <Json_T.h>

#define INICIO 0
#define REPORTAR 1
#define FINALIZAR 2

#define ENCENDIDO 23
#define ESTABILIZADO 48
#define SERVIDOR 50
#define DISPONIBLE 52

Transportadora t;
Gprs_T gprs;
Json json;
Coordenadas cordenadas;

char peticion_[300];
char parametros[180];
char parametros_respaldo[180];
int contador=0;

void setup()
{
  pinMode(ENCENDIDO,OUTPUT);
  pinMode(ESTABILIZADO,OUTPUT);
  pinMode(SERVIDOR,OUTPUT);
  pinMode(DISPONIBLE,OUTPUT);  

  digitalWrite(ENCENDIDO,HIGH);
  Serial.begin(57600);
  Serial.println(F("Iniciando transportadora..."));     
  t.establecerIdContenedor(1);
  t.establecerPinRxGps(10);
  t.establecerPinTxGps(11);
  t.iniciarTransportadora();
  t.establecerParametros(parametros,INICIO);
  t.establecerParametros(parametros_respaldo,INICIO);
  digitalWrite(SERVIDOR,HIGH);
  t.realizarPeticionHttp(peticion_,parametros,parametros_respaldo);
  digitalWrite(SERVIDOR,LOW);  
  json.ctrlConvertir(peticion_,&t);
  t.obtenerEstadoDeContenedor();
  t.verificarParametrosActualesYParametrosEstablecidos();
  digitalWrite(ESTABILIZADO,HIGH);
}
void loop()
{
    double distancia=0.0;
    distancia=cordenadas.obtenerDistanciaEntreDosPuntos(t.obtenerLatitudFinal(),t.obtenerLongitudFinal(),t.obtenerLatitudActual(),t.obtenerLongitudActual());
    if(!t.obtenerActivado())
    {
      digitalWrite(DISPONIBLE,LOW);
      t.establecerParametros(parametros,INICIO);
      Serial.println(F("===== NO HAY RECORRIDO DISPONIBLE...====="));
    }
    else
    {
      digitalWrite(DISPONIBLE,HIGH);
      if(distancia <=35.0)
      {
          Serial.println(F("FIALIZANDO RECORRIDO..."));
          t.establecerParametros(parametros,FINALIZAR); 
      }
      else
      {
          t.establecerParametros(parametros,REPORTAR);
      }
    }
    digitalWrite(SERVIDOR,HIGH);
    t.realizarPeticionHttp(peticion_,parametros,parametros_respaldo);
    digitalWrite(SERVIDOR,LOW);
    json.ctrlConvertir(peticion_,&t);
    t.obtenerEstadoDeContenedor();
    t.verificarParametrosActualesYParametrosEstablecidos();
}
