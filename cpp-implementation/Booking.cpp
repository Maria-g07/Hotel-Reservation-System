#include "Booking.h"
#include "Room.h"

static int code = 0;

Booking::Booking(const std::string &name, int day, int people, int dur) {
	code++;
	id = code; // assign id.
	this->name = name;
	this->people = people;
	this->day = day;
	this->dur = dur;
	this->_room_ = NULL;
}

int Booking::getCode() {
	return this->id;
}

void Booking::setDay(int people) {
	this->day = day;
}

int Booking::getDay() {
	return this->day;
}

void Booking::setPeople(int people) {
	this->people = people;
}

int Booking::getPeople() {
	return this->people;
}

void Booking::setName(const std::string &name) {
	this->name = name;
}

std::string Booking::getName() {
	return this->name;
}

void Booking::setDur(int dur) {
	this->dur = dur;
}

int Booking::getDur() {
	return this->dur;
}

void Booking::setRoom(Room *room) {
	this->_room_ = room;
}

Room *Booking::getRoom() {
	return this->_room_;
}
