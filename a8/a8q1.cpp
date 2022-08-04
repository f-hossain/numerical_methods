#include <iostream>
#include <math.h>
#include <complex>

using namespace std;

// GLOBAL VARS
// size of matrix
const int n = 3;
// i (imaginary)
const complex <double> CI = complex <double>(0.0, 1.0);

// implement gauss seidel
void gauss(complex<double> aA[ ] [n], complex<double> aC[ ], complex<double> aB[ ] ) {
	// forward elimination
	for (int i = 0; i < n; i++ ) {
		if ( !abs(aA[i][i]) ) exit( 0 );
		for ( int j = i + 1; j < n; j++ ) {
			complex<double> d = aA[j][i] / aA[i][i];
			for ( int k = i + 1; k < n; k++ ) {
				aA[j][k] -= d*aA[i][k];
			}
			aB[j] -= d*aB[i];
		}
	}
	
	if ( !abs(aA[n-1][n-1]) ) exit( 0 );
	// back substitution
	for ( int i = n - 1; i >= 0; i-- ) {
		aC[i] = aB[i];
		for ( int j = i + 1; j < n; j++ ) {
			aC[i] -= aA[i][j] * aC[j];
		}
		aC[i] /= aA[i][i];
	}
}

main( ) {
	// initialize matrices 
	complex<double> a[n][n] = { { 1, 0, CI }, { -CI, 1, -CI }, {-1, 0, CI} };
	complex<double> b[n] = { CI, 0, -CI };
	complex<double> c[n];
	
	// apply gauss function
	gauss( a, c, b );
	
	// print out result
	cout << c[0] << '\t' << c[1] <<  '\t' << c[2] << endl;
}
