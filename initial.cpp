//This program will calculate theta in terms of time t.
// The code was influenced by Computational Physics, Konstantinos N. Anagnostopoulos
//Data will be recorded onto the file circulartrajectory.txt and plotted on Gnuplot

#include <iostream>  
#include <fstream>  
#include <cstdlib>  
#include <string>  
#include <cmath>  
using namespace std;

int main()
{

	//----------------------------
	//Variables

	double x, y, vx, vy, ax, ay, r, x0, y0, theta, omega, t, t0, tf, dt;
	 

	ofstream myfile("circulartrajectory.txt");


	//-----------------------------
	//Inputs
	
	cout << "Please enter omega\n";
	cin >> omega;	 
	while (omega <= 0.0) {
		cout << "Please enter an omega greater than 0\n";
		cin >> omega;	 
	}


	cout << "Please enter the radius r\n";
	cin >> r;	 
	while (r <= 0.0) {
		cout << "Please enter a radius greater than 0\n";
		cin >> r;	 
	}

	cout << "Please enter the center of the circle x0\n";
	cin >> x0;	 

	cout << "Please enter the center of the circle y0\n";
	cin >> y0;	 

	cout << "Please enter the start time\n";
	cin >> t0;	 
	while (t0 < 0.0) {
		cout << "Please enter a start time greater than or equal to 0\n";
		cin >> t0;	 
	}

	cout << "Please enter the final time\n";
	cin >> tf;	 
	while (tf <= 0.0) {
		cout << "Please enter a final time greater than 0\n";
		cin >> tf;	 
	}

	cout << "Please enter the dt\n";
	cin >> dt;  
	while (dt <= 0.0) {
		cout << "Please enter a dt greater than 0\n";
		cin >> dt;	 
	}


	//-----------------------------
	//Equations
	t = t0;
		while (t < tf) {

			theta = omega * (t - t0);
			
			x = x0 + r * cos(theta);
			y = y0 + r * sin(theta);

			vx = -omega * r * sin(theta);
			vy = omega * r * cos(theta);

			ax = -pow(omega, 2) * r * cos(theta);
			ay = -pow(omega, 2) * r * sin(theta);

			myfile << t << " " << x << " " << y << " " << vx << " " << vy << " " << ax << " " << ay << " " << endl;

			t = t + dt;
		}

}
