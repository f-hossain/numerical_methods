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
    return ( (*iF)(aX - 2*iDx) - 8*(*iF)(aX - iDx) + 8*(*iF)(aX + iDx) - (*iF)(aX + 2*iDx) ) / ( 12*iDx );
		}
		DerivativeCalculator( double aDx, double aF(double)) : iDx( aDx ) { iF = aF; }
};


// function to approximate
double pow_six( double aX ) {
	return pow( aX, 6 );
}


int main ( ) {
	// define initial values
	double delta = 0.1;
	DerivativeCalculator DC1( delta, pow_six );
	double y[10], log_x[10], x3[10], x4[10], log_err[10] ;
	// iterate through possible delta x values and their associated errors
	for (int i = 0; i < 10; i++) {
		y[i] = DC1.deriv(1.0);
		log_x[i] = log(DC1.dx());
		x3[i] = pow(DC1.dx(), 3);
		x4[i] = pow(DC1.dx(), 4);
		log_err[i] = log(fabs( DC1.deriv(1.0) - 6 ));
		DC1.setDx( DC1.dx() / 1.3 );
	}
	
	
	// define all plots 
	// ------------------------------------------------------------------------
	
	// derivative against third power of step length
	metafl("PNG");
	disini();
	name("Third Power of Delta X", "x");
	name("Derivative", "y");
	incmrk(1);
	setscl(x3, 10, "x");
	setscl(y, 10, "y");
	double minX, maxX, minY, maxY, stepX, stepY;
	graf( minX, maxX, minX, stepX, minY, maxY, minY, stepY );
	curve(x3, y, 10);
	disfin();	
	
		
	
	// derivative against fourth power of step length
	metafl("PNG");
	disini();
	name("Fourth Power of Delta X", "x");
	name("Derivative", "y");
	incmrk(1);
	setscl(x4, 10, "x");
	setscl(y, 10, "y");
	double minX2, maxX2, minY2, maxY2, stepX2, stepY2;
	graf( minX2, maxX2, minX2, stepX2, minY2, maxY2, minY2, stepY2 );
	curve(x4, y, 10);
	disfin();
	
	// verify fourth order accuracy
	metafl("PNG");
	disini();
	name("log x", "x");
	name("log error", "y");
	labels("LOG", "xy");
	incmrk(1);
	setscl(log_x, 10, "x");
	setscl(log_err, 10, "y");
	double minX3, maxX3, minY3, maxY3, stepX3, stepY3;
	graf( minX3, maxX3, minX3, stepX3, minY3, maxY3, minY3, stepY3 );
	curve(log_x, log_err, 10);
	disfin();
	
}
