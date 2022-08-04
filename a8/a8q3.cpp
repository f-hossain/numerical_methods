#include <iostream>
#include <math.h>
#include <dislin.h>

using namespace std;

main () {
	// INITIALIZE PARAMS
	double x[40000], v[40000], a=1, b=0, c=0.3, F=10, t=0, dt = 0.03;
	
	// SET INITIAL CONDITIONS
	x[0] = 1;
	v[0] = 6;
	
	// USE EULER METHOD
	for ( int i = 1; i < 40000 ; i++ ) {
		x[i] = x[i - 1] + v[i - 1] * dt;
		v[i] = v[i - 1] - (a*pow(x[i-1], 3) + b*x[i-1] + c*v[i - 1] + F*cos(t)) * dt; 
		t += dt / 2;
	}
	
	// GENERATE PLOTS
	float minX,maxX,minY,maxY,stepX,stepY;
	metafl("PNG");
	disini( );
	setscl(x, 40000, "X");
	setscl(v, 40000, "Y");
	incmrk(-1); // This plots markers at each point and supresses lines between points
	marker(21); // The marker type (here filled circles)
	hsymbl(15); // The marker size (very small)
	graf(minX, maxX, minX, stepX, minY, maxY, minY, stepY);
	curve(x,v,40000);
	endgrf;
	disfin( );
}
