#include "Room.h"

class Booking;

class RoomC : public Room {
	
private:
	int minPeople = 0;
	int minDays = 0;
public:
	RoomC(int capacity, double price, int minPeople, int minDays);
	bool addBook(Booking *book) override;

};
