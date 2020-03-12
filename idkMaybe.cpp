#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <cmath>
#include <bits/stdc++.h> 
#include <vector>
#include <limits.h>

using namespace std;

int cost = 0;

int min(int c, int numCities, int *matrix[], int completed[]) {
	int i, nc = 1000000;
	int min = 1000000, kmin;
	for (int i = 0; i < numCities; i++) {
		if ((matrix[c][i] != 0) && completed[i] == 0) {
			if (matrix[c][i] + matrix[i][c] < min) {
				min = matrix[i][0] + matrix[c][i];
				kmin = matrix[c][i];
				nc = i;
			}
		}
	}
	if (min != 1000000) {
		cost += kmin;
	}
	return nc;
}
  
void tsp(int city, int *matrix[], int completed[], int numCities) {
	int i, ncity;
	completed[city] = 1;
	//cout << city +1 << "---->";
	ncity=min(city, numCities, matrix, completed);
	if (ncity == 1000000) {
		ncity=0;
		cost += matrix[city][ncity];
		return;
	}
	tsp(ncity, matrix, completed, numCities);
}

int getDistance(int x[], int y[], int numCities, int i, int j, int *matrix[]) {
	if (i == j) {
		matrix[i][j] = 0;
		return matrix[i][j];
	}
	//If not, we use the rounding function on the sqrt function, to find the difference
	matrix[i][j] = round(sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)));
	return matrix[i][j];
}

void getData(ifstream &inFile, string line, int numCities, int *identifier, int *x, int *y) {
	for (int i = 0; i < numCities; i++) {
		inFile >> identifier[i];
		//cout << identifier[i] << " ";
		inFile >> x[i];
		//cout << x[i] << " ";
		inFile >> y[i];
		//cout << y[i] << endl;
	}
}

int main(int argc, char* argv[]) {
	ifstream inFile;
	int numCities = 0;
	int p = 0;
	string line;
	if (argc != 2) {
		cout << "Incorrect number of arguments!" << endl;
		return 1;
	}
	inFile.open(argv[1]);
	while (getline(inFile, line)) {
		++numCities;
	}
	int x[numCities];
	int y[numCities];
	int identifier[numCities];
	inFile.clear();
	inFile.seekg(0);
	getData(inFile, line, numCities, identifier, x, y);
	int **matrix = new int*[numCities];

	for (int i = 0; i < numCities; i++) {
		matrix[i] = new int[numCities];
	}
	for (int i = 0; i < numCities; i++) {
		for (int j = 0; j < numCities; j++) {
			getDistance(x, y, numCities, i, j, matrix);
		}
	}
	int completed[numCities];
	for(int i=0; i<numCities; i++){
        completed[i]=0;
    }
	tsp(completed[0], matrix, completed, numCities);
	cout << "cost: " <<  cost << endl;

	return 0;


}
