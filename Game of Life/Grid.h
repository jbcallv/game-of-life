#pragma once
#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "Conway.h"

class Grid {
public:

	/*
	holds the grid as a 2D pointer
	*/
	Cell** cellGrid;

	/*
	constructor to make
	a maze grid with n rows and cols
	*/
	Grid(int rows, int cols);

	/*
	class destructor is neccessary to delete cellGrid
	*/
	~Grid();

	/*
	draws all the cells
	*/
	void Draw(sf::RenderWindow& window);

	/*
	generates the cells for the
	*/
	void generateCells();

	/*
	handles mouse input
	*/
	void toggleCell(sf::RenderWindow& window);

	/*
	takes a single step in the generations of GOL
	*/
	void stepOneGeneration();

private:
	// rows and columns in maze
	int rows;
	int cols;

	Conway conway;
};
#endif