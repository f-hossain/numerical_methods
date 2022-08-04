

#include <iostream>
#include "math.h"
#include "dislin.h"

using namespace std;


int main( ) {
	
	// -------------------- VARIABLES --------------------
	
	// instantiate + define necessary variables
	int timeSteps = 10000;
	double length = M_PI;
	int numGridPoints = 100;
	// int numGridPoints = 10000;
	
	// set arrays
	double *temp = new double[ numGridPoints ];
	double *tempEnd = new double[ numGridPoints ];
	double *gridPoints = new double[ numGridPoints ];
	
	// set delta and coefficient values based on known data
	double dt = 0.01; 
	double dx = length / ( numGridPoints - 1 );
	double diffusionCoefficient = 0.02; 
	double C = diffusionCoefficient * dt / ( pow(dx, 2 ));
	
	// fill in arrays with appropriate values
	for( int i = 0; i < numGridPoints; i++ ) {
		gridPoints[i] = i * dx;
		// initial temp distribution
		temp[i] = 10. * sin( gridPoints[i] ); 
	}
	
	// -------------------- SOLVE --------------------
	
	// simple diffusion eqn
	for ( int i = 0; i < timeSteps; i++ ) {
		for ( int j = 0; j < numGridPoints; j++ ) {
			tempEnd[j] = temp[j];
		} 
		for ( int j = 0; j < numGridPoints; j++ ) {
			if ( j == ( numGridPoints - 1 ) ) {
				temp[j] = C * ( tempEnd[j - 1] - 2 * tempEnd[j] + temp[0]) + temp[j];
			} 
			else if ( j == 0 ) {
				temp[j] = C * ( tempEnd[numGridPoints - 1] - 2 * tempEnd[j] + tempEnd[j + 1] ) + temp[j];
			}
			else {
				temp[j] = C * ( tempEnd[j - 1] - 2 * tempEnd[j] + tempEnd[j + 1] ) + temp[j];
			}
		} 
	} 


	// -------------------- PLOT --------------------
	
	metafl("XWIN");
	// initiate dislin
	disini( );
	// set scales
	setscl(gridPoints, numGridPoints, "X");
	setscl(temp, numGridPoints, "Y");
	// set vars
	float minX,maxX,minY,maxY,stepX,stepY;
	// plot
	graf(minX, maxX, minX, stepX, minY, maxY, minY, stepY);
	curve(gridPoints,temp,numGridPoints);
	endgrf;
	// exit dislin
	disfin( );

}
