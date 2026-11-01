#include "RoomB.h"
#include "Booking.h"

RoomB::RoomB(int capacity, double price, double disc) : RoomA(capacity, price) {
	discPerDay = disc;
}

double RoomB::roomCost() {
	double ret = 0;
	double temp = discPerDay;
	double temp1 = 0;
	for (int i = 0; i < 30 ; i++) {
		if (_books_[i] != NULL) {
			for (int h = 0; h < _books_[i]->getDur(); h++) {
				if (price - discPerDay*h >= price / 2) {
					temp1 = price - discPerDay*h;
				}
				else {
					temp1 = price / 2;
				}
				ret += _books_[i]->getPeople()*temp1;
			}
		}
	}
	return ret;
}

bool RoomB::cancel(int code) {
	return false; // cannot cancel
}
