/*
 * Transportadora.cpp
 *
 *  Created on: 22/02/2015
 *      Author: Mizael Martinez
 */
#include<iostream>
using namespace std;
class Transportadora{
	private:
		//Atributos configuracion
		int id_contenedor;
		double temperatura_min;
		double temperatura_max;
		double humedad_min;
		double humedad_max;
		double latitud_inicio;
		double longitud_inicio;
		double latitud_final;
		double longitud_final;
		int telefonos[];
		//Pines
		int pinTemperaturaHumedad;
		int pinPresionAltitud;
	public:
		Transportadora(int id_contenedor)
		{
			this->establecerIdContenedor(id_contenedor);
		}
		void establecerIdContenedor(int id_contenedor);
		void establecerTemperaturaMin(double temperatura_min);
		void establecerTemperaturaMax(double temperatura_max);
		void establecerHumedadMin(double humedad_min);
		void establecerHumedadMax(double humedad_max);
		void establecerLatitudInicio(double latitud_inicio);
		void establecerLongitudInicio(double longitud_inicio);
		void establecerLatitudFinal(double latitud_final);
		void establecerLongitudFinal(double longitud_final);
		void establecerTelefonos(int telefonos[]);

};

void Transportadora::establecerIdContenedor(int id_contenedor)
{
	this->id_contenedor=id_contenedor;
}
void Transportadora::establecerTemperaturaMin(double temperatura_min)
{
	this->temperatura_min=temperatura_min;
}
void Transportadora::establecerTemperaturaMax(double temperatura_max)
{
	this->temperatura_max=temperatura_max;
}
void Transportadora::establecerHumedadMin(double humedad_min)
{
	this->humedad_min=humedad_min;
}
void Transportadora::establecerHumedadMax(double humedad_max)
{
	this->humedad_max=humedad_max;
}
void Transportadora::establecerLatitudInicio(double latitud_inicio)
{
	this->latitud_inicio=latitud_inicio;
}
void Transportadora::establecerLongitudInicio(double longitud_inicio)
{
	this->longitud_inicio=longitud_inicio;
}
void Transportadora::establecerLatitudFinal(double latitud_final)
{
	this->latitud_final=latitud_final;
}
void Transportadora::establecerLongitudFinal(double longitud_final)
{
	this->longitud_final=longitud_final;
}
void Transportadora::establecerTelefonos(int telefonos[])
{

}
int main(int argc,char *argv[])
{

}


