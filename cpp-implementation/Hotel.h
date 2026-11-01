#include <string>
#include <vector>
#include <iostream>

class Room;
class Booking;

class Hotel {
	
private:
	std::string name;
	std::vector<Room*> rooms;
	std::vector<Booking*> books;

public:
	Hotel(const std::string &name);
	virtual std::string getName();
	virtual void addRoom(Room *room);
	virtual Room *getRoom(int code);
	virtual Booking *getBook(int code);
	virtual bool setRoomBooking(Booking *book, int code);
	virtual bool setBooking(Booking *book);
	virtual void cancel(int code);
	virtual double Profit();
	virtual double Profit(int code);
	virtual void printPlan();
	virtual void printReserv();
	virtual void printRoomInf();
	virtual Booking *getRandBook();
	
};
