//============================================================================
// Name        : gorillas.cpp
// Author      : Chintan Mistry
// Version     :
// Copyright   : 
// Description : This program computes the horizontal range of a banana given an intial launch angle
//============================================================================
#include <iostream>
#include <cmath>
#include <String>

int main();
double horizontal_velocity(double vi, double theta);
double vertical_velocity(double vi, double theta);
double gravity();
double computed_range(double vi, double theta, double height);

double horizontal_velocity(double vi, double theta) {
	double vx, r_ang;
     r_ang = (theta*M_PI)/180;
	  vx = vi*(cos(r_ang));
	return vx;
}
double vertical_velocity(double vi, double theta){
	double vy, r_ang;
	  r_ang = (theta*M_PI)/180;
	  vy=vi*(sin(r_ang));
	return vy;
}
double gravity(){

	return (9.80665);
}
double computed_range(double vi, double theta, double height){
	double d, vv, hv, g;
	hv= horizontal_velocity(vi, theta);
	vv= vertical_velocity(vi, theta);
	g = gravity();
	d=((hv*vv) + hv*(sqrt((vv*vv) + (2*g*height))))/g;
	return(d);


}


int main() {
	int input;
	std::string replay;
	std::cout << "Welcome to Banana Launch" << std::endl;
	while(input != -1){
		std::cout << "Please specify a launch angle or enter -1 to end the program: ";
		std::cin >> input;
		std::cout << "The range the banana reaches for the launch angle of " << input << " degrees is " << computed_range(600, input, 10) << std::endl;
		std::cout << "Would you like to play again? [Y or N]: ";
		std::cin >> replay;
		if(replay == "N"){
			std::cout << "Thanks for playing!" << std::endl;
			break;
		}
	}

	return 0;
}

