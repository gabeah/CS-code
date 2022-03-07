//GabeH
//Griddle Pi
//3.6.22

#include <iostream>
#include <cmath>

constexpr double gridpi2(unsigned npoints){
	double inside = 0;
	for (double i = 0; i < npoints; i++){
		for (double j = 0; j < npoints; j ++){
			if (std::hypot(i,j)<npoints){
				inside += 1.0;
			}
		}
	}	
	
	double output = (inside/(npoints*npoints)) * 4.0;
	return output;
}

double gridpi(unsigned npoints){
	double inside = 0;
	for (double i = 0; i < npoints; i++){
		for (double j = 0; j < npoints; j ++){
			if (std::hypot(i,j)<npoints){
				inside += 1.0;
			}
		}
	}	
	
	double output = (inside/(npoints*npoints)) * 4.0;
	return output;
}

int main(){
	int input;
	std::cout << "input number: \n";
	std::cin >> input;
	std::cout << gridpi(input) << "\n";
}
