#pragma once

class Booking;

class Room {
protected:
	static int code; // ids start from 100.
	int id = 0;
	int capacity = 0;
	double price = 0;
	Booking **_books_ = new Booking*[30]; // 30 per month
public:
	virtual ~Room() {
		delete[] _books_;
	}

	Room(int capacity, double price);
	virtual int getCode();
	virtual void setCap(int cap);
	virtual int getCap();
	virtual Booking **getBooks();
	virtual bool addBook(Booking *book);
	virtual double roomCost();
	virtual bool cancel(int code);
	virtual int complet();
private:
	void InitRoom();
	
};
