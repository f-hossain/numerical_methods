//  NE451 Assignment 8 Problem 1
//  2021-11-20
//  Kaylie Choi - 20692499

#include <iostream>
#include "math.h"
#include <complex>

using namespace std;

// define global variables
const int n = 3; // size of aA matrix
const complex<double> CI = complex<double>(0.0, 1.0); // CI = i

void gauss( complex<double> aA[ ][n], complex<double> aC[ ], complex<double> aB[ ] ) {
  // Forward elimination
  for ( int i = 0; i < n; i ++ ) {
    complex<double> diag = aA[i][i]; // identify diagonal of 3x3 aA matrix
    
    if ( !abs(diag) ) exit( 0 );
    for ( int j = i + 1; j < n; j++ ) {
      complex<double> d = aA[j][i] / diag;
      
      for ( int k = i + 1; k < n; k++ )
        aA[j][k] -= d * aA[i][k];
        aB[j] -= d * aB[i];
    }
  }
  
  if ( !abs(aA[n-1][n-1]) ) exit( 0 );
  
  // Back substitution
  for ( int i = n - 1; i >= 0; i-- ) {
    aC[i] = aB[i];
    for ( int j = i + 1; j < n; j++ ) 
      aC[i] -= aA[i][j] * aC[j];
      aC[i] /= aA[i][i];
  }
}

int main( ) {
  // defining matrices from assignment question; Ac=b
  complex<double> a[n][n] = { { 1, 0, CI }, { -CI, 1, -CI }, {-1, 0, CI} }; 
  complex<double> c[n];
  complex<double> b[n] = { CI, 0, -CI };
  gauss( a, c, b );

  cout << "c matrix: " << endl << c[0] << endl << c[1] << endl << c[2] << endl << endl;
  
  // verify C matrix is correct by manual matrix multiplication
  // Ac = b; b should be [i, 0, -i]
  cout << "dot product of A and c: " << endl;
  cout << (c[0]) + (0.0*c[1]) + (CI * c[2]) << endl; 
  cout << (-CI * c[0]) + (c[1]) - (CI * c[2]) << endl; 
  cout << (-c[0]) + (0.0*c[1]) + (CI * c[2]) << endl; 
}
