#include "Lanchas.h"

//Velocidad
int Lancha::getVelocidad()
{
	return velocidad;
}

void Lancha::setVelocidad(int pVelocidad)
{
	velocidad = pVelocidad;
}

//Distancia
int Lancha::getDistancia()
{
	return distancia;
}

void Lancha::setDistancia(int pDistancia)
{
	distancia = pDistancia;
}

//Nitro
int Lancha::getNitro()
{
	return nitro;
}

void Lancha::setNitro(int pNitro)
{
	nitro = pNitro;
}

//Nombre
string Lancha::getNomCorredor()
{
	return nomCorredor;
}

void Lancha::setNomCorredor(string pNomCorredor)
{
	nomCorredor = pNomCorredor;
}

//Devolver parametros
void Lancha::getParams()
{
	cout << "Nombre: " << nomCorredor << "Velocidad: " << velocidad << "Distancia: " << distancia << "Nitro: " << nitro << "\n";
}

//Constructor
Lancha::Lancha(int pVelocidad, int pDistancia, int pNitro, string pNomCorredor)
{
	velocidad = pVelocidad;
	distancia = pDistancia;
	nitro = pNitro;
	nomCorredor = pNomCorredor;
}
