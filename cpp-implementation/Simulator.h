#pragma once

#include <string>
#include <iostream>

//JAVA TO C++ CONVERTER NOTE: Forward class declarations:
class Hotel;

class Simulator {

	static void main(std::string args[]);

private:
	static int menu();

	static void printProfs(Hotel *hotel);
	
	static double fRand(double fMin, double fMax);
	
	static void userReservation(Hotel *hotel);

	static void cancelRes(Hotel *hotel);


	static std::string randomName();

};
