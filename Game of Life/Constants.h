#pragma once
#ifndef CONSTANTS_H
#define CONSTANTS_H

/*
window stuff
*/
const int HEIGHT = 600;
const int WIDTH = 1000;

/*
cell stuff
*/
const int CELL_HEIGHT = 10;
const int CELL_WIDTH = 10;
const int WALL_WIDTH = 2;

/*
color stuff
*/
const sf::Color DEAD = sf::Color(0, 0, 0, 255);
const sf::Color ALIVE = sf::Color(255, 255, 255, 255);
const sf::Color WALL_COLOR = sf::Color(0, 0, 255, 255);
#endif
