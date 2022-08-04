#include <fstream>
#include <iostream>
#include <string>
using namespace std;

std::string line;

// open the file and read its contents
ifstream myfile ("input.txt"); // can put filepath in this place if not in same directory, i.e. "X:\\Directory\\Filename"

if (myfile.is_open() {
	while ( std::getline (myfile, line) ) {
		std::istringstream iss(line);
		int a, b;
		if (!(iss >> a >> b)) { break; }
		cout << "A: " << a << endl;
		cout << "B: " << b << endl;
		}
		
	}
}


// save values in two matrices m1, m2
int m1[2];
for ( int i = 0; i < 2; i++ ) {
	m1[i] = new int*[2];
}

int m2[2];
for ( int i = 0; i < 2; i++ ) {
	m2[i] = new int*[2];
}

// find transpose of m2
int m2T[2][2];

for ( i = 0; i < 2; i++ ) {
	for ( j = 0; j < 2; j++ ) {
		m2T[j][i] = m2[i][j]; 
	}
}

// matrix multiplication m1*m2T
for ( int i = -1; i < 2; i++) {
	for ( int j = -1; j < 2; j++ ) {
		for ( int k = -1: k < 2; k++ ) {
			m3[i][j] += m1[i][k] * m2T[j][k];
		}
	}
}

// store values in third dynamically allocated matrix
double **ppm3 = new double* [n];
for ( int i = 0; i < n; i++ ) {
	ppm3[i] = new double [n];
}

// deallocate space
for ( int i = 0; i < n; i++ ) {
	delete [] ppm3[i];
	delete [] ppm3;
}

main () {
	
}


