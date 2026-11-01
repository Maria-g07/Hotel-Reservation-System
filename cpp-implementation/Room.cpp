#include "Room.h"
#include "Booking.h"

int Room::code = 99;

Room::Room(int capacity, double price) {
	code++;
	id = code;
	this->capacity = capacity;
	this->price = price;
	InitRoom();
}

int Room::getCode() {
	return this->id;
}

void Room::setCap(int cap) {
	this->capacity = cap;
}

int Room::getCap() {
	return this->capacity;
}

Booking **Room::getBooks() {
	return this->_books_;
}

bool Room::addBook(Booking *book) {
	bool flag = true;
	if (book->getDay() + book->getDur() - 1 >= 30) {
		return false;
	}
	for (int i = book->getDay() - 1; i < book->getDay() + book->getDur() - 1; i++) {
		if (_books_[i] != NULL) {
			flag = false;
		}
	}

	if (flag == true) {

		flag = false;
		if (book->getPeople() <= capacity)
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

double Room::roomCost() {
	double ret = 0;
	for (int i = 0; i < 30 ; i++) {
		if (_books_[i] != NULL) {
			ret += _books_[i]->getPeople()*price*_books_[i]->getDur();
		}
	}
	return ret;
}

bool Room::cancel(int code) {
	bool flag = false;
	for (int i = 0; i < 30 ; i++) {
		if (_books_[i] != NULL) {
			if (_books_[i]->getCode() == code) {
				_books_[i] = NULL;
				flag = true;
			}
		}
	}
	return flag;
}

int Room::complet() {
	int ret = 0;
	for (int i = 0; i < 30 ; i++) {
		if (_books_[i] != NULL) {
			ret++;
		}
	}
	return ret / 30*10;
}

void Room::InitRoom() {
	for (int i = 0; i < 30 ; i++) {
		_books_[i] = NULL;
	}
}
