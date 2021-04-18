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
	Cell* getAdjacent();

	/*
	returns alive adjacent cells
	*/
	Cell* getAlive();

private:
};
#endif CONWAY_H
