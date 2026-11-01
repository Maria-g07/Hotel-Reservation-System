#include <string>
class Room;

class Booking {

private:
	std::string name;
	int id = 0;
	int dur = 0;
	int day = 0;
	int people = 0;
	Room *_room_;
public:
	virtual ~Booking() {
		delete _room_;
	}
	Booking(const std::string &name, int day, int people, int dur);
	virtual int getCode();
	virtual void setDay(int people);
	virtual int getDay();
	virtual void setPeople(int people);
	virtual int getPeople();
	virtual void setName(const std::string &name);
	virtual std::string getName();
	virtual void setDur(int dur);
	virtual int getDur();
	virtual void setRoom(Room *room);
	virtual Room *getRoom();

};
