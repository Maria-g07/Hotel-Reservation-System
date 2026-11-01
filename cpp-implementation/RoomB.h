#include "RoomA.h"

class RoomB : public RoomA {
private:
	double discPerDay = 0;

public:
	RoomB(int capacity, double price, double disc);
	double roomCost() override;
	bool cancel(int code) override;
};
