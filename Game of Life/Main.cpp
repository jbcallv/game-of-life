#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Grid.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Game of Life", sf::Style::Titlebar | sf::Style::Close);
    Grid *grid = new Grid((int) HEIGHT / CELL_HEIGHT, (int) WIDTH / CELL_WIDTH);
    grid->generateCells();
    bool ready = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    grid->toggleCell(window);
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    ready = true;
                    //grid->stepOneGeneration();
                }
            }
        }

        window.clear(sf::Color::White);
        grid->Draw(window);
        if (ready) {
            grid->stepOneGeneration();
        }
        //grid->stepOneGeneration();
        window.display();
    }

    return 0;
}