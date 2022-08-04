// NE 451 Assignment 7 Question 3 

// November 15th, 2021

// Fariha Hossain
// f22hossa, 20728793

#include <iostream>
#include <dislin.h>
#include <math.h>

using namespace std;

// global variable to track the iterations
int iter = 0;

// function with which to evaluate newtons method: f(x) = sin(x) OR f(x) = x*sqrt(x)
double myFunction( double aD ) {
	return sin(aD);
//	return aD * sqrt(fabs(aD));
}

// define the derivative to use
double derivative( double aF(double), double aX) {
	double delta = 1e-4;
	return (aF(aX + delta) - aF(aX - delta)) / (2. * delta);
}

// define the recursive newton's method
double newton(double aF(double), double a, double aEps) {
	iter++;
	double del = -aF(a) / derivative( aF, a );
	a += del;
	if (fabs(del) < aEps ) {
		return a;
	} else {
		return newton(aF, a, aEps);
	}
}

main () {
	// output the results and compare against the number of iterations it took
	cout << "Root: " << newton(myFunction, 0.1, 1.e-4) << endl;
	cout << "Number of evaluations: " << iter << endl;
}
