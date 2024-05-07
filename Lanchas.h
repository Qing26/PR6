#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace std;

class Lancha {
	private:
		int velocidad;
		int distancia;
		int nitro;

		string nomCorredor;
		sf::Sprite sprite;
		sf::Texture texture;
	public:
		int getVelocidad();
		void setVelocidad(int pVelocidad);

		int getDistancia();
		void setDistancia(int pDistancia);

		int getNitro();
		void setNitro(int pNitro);

		string getNomCorredor();
		void setNomCorredor(string pNomCorredor);

		void getParams();

		//Constructor
		Lancha(int pVelocidad, int pDistancia, int pNitro, string pNomCorredor);

};

