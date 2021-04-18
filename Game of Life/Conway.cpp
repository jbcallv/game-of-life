#include "Conway.h"

Conway::Conway() {
	// nuhin yet
}

std::vector<Cell> Conway::getAdjacent(Cell** mazeGrid, Cell cell) {
	// each cell has 4 neighbors
	std::vector<Cell> adjacent;

	// only push back cells that exist
	if (cell.getPosX() < WIDTH) adjacent.push_back(mazeGrid[cell.getPosX() + 1][cell.getPosY()]);
	if (cell.getPosX() > 0) adjacent.push_back(mazeGrid[cell.getPosX() - 1][cell.getPosY()]);
	if (cell.getPosY() < HEIGHT) adjacent.push_back(mazeGrid[cell.getPosX()][cell.getPosY() + 1]);
	if (cell.getPosY() > 0) adjacent.push_back(mazeGrid[cell.getPosX()][cell.getPosY() - 1]);
	return adjacent;
}

std::vector<Cell> Conway::getAlive(std::vector<Cell> adjacent) {
	std::vector<Cell> alive;
	for (int i = 0; i < adjacent.size(); ++i) {
		if (adjacent.at(i).alive) {
			alive.push_back(adjacent.at(i));
		}
	}
	return alive;
}