// NE 451 Assignment 3 Question 2 

// October 18th, 2021

// Fariha Hossain
// f22hossa, 20728793

#include <iostream>

using namespace std;

class Rectangle {
   public:
      // constructor
      Rectangle( double aLength, double aWidth ) {
         iLength = aLength;
         iWidth = aWidth;
      }

      // getters
      double length( ) { 
         return iLength; 
      }
      double width( ) { 
         return iWidth; 
      }

      // setters
      void setWidth( double aWidth ) { 
         iWidth = aWidth; 
      }
      void setLength( double aLength ) { 
         iLength = aLength; 
      }

      // function for calculating area using length and width getters
      void area( ) { 
         cout << length( ) * width( ); 
      }

   private:
      double iLength;
      double iWidth;
};

main( ) {
   Rectangle R1( 10, 20 );
   R1.area( );
}
