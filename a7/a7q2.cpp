// NE 451 Assignment 7 Question 2 

// November 15th, 2021

// Fariha Hossain
// f22hossa, 20728793

#include <iostream>
#include <dislin.h>
#include <math.h>

using namespace std;

// define function to solve: f(x) = x^5
double fifth(double aX) {
	return pow(aX, 5);
}

// define class implementation of the simpsons rule
class SimpsonsCalculator {
	private:
		double iUpperLimit, iLowerLimit, iIntegral, iDx;
		int iIntervals;
		double (*iF) (double);
		
	public :
	
		// constructor
		SimpsonsCalculator( double (*aF) (double) ) : iF(aF) { }
		
		// getter function for the number of intervals we're using to solve with
		int intervals() {
			return iIntervals;
		}
		
		// setter function for the number of intervals we're using to solve with
		void setIntervals( int aIntervals ) {
			iIntervals = aIntervals;
		}
		
		// getter function for the right limit of the integral
		int upperLimit() {
			return iUpperLimit;
		}
		
		// setter function for the right limit of the integral
		void setUpperLimit( int aUpperLimit ) {
			iUpperLimit = aUpperLimit;
		}
		
		// getter function for the left limit of the integral
		int lowerLimit() {
			return iLowerLimit;
		}
		
		// setter function for the left limit of the integral
		void setLowerLimit( int aLowerLimit ) {
			iLowerLimit = aLowerLimit;
		}
		
		// getter function for the delta x value 
		double dx() {
			return iDx;
		}
		
		// getter function for the resultant integral value
		double integral() {
			return iIntegral;
		}
		
		// define simpsons rule used to find the integral value
		void integrate() {
			// calculate the value for delta x based on input values for the integral limits
			iDx = (iUpperLimit - iLowerLimit) / iIntervals;
			
			// set initial x value as the lower limit
			double x = iLowerLimit;
			
			// iterate through the number of intervals to find the result
			double sum = 0;
			for (int i = 0; i <= iIntervals; i++) {
				sum += (iF(x) + 4 * iF( x + iDx / 2) + iF(x + iDx)) / 6. ;
				x += iDx;
			}
			
			iIntegral = sum * iDx;
		}
};

main () {
	
	// initialize and set variables to use
	double x[10], y[10]; 
	SimpsonsCalculator SC1( fifth );
	SC1.setUpperLimit(1);
	SC1.setLowerLimit(0);
	SC1.setIntervals(10);
	
	// use the simpsons method to calculate the integral
	SC1.integrate();

	// populate x and y arrays with the step length and integral value
	for (int i = 0; i < 10; i++) {
		x[i] = log( SC1.dx( ) );
		SC1.integrate( );
		y[i] = log( fabs ( SC1.integral( ) - 1.0 / 6.0 ) );
		
		// update the interval to use for the next iteration
		SC1.setIntervals(SC1.intervals( ) * 1.3);
	}
	
	// PLOT THE RESULTS
	
	metafl("XWIN"); 
	disini( ); 
	// set x and y axes
	name("Logarithm of the step length", "x");
	name("Logarithm of the error", "y"); 
	incmrk(1);
	// set scale
	setscl(x, 10, "x");
	setscl(y, 10, "y");
	double minX, maxX, minY, maxY, stepX, stepY;
	graf( minX, maxX, minX, stepX, minY, maxY, minY, stepY );
	curve(x, y, 10);
	disfin();
}
