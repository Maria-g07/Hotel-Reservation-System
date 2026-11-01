#pragma once

#include "Room.h"

class 
RoomA : public Room {
protected:
	double costPerDay = 0;
public:
	RoomA(int capacity, double price);
	double roomCost() override;
};
