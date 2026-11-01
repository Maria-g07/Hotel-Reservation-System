#include "RoomC.h"
#include "Booking.h"

RoomC::RoomC(int capacity, double price, int minPeople, int minDays) : Room(capacity, price) {
	this->minPeople = minPeople;
	this->minDays = minDays;
}

bool RoomC::addBook(Booking *book) {
	bool flag = true;
	for (int i = book->getDay() - 1; i < book->getDay() + book->getDur() - 1; i++) {
		if (_books_[i] != NULL) {
			flag = false;
		}
	}
	if (flag == true) {
		flag = false;
		if ((book->getPeople() <= capacity) && (book->getPeople() >= minPeople) && (book->getDur() >= minDays))
		{ // Cap is valid.
			flag = true;
			for (int i = book->getDay() - 1; i < book->getDay() + book->getDur() - 1; i++) {
				if (_books_[i] == NULL) {
					_books_[i] = book; // Set at records.
				}
			}
			book->setRoom(this); // Set on book object.
		}
	}
	return flag;
}
