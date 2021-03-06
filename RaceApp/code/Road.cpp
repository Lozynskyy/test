#include <iostream>
#include "Road.h"
#include "Game.h"

void Road::move(char space[30][50], int xCarCoordinate[], int yCarCoordinate[], int yBorderCoordinate[], const int LENGTH, const int WIDTH)
{
	for(int i = LENGTH-1; i >= 0; i--){
		for(int j = 0; j < WIDTH; ++j){
			if(space[i][j] != '(' && space[i][j] != ')' && space[i][j] != '.' && space[i][j] != '_' && space[i][j] != '|'){
				if(i!=0){
					space[i][j] = space[i-1][j];
				}
				else{
					for(int k = 0; k < 4; ++k){
						space[i][yBorderCoordinate[k]] = '|';
					}
					space[i][j] = ' ';
				}
			}
		}
	}
};
void Road::frontStrike(char space[30][50], int xCarCoordinate[], int yCarCoordinate[])
{
	if(space[xCarCoordinate[0]-1][yCarCoordinate[0]] == '*' || space[xCarCoordinate[0]-1][yCarCoordinate[1]] == '*' || space[xCarCoordinate[0]-1][yCarCoordinate[2]] == '*' || space[xCarCoordinate[0]-1][yCarCoordinate[3]] == '*' || space[xCarCoordinate[0]-1][yCarCoordinate[4]] == '*'){
		Game game;
		game.gameOver();
	}
};
void Road::addRubbish(char space[30][50])
{
	for (int i = 5; i < 44; i++){
		if (rand() % 100 == 1)
			space[0][i] = '*';
	}
};
int Road::getSpeed()
{
	Game game;
	return speed = 10000 / game.getDelay();
};
void Road::draw(char space[30][50], int xCarCoordinate[], int yCarCoordinate[], int yBorderCoordinate[], const int LENGTH, const int WIDTH)
{
	for(int i = 0; i < LENGTH; ++i){
		for(int j = 0; j < WIDTH; ++j){
			space[i][j] = ' ';
		}
		for(int k = 0; k < 4; ++k){
			space[i][yBorderCoordinate[k]] = '|';
		}
	}
	space[xCarCoordinate[0]][yCarCoordinate[0]] = '(';
	space[xCarCoordinate[0]][yCarCoordinate[1]] = ')';
	space[xCarCoordinate[0]][yCarCoordinate[2]] = '_';
	space[xCarCoordinate[0]][yCarCoordinate[3]] = '(';
	space[xCarCoordinate[0]][yCarCoordinate[4]] = ')';
	space[xCarCoordinate[1]][yCarCoordinate[0]] = '.';
	space[xCarCoordinate[1]][yCarCoordinate[1]] = '|';
	space[xCarCoordinate[1]][yCarCoordinate[2]] = '|';
	space[xCarCoordinate[1]][yCarCoordinate[3]] = '|';
	space[xCarCoordinate[1]][yCarCoordinate[4]] = '.';
	space[xCarCoordinate[2]][yCarCoordinate[0]] = '.';
	space[xCarCoordinate[2]][yCarCoordinate[1]] = '|';
	space[xCarCoordinate[2]][yCarCoordinate[2]] = '_';
	space[xCarCoordinate[2]][yCarCoordinate[3]] = '|';
	space[xCarCoordinate[2]][yCarCoordinate[4]] = '.';
	space[xCarCoordinate[3]][yCarCoordinate[0]] = '(';
	space[xCarCoordinate[3]][yCarCoordinate[1]] = ')';
	space[xCarCoordinate[3]][yCarCoordinate[2]] = ' ';
	space[xCarCoordinate[3]][yCarCoordinate[3]] = '(';
	space[xCarCoordinate[3]][yCarCoordinate[4]] = ')';
}