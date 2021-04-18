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
	for (int i = 0; i < cols; ++i) {
		for (int j = 0; j < rows; ++j) {
			if (cellGrid[i][j].alive == true) {
				cellGrid[i][j].cellRect.setFillColor(ALIVE);
			}
			else {
				cellGrid[i][j].cellRect.setFillColor(DEAD);
			}
			window.draw(cellGrid[i][j].cellRect);
			window.draw(cellGrid[i][j].leftWall);
			window.draw(cellGrid[i][j].topWall);
		}
	}
}

void Grid::generateCells() {
	for (int i = 0; i < cols; ++i) {
		for (int j = 0; j < rows; ++j) {
			cellGrid[i][j] = Cell(i, j);
		}
	}
}