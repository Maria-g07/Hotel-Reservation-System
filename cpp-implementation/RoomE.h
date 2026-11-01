#include "Room.h"

class RoomE : public Room {
public:
	RoomE(int capacity, double price);
    double roomCost() override;
};
