// NE 451 Assignment 7 Question 3 

// November 15th, 2021

// Fariha Hossain
// f22hossa, 20728793

#include <iostream>
#include <dislin.h>
#include <math.h>

using namespace std;

// function with which to evaluate newtons method: f(x) = x^3
double myFunction( double aD ) {
	return pow(aD, 3);
}

// define the derivative to use
double derivative( double aF(double), double aX, double delta) {
	return (aF(aX + delta) - aF(aX - delta)) / (2. * delta);
}

// define the recursive newton's method
double newton(double aF(double), double a, double aEps, double delta) {
	double del = -aF(a) / derivative( aF, a, delta );
	a += del;
	if (fabs(del) < aEps ) {
		return a;
	} else {
		// call the function again, until the previous condition is satisfied
		return newton(aF, a, aEps, delta);
	}
}

main () {
	// initialize and set variables to use
	double x0 = 0.1;
	double del = 0.1;
	double x[10], y[10];
	
	// iterate through different values of delta x
	for ( int i = 0; i < 10; i++) {
		// take the log of the results for the plot
		x[i] = log(del);
		y[i] = newton(myFunction, 0.1, 1.e-4, del);
		
		// update the delta x value for the next iteration
		del = del / sqrt(10);
	}
	
	// PLOT THE RESULTS
	
	metafl("XWIN"); 
	disini( ); 
	// set x and y axes
	name("delta x", "x");
	name("root", "y");
	// set x axis label as log since we want the log plot 
	labels("LOG", "x"); 
	incmrk(1);
	// set scale
	setscl(x, 10, "x");
	setscl(y, 10, "y");
	double minX, maxX, minY, maxY, stepX, stepY;
	graf( minX, maxX, minX, stepX, minY, maxY, minY, stepY );
	curve(x, y, 10);
	disfin();
}
