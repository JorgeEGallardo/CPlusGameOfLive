#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;
const int w = 50;
class cell {
public:
	int state;
	int x;
	int y;
	int livestem;
	int getState() {
		return state;
	}
	void init(int i, int j) {
		state = rand() % 2;
		x = i;
		y = j;
	}
	int dead(cell cells[w][w]) {
		if (count(cells) == 3) {

			return 1;

		}
		return state;
	}
	int alive(cell cells[w][w]) {
		if (!(count(cells) == 3 or count(cells) == 2)) {

			return 0;
		}
		return state;
	}
	int count(cell cells[w][w]) {
		int lives = 0;
		int xtemp = x - 1;
		int ytemp = y - 1;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (!((i == 1 && j == 1) || (xtemp + i >= w || ytemp + j >= w)
						|| (xtemp + i < 0 || ytemp + j < 0))) {
					if (cells[xtemp + i][ytemp + j].getState() == 1) {
						lives++;
					}
				}

			}
		}
		return lives;
	}
	int setState(cell cells[w][w]) {
		if (state)
			return alive(cells);
		else
			return dead(cells);
	}
	void forceState(int st) {
		state = st;
	}
};
class board {
public:
	cell cells[w][w];
	cell newCells[w][w];

	void Initgame() {
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < w; j++) {
				cells[i][j].init(i, j);
				cout << "[" << cells[i][j].getState() << "]";
			}
			cout << endl;
		}
		cout << endl;

	}
	void turn() {
		memcpy(newCells, cells, sizeof(newCells));

		for (int i = 0; i < w; i++) {
			for (int j = 0; j < w; j++) {
				newCells[i][j].forceState(cells[i][j].setState(cells));
				if (newCells[i][j].getState())
					cout << char(207);
				else
					cout << char(254);
			}

			cout << endl;
		}

		memcpy(cells, newCells, sizeof(cells));
	}
};
int main() {
	board board;
	board.Initgame();
	int i = 0, sle;
	cin >> sle;
	while (true) {
		board.turn();
		cout << endl;
		Sleep(sle);
		cout << "<" << i << ">" << endl;
		i++;
	}
}
