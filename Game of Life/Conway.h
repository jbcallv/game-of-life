#pragma once
#ifndef CONWAY_H
#define CONWAY_H

#include "Constants.h"
#include "Cell.h"

class Conway {
public:
	/*
	constructor
	*/
	Conway();

	/*
	returns an array of all neighboring cells
	*/
	std::vector<Cell> getAdjacent(Cell** cellGrid, Cell cell);

	/*
	returns alive adjacent cells
	*/
	int getAlive(std::vector<Cell> adjacent);

private:
};
#endif CONWAY_H
