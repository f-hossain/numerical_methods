#include <iostream>
using namespace std;

double continuedFraction( int n ) {
	int maxNum = 10;
	if ( n <= maxNum && n > 1) {
		return ( 1 / ( 2 + continuedFraction( n-1 ) ) );
	} else {
		return (0.5);
	}
}
int main() {
	double n, result, sqrt;
	for ( n=1; n <= 10; n++) {
		result = continuedFraction(n);
		sqrt = result + 1;
		cout << "The inputted n value is: " << n << endl;
		cout << "This continued fraction approximates to: " << result << endl;
		cout << "The approximated square root of two is: " << sqrt << endl;
	}
}

