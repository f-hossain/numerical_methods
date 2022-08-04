// ne 451 final exam question 3
// dec 16 2021

// fariha hossain
// f22hossa
// 20728793

#include <iostream>
#include "math.h"
#include "dislin.h"

using namespace std;

// PART 1: BALL CLASS
class Ball {
	public:
		// params
		Ball iBall;
		double iMass;
		double iCoordinates[2]
		double iVelocity[2];
		
		// getters - read only
		double mass() {
			return iMass;
		}
		
		double coordinates() {
			return iCoordinates;
		}
		
		double velocity() {
			return iVelocity;
		}
		
		// constructor
		Ball ( Ball aBall, double aMass, double aX, double aY, double aVx, double aVy): iBall(aBall) {
			iMass = aMass;
			iCoordinates[0] = aX;
			iCoordinates[1] = aY;
			iVelocity[0] = aVx;
			iVelocity[1] = aVy;	
		}
	
};


// PART 2: TWO BALL SYSTEM CLASS

class TwoBallSystem {
	public:
		// internal member variables
		TwoBallSystem iTwoBallSystem;
		Ball iBall1;
		Ball iBall2;
		double iBallArray[2];
		double forceConst;
		double dampingConst;
		double iXTimeSteps[1000];
		double iYTimeStep[1000];
		double iNumberOfSteps;
		double iTimeInterval;
		
		// constructor
		TwoBallSystem ( TwoBallSystem aTwoBallSystem, Ball aBall1, Ball aBall2, double aForceConstant, double aDampingConstant, int aNumberofSteps, int aTimeInterval ) : iTwoBallSystem(aTwoBallSystem) {
			iBall1 = aBall1;
			iBall2 = aBall2;
			forceConst = aForceConstant;
			dampingConst = aDampingConstant;
			iNumberOfSteps = aNumberOfSteps;
			iTimeInterval = aTimeInterval;
		}
		
		// internal member functions
		
		void propagate() {
			
		}
		
		void setBall() {
			iBallArray[0] = iBall1;
			iBallArray[1] = iBall2;
		}
		
		void plotTrajectory() {
//			qplot();
		}
		
	
};


// PART 3: MAIN FUNCTION
int main( ) {
	
	// first ball
	double mass1 = 1 // kg
	double x10 = 0;
	double y10 = 1;
	double vx10 = -2;
	double vy10 = 0;
	Ball B1(mass1, x10, y10, vx10, vy10);
	
	
	// second ball
	double mass2 = 2 // kg
	double x20 = 0;
	double y20 = -1;
	double vx20 = 0.2;
	double vy20 = 1;
	Ball B1(mass2, x20, y20, vx20, vy20);
	
	
	// two ball system
	double forceConstant = 0.2;
	double dampingConstant = 0.2;
	double numberOfSteps = 1000; 
	double timeInterval = 0.0025;
	TwoBallSystem TBS(B1. B2, forceConstant, dampingConstant, numberOfSteps, timeInterval);
	TBS.setBall();
	
}
