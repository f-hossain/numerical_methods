#include <iostream>
#include <dislin.h>
#include <math.h>

using namespace std;

// derivative operator class definition
class DerivativeCalculator {
	double (*iF)(double);
	double iDx;
	public:
		void setDx( double aDx ) {
			iDx = aDx;
		}
		double dx() {
			return iDx;
		}
		double deriv( double aX ) {
    		return ( 4*(*iF)(aX + iDx) - (*iF)(aX + 2*iDx) - 3*(*iF)(aX) ) / (2*iDx);
		}
		DerivativeCalculator( double aDx, double aF(double)) : iDx( aDx ) { iF = aF; }
};


// function to approximate
double pow_four( double aX ) {
	return pow( aX, 4 );
}


int main ( ) {
	// define initial values
	double delta = 0.1;
	DerivativeCalculator DC1( delta, pow_four );
	double x2[10], err[10] ;
	// iterate through possible delta x values and their associated errors
	for (int i = 0; i < 10; i++) {
		x2[i] = pow(DC1.dx(), 2);
		err[i] = fabs( DC1.deriv(1.0) - 4 );
		DC1.setDx( DC1.dx() / 1.3 );
	}
	
	
	// plot error against delta x
	metafl("PNG");
	disini();
	name("second power of delta x", "x");
	name("error", "y");
	labels("EXP", "xy");
	incmrk(1);
	setscl(x2, 10, "x");
	setscl(err, 10, "y");
	double minX3, maxX3, minY3, maxY3, stepX3, stepY3;
	graf( minX3, maxX3, minX3, stepX3, minY3, maxY3, minY3, stepY3 );
	curve(x2, err, 10);
	disfin();
	
}
