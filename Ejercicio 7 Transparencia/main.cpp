#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

// Variables
Texture texture_bcircule;
Sprite sprite_bcircule;
Texture texture_punto_rojo;
Sprite sprite_punto_rojo;

// Punto de entrada a la aplicaci�n
int main() {
    // Cargamos la textura del archivo
    texture_bcircule.loadFromFile("bcircule.png");
    texture_punto_rojo.loadFromFile("rcircle.png");

    // Cargamos el material del sprite
    sprite_bcircule.setTexture(texture_bcircule);
    sprite_punto_rojo.setTexture(texture_punto_rojo);

    // Creamos la ventana
    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Ejercicio 7 transparencia");

    // Loop principal
    while (App.isOpen()) {
        // Limpiamos la ventana
        App.clear();

        // Obtener el tama�o de la ventana
        sf::Vector2u windowSize = App.getSize();

        // Tama�o del sprite
        sf::Vector2u spriteSize = texture_punto_rojo.getSize();

        // Dibujar en la esquina superior izquierda
        sprite_punto_rojo.setPosition(0, 0);
        App.draw(sprite_punto_rojo);

        // Dibujar en la esquina superior derecha
        sprite_punto_rojo.setPosition(windowSize.x - spriteSize.x, 0);
        App.draw(sprite_punto_rojo);

        // Dibujar en la esquina inferior izquierda
        sprite_punto_rojo.setPosition(0, windowSize.y - spriteSize.y);
        App.draw(sprite_punto_rojo);

        // Dibujar en la esquina inferior derecha
        sprite_punto_rojo.setPosition(windowSize.x - spriteSize.x, windowSize.y - spriteSize.y);
        App.draw(sprite_punto_rojo);

        // Calcular la posici�n para centrar el sprite
        float x = (windowSize.x - sprite_bcircule.getGlobalBounds().width) / 2;
        float y = (windowSize.y - sprite_bcircule.getGlobalBounds().height) / 2;

        // Establecer la posici�n del sprite en el centro de la ventana
        sprite_bcircule.setPosition(x, y);

        // Dibujar el sprite
        App.draw(sprite_bcircule);

        // Mostrar la ventana
        App.display();
    }

    return 0;
}