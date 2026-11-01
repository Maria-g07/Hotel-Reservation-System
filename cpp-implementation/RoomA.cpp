#include "RoomA.h"
#include "Booking.h"

RoomA::RoomA(int capacity, double price) : Room(capacity, price) {
}

double RoomA::roomCost() {
	double ret = 0;
	for (int i = 0; i < 30 ; i++) {
		if (_books_[i] != NULL) {
			ret += _books_[i]->getPeople()*costPerDay;
		}
	}
	return ret;
}
