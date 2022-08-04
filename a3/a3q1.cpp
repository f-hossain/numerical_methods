// NE 451 Assignment 3 Question 1 

// October 18th, 2021

// Fariha Hossain
// f22hossa, 20728793

#include <iostream>

using namespace std;

class Semiconductor{
	
   double iElectronDensity, iHoleDensity, iIntrinsicCarrierDensity;
   
   
   public:
   	  // getters
      double electronDensity( ) {
      	return iElectronDensity;
	  }
      double holeDensity( ) {
      	return iHoleDensity;
	  }   
      double intrinsicCarrierDensity( ) {
      	return iIntrinsicCarrierDensity;
	  }
      
      // setters
      void setElectronDensity( double aElectronDensity ) {
      	iElectronDensity = aElectronDensity;
		// set hole density using recombination law
		iHoleDensity = ( intrinsicCarrierDensity() * intrinsicCarrierDensity() ) / aElectronDensity;
	  } 
      void setHoleDensity( double aHoleDensity ) {
      	iHoleDensity = aHoleDensity;
      	// set electron density using recombination law
      	iElectronDensity =  ( intrinsicCarrierDensity() * intrinsicCarrierDensity() ) / aHoleDensity;
	  } 
      void print(  ) {
      	cout << "Electron density = " << electronDensity() << endl;
      	cout << "Hole density = " << holeDensity() << endl;
      	cout << "Intrinsic carrier density = " << intrinsicCarrierDensity() << endl;
	  }
	  
	  // single element constructor
      Semiconductor( double aIntrinsicCarrierDensity )  {
      	iIntrinsicCarrierDensity = aIntrinsicCarrierDensity;
	  }
}; 

main( ) {
   Semiconductor Silicon( 1.5E10 ); 
   Silicon.setElectronDensity( 1E10 );
   Silicon.print(  );
}

