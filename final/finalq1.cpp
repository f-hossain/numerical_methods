
// ne 451 final exam question 1
// dec 16 2021

// fariha hossain
// f22hossa
// 20728793

#include <iostream>
#include "math.h"
#include "dislin.h"

using namespace std;

int main( ) {
	// initialize variables and dynamically allocate arrays
	double numberOfPoints, randomDist, numberOfDimensions, thresholdDistance;
	double **randomDist = new double* [];
	double **histogramBins = new double* [100];
	
	// prompt for user input: numberOfPoints
	cin >> numberOfPoints; // 110 in example
	
	// generate random distribution
	randomDist = rand() % numberOfPoints + 1;
	
	// prompt for user input: numberOfDimensions
	// projection of a point along each axis - uniformly dist number between 0 and 1
	cin >> numberOfDimensions; // 15 in example
	
	// prompt for user input: thresholdDistance
	cin >> thresholdDistance; //  0.9 in example
	
	// calculate number of pairs
	int totalNumberOfPairs = numberOfPoints*(numberOfPoints - 1) / 2;
	
	// calculate largest possible distance within a given dimension
	int L_max = pow(numberOfDimensions, 0.5);
	
	// find total number of pairs closer than the threshold distance
	
	
	// calculate total pairs + separate into histogram bins
	
	
	// outputs totalNumberOfPairs that are closer than the threshold distance
	
	
	// output: qplot of histrogram of number of pairs of points every 100 equal length intervals betweem 0 and L_max
	
	
	// deallocate all dynamically allocated arrays before the program exits
	
	// (1) distribution of points
	for ( int i = 0; i < n; i++ ) {
		delete [] randomDist[i];
		delete [] randomDist;
	}
	
	// --- histogram bins ---
	for ( int i = 0; i < 100; i++ ) {
		delete [] histogramBins[i];
		delete [] histogramBins;
	}
	
}

