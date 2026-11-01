#include "RoomD.h"
#include "Booking.h"

int RoomD::peopleLim = 3;

RoomD::RoomD(int capacity, double price) : Room(capacity, price) {
}

bool RoomD::addBook(Booking *book) {
	bool flag = true;
	for (int i = book->getDay(); i < book->getDay() + book->getDur(); i++) {
		if (_books_[i] == NULL) {
			flag = false;
		}
	}
	if (flag == true) {
		flag = false;
		if ((book->getPeople() <= capacity) && (book->getPeople() == peopleLim))
		{ // Cap is valid.
			flag = true;
			for (int i = book->getDay(); i < book->getDay() + book->getDur(); i++) {
				if (_books_[i] == NULL) {
					_books_[i] = book; // Set at records.
				}
			}
			book->setRoom(this); // Set on book object.
		}
	}
	return flag;
}

double RoomD::roomCost() {
	double ret = 0;
	for (int i = 0; i < 30 ; i++) {
		if (_books_[i] != NULL) {
			ret += _books_[i]->getDur()*price;
		}
	}
	return ret;
}
