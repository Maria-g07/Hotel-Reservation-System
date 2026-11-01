#include "RoomE.h"
#include "Booking.h"

RoomE::RoomE(int capacity, double price) : Room(capacity, price) {
}

double RoomE::roomCost() {
  double ret = 0;
  for (int i = 0; i < 30 ; i++) {
	  if (_books_[i] != NULL) {
		  ret += _books_[i]->getDur()*(price / 2)*_books_[i]->getPeople();
	  }
  }
  return ret;
}
