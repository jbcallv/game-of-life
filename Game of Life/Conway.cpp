#include "Conway.h"

Conway::Conway() {
	// nuhin yet
}

std::vector<Cell> Conway::getAdjacent(Cell** cellGrid, Cell cell) {
	// each cell has 8 neighbors
	std::vector<Cell> adjacent;

	// only push back cells that exist in the matrix
	if (cell.getPosX() < WIDTH / CELL_WIDTH - 1) adjacent.push_back(cellGrid[cell.getPosX() + 1][cell.getPosY()]);
	if (cell.getPosX() > 0) adjacent.push_back(cellGrid[cell.getPosX() - 1][cell.getPosY()]);
	if (cell.getPosY() < HEIGHT / CELL_HEIGHT - 1) adjacent.push_back(cellGrid[cell.getPosX()][cell.getPosY() + 1]);
	if (cell.getPosY() > 0) adjacent.push_back(cellGrid[cell.getPosX()][cell.getPosY() - 1]);

	if (cell.getPosX() < WIDTH / CELL_WIDTH - 1 && cell.getPosY() < HEIGHT / CELL_HEIGHT - 1) adjacent.push_back(cellGrid[cell.getPosX() + 1][cell.getPosY() + 1]);
	if (cell.getPosX() < WIDTH / CELL_WIDTH - 1 && cell.getPosY() > 0) adjacent.push_back(cellGrid[cell.getPosX() + 1][cell.getPosY() - 1]);
	if (cell.getPosX() > 0 && cell.getPosY() < HEIGHT / CELL_HEIGHT - 1) adjacent.push_back(cellGrid[cell.getPosX() - 1][cell.getPosY() + 1]);
	if (cell.getPosX() > 0 && cell.getPosY() > 0) adjacent.push_back(cellGrid[cell.getPosX() - 1][cell.getPosY() - 1]);

	return adjacent;
}

int Conway::getAlive(std::vector<Cell> adjacent) {
	int j = 0;
	for (int i = 0; i < adjacent.size(); ++i) {
		if (adjacent.at(i).alive) {
			j++;
		}
	}
	return j;
}