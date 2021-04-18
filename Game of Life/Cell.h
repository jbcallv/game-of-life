#pragma once
#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>
#include "Constants.h"

class Cell {
public:

	/*
	holds wheter the cell
	has been visited
	*/
	bool alive;

	/*
	default constructor for the curCell
	in Grid.cpp
	*/
	Cell();

	/*
	constructor to make a cell
	at row x and column y, with a wall on side
	walls
	*/
	Cell(int x, int y);

	/*
	sets the cell walls depending on parameter
	*/
	void generateWalls();

	/*
	getter for x
	*/
	int getPosX();

	/*
	getter for y
	*/
	int getPosY();

	/*
	the cell rectangle
	*/
	sf::RectangleShape cellRect;

	// walls for each cell
	sf::RectangleShape topWall;
	sf::RectangleShape leftWall;

private:
	// row and column
	int x;
	int y;
};
#endif
