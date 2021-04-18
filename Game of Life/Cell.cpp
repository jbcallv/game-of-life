#include "Cell.h"

Cell::Cell() {
	// default
}

Cell::Cell(int x, int y) {
	this->x = x;
	this->y = y;
	// change this field as neccessary
	this->alive = false;
	this->cellRect = sf::RectangleShape(sf::Vector2f(CELL_WIDTH - WALL_WIDTH, CELL_HEIGHT - WALL_WIDTH));
	this->cellRect.setFillColor(DEAD);
	this->cellRect.setPosition(sf::Vector2f(x * CELL_WIDTH + WALL_WIDTH, y * CELL_HEIGHT + WALL_WIDTH));

	this->generateWalls();
}

void Cell::generateWalls() {
	// cell has both a top and left wall
	topWall = sf::RectangleShape(sf::Vector2f(CELL_WIDTH, WALL_WIDTH));
	topWall.setFillColor(WALL_COLOR);
	topWall.setPosition(sf::Vector2f(x * CELL_WIDTH, y * CELL_HEIGHT));

	leftWall = sf::RectangleShape(sf::Vector2f(WALL_WIDTH, CELL_HEIGHT));
	leftWall.setFillColor(WALL_COLOR);
	leftWall.setPosition(sf::Vector2f(x * CELL_WIDTH, y * CELL_HEIGHT));
}

int Cell::getPosX() {
	return this->x;
}

int Cell::getPosY() {
	return this->y;
}
