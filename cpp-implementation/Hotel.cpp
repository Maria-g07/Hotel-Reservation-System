#include "Hotel.h"
#include "Room.h"
#include "Booking.h"
#include <time.h>       /* time */
#include <stdlib.h>     /* srand, rand */

Hotel::Hotel(const std::string &name) {
   this->name = name; // Set Hotel Name
}

std::string Hotel::getName() {
	return this->name;
}

void Hotel::addRoom(Room *room) {
	rooms.push_back(room);
}

Room *Hotel::getRoom(int code) {
	for (int i = 0 ; i < rooms.size() ; i++) {
		if (rooms[i]->getCode() == code) {
			return rooms[i];
		}
	}
	return NULL;
}

Booking *Hotel::getBook(int code) {
	for (int i = 0 ; i < books.size() ; i++) {
		if (books[i]->getCode() == code) {
			return books[i];
		}
	}
	return NULL;
}

bool Hotel::setRoomBooking(Booking *book, int code) {
	Room *temp = getRoom(code);
	if (temp->addBook(book)) {
		std::cout << ">Booked successfully." << std::endl;
		temp->addBook(book);
		books.push_back(book);
		return true;
	}
	std::cout << ">Book error." << std::endl;
	return false;
}

bool Hotel::setBooking(Booking *book) {
	for (int i = 0 ; i < rooms.size() ; i++) {
		if (rooms[i]->addBook(book)) {
			books.push_back(book);
			printf (">Reservation %03d added to Room %03d \n", book->getCode(), rooms[i]->getCode());
			return true;
		}
	}
	std::cout << ">Reservation cannot be added" << std::endl;
	return false;
}

void Hotel::cancel(int code) {
	Booking *temp = getBook(code);
	if (temp->getRoom()->cancel(code)) {
		std::cout << ">Reservation canceled successfully." << std::endl;
	}
	else {
		std::cout << ">Reservation cancel error." << std::endl;
	}
}

double Hotel::Profit() {
	double ret = 0;
	for (int i = 0 ; i < rooms.size() ; i++) {
		ret += rooms[i]->roomCost();
	}
	return ret;
}

double Hotel::Profit(int code) {
	double ret = 0;
	for (int i = 0 ; i < rooms.size() ; i++) {
		if (rooms[i]->getCode() == code) {
			ret += rooms[i]->roomCost();
			break;
		}
	}
	return ret;
}

void Hotel::printPlan() {
	std::cout << "Rooms Plan\n------------------------------" << std::endl;
	std::cout << "Room ID |";
	for (int i = 0 ; i < 30; i++) {
		printf (" %02d", i+1);
	}
	std::cout << std::endl;
	for (int i = 0 ; i < rooms.size() ; i++) {
		printf ("%03d     |", rooms[i]->getCode());
		Booking **temp = rooms[i]->getBooks();
		for (int j = 0; j < 30; j++) {
			if (temp[j] == NULL) {
				std::cout << "  _";
			}
			else {
				std::cout << "  *";
			}
		}
		std::cout << std::endl;
	}
}

void Hotel::printReserv() {
	std::cout << "Reservations Info\n------------------------------" << std::endl;
	std::cout << "Room.Code| Name         |Res.Code\n";
	for (int i = 0 ; i < books.size() ; i++) {
		printf ("%03d      | %s      | %03d\n", books[i]->getCode(), books[i]->getName().c_str(),books[i]->getRoom()->getCode() );
	}

}

void Hotel::printRoomInf() {
	std::cout << "Rooms Info\n------------------------------" << std::endl;
	std::cout << "Code | Capacity  | Profits\n";
	for (int i = 0 ; i < rooms.size() ; i++) {
		printf ("%03d  |    %02d     | %03f \n", rooms[i]->getCode(),rooms[i]->getCap(),rooms[i]->roomCost());
	}

}

Booking *Hotel::getRandBook() {
	srand ( time( NULL ) ); /* Initialize Seed */
   	if (books.size() > 0) {
   		int temp = rand() % books.size(); /* generate number between 0 and 1: */
	   	return books[temp];
   	}
   	else {
		return NULL;
   }
}
