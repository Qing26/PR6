//SuperLanchasJuego Un juego sobre super lanchas haciendo carreras 

#include <iostream>
#include "Lanchas.h"
#include <cstdlib>
#include <time.h>


using namespace std;

//Funcion lanzar dado y calcular velocidad
int calcVelocidad() {
    int dado = rand() % 6;
    return dado;
}
int usarNitro(int velocidad) {
    int velFinal = 0;
    int dado = rand() % 2;
    if (dado == 0) {
        velFinal = velocidad / 2;
    }
    else {
        velFinal = velocidad * 2;
    }
    return velFinal;
 }

int calDistancia(int distancia, int velocidad) {
    distancia = distancia + velocidad * 100;
    return distancia;
}

int main() {
    //Reiniciar num aleatorio
    srand(time(0));
    //Objeto de la ventada
    sf::RenderWindow window(sf::VideoMode(900, 600), "Lanchas de Carrera");
    window.setFramerateLimit(30);

    //Sprite background
    sf::Texture texture0;
    if (!texture0.loadFromFile("Imagenes/background_day.png")) {
        cout << "Error loading texture from file";
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(texture0);
    backgroundSprite.setScale(2.0f, 2.0f);

    //Sprite lancha 1
    sf::Texture texture1;
    if (!texture1.loadFromFile("Imagenes/Img_lancha.png")) {
        cout << "Error loading texture from file";
    }
    sf::Sprite lanchaSprite1;
    lanchaSprite1.setTexture(texture1);
    Lancha  lancha1(0, 0, 1, "Sentinel I"); //Propiedades de la lancha1
    //Posicion de lancha 1
    lanchaSprite1.setPosition(10, 170);
    lanchaSprite1.setScale(0.2f,0.2f);
    //Movimiento de lancha 1
    int lancha1X = 0; //El eje X sera la "velocidad"  del barco
    int lancha1Y = 0; 
    lanchaSprite1.move(lancha1X,lancha1Y);
    
    //Sprite lancha 2
    sf::Texture texture2;
    if (!texture2.loadFromFile("Imagenes/Img_lancha2.png")) {
        cout << "Error loading texture from file";
    }
    sf::Sprite lanchaSprite2;
    lanchaSprite2.setTexture(texture2);
    Lancha  lancha2(0, 0, 1, "Sentinel II"); //Propiedades de la lancha1
    //Posicion de lancha 2
    lanchaSprite2.setPosition(10,320);
    lanchaSprite2.setScale(0.2f, 0.2f);    

    //Variables
    int count = 0;
    int totalVelocidad1 = 0;

    // Configuracion vista de la lancha 1
    sf::View view(sf::FloatRect(0.f, 0.f, 800.f, 600.f));
    window.setView(view);

    //Ventana del SFML
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::E) {
                    int velocidadLancha1 = calcVelocidad();
                    cout << "Velocidad obtenida: " << velocidadLancha1 << endl;
                    totalVelocidad1 += velocidadLancha1;
                    lancha1.setVelocidad(totalVelocidad1);
                    count++;
                    if (count == 5) {
                        //lancha1X += totalVelocidad1;
                        count = 0;
                        //totalVelocidad1 = 0;
                        cout << lancha1.getNomCorredor()<< endl;
                        cout << "Total velocidad acumulada: " << lancha1.getVelocidad() << endl;
                        cout << "Pulsa el boton R si quieres utilizar nitro" << endl;
                        cout << "Pulsa el boton Q si quieres ver la velocidad final" << endl;
                    }
                }
                if (event.key.code == sf::Keyboard::R) {
                    cout << "Has utilizado la nitro!" << endl;
                    if (lancha1.getNitro() == 0) {
                        cout << "Se intento utilizar nitro, pero no hay!" << endl;
                        cout << "Tu velocidad final es: " << lancha1.getVelocidad() << endl;
                        lancha1X = lancha1.getVelocidad();
                    }
                    else {
                        lancha1X = usarNitro(totalVelocidad1);
                        cout << "Tu velocidad final es: " << lancha1X << endl;
                        lancha1.setNitro(0);
                    }
                    
                }
                if (event.key.code == sf::Keyboard::Q) {
                    cout << "Tu velocidad final es: " << lancha1.getVelocidad() << endl;
                    lancha1X = lancha1.getVelocidad();
                }
            }
            
        }


        // Actualiza la posicion de la lancha 1
        lanchaSprite1.setPosition(lancha1X, lancha1Y);

        // Actualiza la posicion de la lancha 2


        window.clear();
        window.draw(backgroundSprite);
        window.draw(lanchaSprite1); //Dibuja lancha1
        window.draw(lanchaSprite2); //Dibuja lancha2
        //lanchaSprite1.move(lancha1X, lancha1Y); //La lancha va para delante
        window.display();
    }

    return 0;
}

