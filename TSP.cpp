#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <cmath>
#include <bits/stdc++.h> 

using namespace std;


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
		inFile >> x[i];
		inFile >> y[i];
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

  
    return 0; 
}