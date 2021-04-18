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
		 
		// draw line on bottom and right of screen
		sf::RectangleShape btm = sf::RectangleShape(sf::Vector2f(WIDTH, WALL_WIDTH));
		btm.setFillColor(WALL_COLOR);
		btm.setPosition(0, HEIGHT - WALL_WIDTH);
		window.draw(btm);

		// right
		sf::RectangleShape right = sf::RectangleShape(sf::Vector2f(WALL_WIDTH, HEIGHT));
		right.setFillColor(WALL_COLOR);
		right.setPosition(WIDTH - WALL_WIDTH, 0);
		window.draw(right);
	}
}

void Grid::generateCells() {
	for (int i = 0; i < cols * rows; ++i) {
		int x = i / rows;
		int y = i % rows;
		cellGrid[x][y] = Cell(x, y);
	}
}

void Grid::toggleCell(sf::RenderWindow& window) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	// get row and col for cell
	int x = (int) mousePos.x / CELL_WIDTH;
	int y = (int) mousePos.y / CELL_HEIGHT;

	cellGrid[x][y].alive = !cellGrid[x][y].alive;
}

void Grid::stepOneGeneration() {

}
