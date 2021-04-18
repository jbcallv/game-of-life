#include "Grid.h"

Grid::Grid(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;

	// make this entire class more efficient by using a 1D array instead
	this->cellGrid = new Cell* [cols];
	for (int i = 0; i < cols; ++i) {
		this->cellGrid[i] = new Cell[rows];
	}
}

Grid::~Grid() {
	for (int i = 0; i < cols; ++i) {
		delete cellGrid[i];
	}
	delete cellGrid;
}

void Grid::Draw(sf::RenderWindow& window) {
	for (int i = 0; i < cols * rows; ++i) {
		// to avoid a double iterator
		int x = i / rows;
		int y = i % rows;

		if (cellGrid[x][y].alive == true) {
			cellGrid[x][y].cellRect.setFillColor(ALIVE);
		}
		else {
			cellGrid[x][y].cellRect.setFillColor(DEAD);
		}
		window.draw(cellGrid[x][y].cellRect);
		window.draw(cellGrid[x][y].leftWall);
		window.draw(cellGrid[x][y].topWall);
	}
}

void Grid::generateCells() {
	for (int i = 0; i < cols * rows; ++i) {
		int x = i / rows;
		int y = i % rows;
		cellGrid[x][y] = Cell(x, y);
	}
}