// Gravitational field of a point earth. Illustrates simple 3-dimensional
// plotting routines.
#include <iostream>
#include <dislin.h>
#include <math.h>
using namespace std;
const double KM = 1000; // Note this procedure!
// An alternate naming
// convention capitalizes
// all global constants
const double GRAVITATIONALCONSTANT = 6.67e-11;
const double EARTHMASS = 5.97e24;
const double EARTHRADIUS = 6380 * KM;
const int MATSIZE = 20; // This MUST be declared a const int
// to be used in the subsequent
// type statements!
double gravitationalField(double aX, double aY) {
const double radius = sqrt(aX * aX + aY * aY);
if (radius >= EARTHRADIUS)
	return GRAVITATIONALCONSTANT * EARTHMASS / (aX * aX + aY * aY);
else if (radius < EARTHRADIUS)
	return GRAVITATIONALCONSTANT * EARTHMASS * radius / (EARTHRADIUS * EARTHRADIUS * EARTHRADIUS);
}
main ( ) {
double position[MATSIZE]; // x and y coordinate positions
double field[MATSIZE][MATSIZE]; // the gravitational field CHANGE TO
// FLOAT FOR S.P. DISLIN LIBARY
float offset = MATSIZE / 2 - 0.5; // Determines the starting point of the grid
for (int loop = 0; loop < MATSIZE; loop++) {
position[loop] = 0.1 * EARTHRADIUS * (loop - offset);
}
float x, y;
for (int outerLoop = 0; outerLoop < MATSIZE; outerLoop++) {
x = position[outerLoop];
for (int innerLoop = 0; innerLoop < MATSIZE; innerLoop++) {
y = position[innerLoop];
field[outerLoop][innerLoop] = gravitationalField(x,y);
}
}
metafl("XWIN");
disini( ); // required for 3-dimensional plots
int iPlot = 0; // set to 1 for surface plot, 2 for color plot.
if (iPlot == 1) // surface plot
// The conversion function (explicit cast) double* below (which returns the first
// memory location occupied by the matrix) is required by dislin.
// REPLACE ALL (double*) BELOW by (float*) ONLY IF YOU ARE USING THE
// SINGLE PRECISION DISLIN LIBRARY
qplsur((double*) field, MATSIZE, MATSIZE);
else if (iPlot == 2) // color plot
qplclr((double*) field, MATSIZE, MATSIZE);
else { // contour plot
int numberOfContours = 30;
qplcon((double*) field, MATSIZE, MATSIZE, numberOfContours);
}
}
