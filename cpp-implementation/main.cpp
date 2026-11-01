#include <cstdlib>
#include <iostream>
#include "Hotel.h"
#include "Room.h"
#include "RoomA.h"
#include "RoomB.h"
#include "RoomC.h"
#include "RoomD.h"
#include "RoomE.h"
#include "Booking.h"
#include <time.h>       /* time */
#include <stdlib.h>     /* srand, rand */

using namespace std;

void printProfs(Hotel *hotel) {
	std::cout << ">Give room id(-1 to skip) : (";
	int room;
	std::cin >> room;
	if (room != - 1) {
		Room *temp = hotel->getRoom(room);
		if (temp != NULL) {
			std::cout << ">Room profit is : " << temp->roomCost() << std::endl;
		}
		else {
			std::cout << ">Invalid Room Id!" << std::endl;
		}
	}
	else {
		std::cout << ">Hotel Profit is : " << hotel->Profit() << std::endl;
	}
}

void userReservation(Hotel *hotel) {
	std::string name;
	std::cout << ">Give Reservation name : ";
	std::cin >> name;
	std::cout << ">Give day of arival : ";
	int day;
	std::cin >> day;
	std::cout << ">Give Reservation's duration : ";
	int dur;
	std::cin >> dur;
	std::cout << ">Give Reservation's people : ";
	int people;
	std::cin >> people;
	std::cout << ">Give room id(-1 to skip) : ";
	int room;
	std::cin >> room;
	Booking *temp = new Booking(name, day, people, dur);
	if (room == - 1) {
		hotel->setBooking(temp); // Inser at random room.
	}
	else {
		if (hotel->getRoom(room) == NULL) {
			std::cout << ">Invalid Room Id!" << std::endl;
		}
		else {

			hotel->setRoomBooking(temp,room); // Insert at a specific room
		}
	}
}

void cancelRes(Hotel *hotel) {
	int selection;
	std::cout << ">Give Reservation code : ";
	std::cin >> selection;
	hotel->cancel(selection);
}

std::string randomName() {
   srand ( time( NULL ) ); /* Initialize Seed */
   std::string *names = new std::string[20] {"Alex Worth","George Will","Nick Monter","Julia Hop","Nickolas Hunter", "George Manus","Helen Ulter","Peter Pan","Crish Cros","Cristina Noon","John Null","Nick After","Juli Pan","After Dark","Java Lang","Other User","Roor root","Windows Vista","Bill Gates","Steve Jobs"};
   int temp = rand() % 20;	
   return names[temp];
}

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

int menu() {
	int selection;
	std::cout << "\n\nChoose from above choices" << std::endl;
	std::cout << "-------------------------\n" << std::endl;
	std::cout << "1 - Next Iteration" << std::endl;
	std::cout << "2 - Add Reservation" << std::endl;
	std::cout << "3 - Cancel Reservation" << std::endl;
	std::cout << "4 - Print Reservations" << std::endl;
	std::cout << "5 - Print Room Info" << std::endl;
	std::cout << "6 - Print Room Plans" << std::endl;
	std::cout << "7 - Print Profits" << std::endl;
	std::cout << "8 - Quit" << std::endl;
	std::cin >> selection;
	while (selection < 1 || selection > 9) {
		std::cout << "Wrong Input! Input must be in range of(1-9)" << std::endl;
		std::cin >> selection;
	}
	return selection;
}

int main(int argc, char *argv[])
{
std::cout << "Java Project Simulator" << std::endl;
   std::cout << "-------------------------" << std::endl;
   std::cout << ">Creating Hotel Object.." << std::endl;
   /* Initialize Hotel Object.*/
   Hotel *test = new Hotel("Upatras");
   std::cout << ">Creating Room Objects.." << std::endl;
   srand ( time( NULL ) ); /* Initialize Seed */
   int temp = rand() % 10 + 10;
   // Initialize Hotel with Room Objects.
   for (int i = 0; i < temp ; i++) {
	   std::cout << ">Creating Room Object[" << (i << 1) << "].." << std::endl;
	   int cap = rand() % 4 + 1;
	   double price = 5 + fRand(10, 50);
	   int roomType = rand() % 15;
	   if (roomType < 5) {
		   Room *room = new Room(cap, price);
		   test->addRoom(room);
	   }
	   else if (roomType < 6) {
		   RoomA *room = new RoomA(cap, price);
		   test->addRoom(room);
	   }
	   else if (roomType < 8) {
	   	   double disc = 15 + fRand(10, 20);
		   RoomB *room = new RoomB(cap, price, disc);
		   test->addRoom(room);
	   }
	   else if (roomType < 10) {
		   RoomC *room = new RoomC(cap, price, rand() % 3 + 1 , rand() % 5 + 1);
		   test->addRoom(room);
	   }
	   else if (roomType < 13) {
		   RoomD *room = new RoomD(cap, price);
		   test->addRoom(room);
	   }
	   else {
		   RoomE *room = new RoomE(cap, price);
		   test->addRoom(room);
	   }



   }
   std::cout << ">Simulation start.." << std::endl;
   int selection = menu();
   while (selection != 8) {
	   Booking *book = new Booking(randomName(), rand() % 29 + 1, rand() % 3 + 1, rand() % 4 + 1); // Create Random Reservation.
	   test->setBooking(book); // Add Reservation.
	   int canc = rand() % 4;
	   if (canc == 3) {
		   test->cancel(test->getRandBook()->getCode());
	   }
	   switch (selection) {
			case 1:
				break;
			case 2:
				userReservation(test);
				break;
			case 3:
				cancelRes(test);
				break;
			case 4:
				test->printReserv();
				break;
			case 5:
				test->printRoomInf();
				break;
			case 6:
				test->printPlan();
				break;
			case 7:
				printProfs(test);
			case 8:
				break;
			default:
				break;
	   }
	   selection = menu();
   }
    return EXIT_SUCCESS;
}

