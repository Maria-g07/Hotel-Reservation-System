#include "Room.h"

class Booking;

class RoomD : public Room {
private:
	static int peopleLim;
public:
	RoomD(int capacity, double price);
	bool addBook(Booking *book) override;
	double roomCost() override;
};
