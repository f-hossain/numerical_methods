#include <iostream>
#include <dislin.h>

using namespace std;

const double R = 0.082;

class Gas {
	public: 
		double iA;
		double iB;
		Gas(double aA, double aB) : iA(aA), iB(aB) { }	
};

class VanDerWaalsCalculator {
	public:
		Gas iGas;
		double iVolume[100];
		double iPressure[100];
		double iTemperature;
		double iNumberOfMoles;
		int iNumberOfPoints;
		double delta_V;
		
		VanDerWaalsCalculator ( Gas aGas, double aMinimumVolume, double aMaximumVolume, double aTemperature, double aNumberOfMoles, int aNumberOfPoints) : iGas(aGas) {
			iTemperature = aTemperature;
			iNumberOfMoles = aNumberOfMoles;
			iNumberOfPoints = aNumberOfPoints;
			
			// must find delta V such that you can populate volume vector with equidistant points 
			delta_V = (aMaximumVolume - aMinimumVolume) / (aNumberOfPoints);
			for(int i = 0; i < (iNumberOfPoints); i++) {
				cout << "volume:" << endl;
				if (i == 0) {
					iVolume[i] = aMinimumVolume;
					cout << iVolume[0];
				} else {
					iVolume[i] = iVolume[i-1] + delta_V;
					cout << iVolume[i];
				}
			}
		}
		
		void generatePressure() {
			
			double n = iNumberOfMoles;
			double T = iTemperature;
			double a = iGas.iA;
			double b = iGas.iB;
			
			
			// populate pressure based on volume values 
			for(int i = 0; i < iNumberOfPoints; i++) {
				double V = iVolume[i];
				
				// use van der waals equation of state
				iPressure[i] = (n*R*T) / ((iVolume[i] - (b*n))) - ( ( a * n * n ) / (  V * V  ) ) ;
			}
		}
		
		void draw() {
			metafl("PNG");
			qplot(iVolume, iPressure, iNumberOfPoints);
		}	
};

main() {
	Gas Oxygen(0.027, 0.0014);
	int numberOfPoints = 100;
	float minimumVolume = 1;
	float maximumVolume = 10;
	float temperature = 300;
	float numberOfMoles = 1;
	VanDerWaalsCalculator VDW(Oxygen, minimumVolume, maximumVolume, temperature, numberOfMoles, numberOfPoints);
	VDW.generatePressure();
	VDW.draw();
}
