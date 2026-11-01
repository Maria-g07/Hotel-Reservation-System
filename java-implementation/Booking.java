public class Booking
{

    private String name;
    private static int code = 0; // static for unique id per object.
    private int id;
    private int dur;
    private int day;
    private int people;
    private Room _room_;
    
    public Booking(String name, int day, int people, int dur)
    {
        code++;
        id = code; // assign id.
        // Init rest.
        this.name = name;
        this.people = people;
        this.day = day;
        this.dur = dur;
        this._room_ = null;
    }
    
    public int getCode(){ return this.id; }
    
    public void setDay(int people){ this.day = day; }
    
    public int getDay() { return this.day; }
    
    public void setPeople(int people){ this.people = people; }
    
    public int getPeople(){ return this.people; }
    
    public void setName(String name){ this.name = name; }
    
    public String getName(){ return this.name; }
    
    public void setDur(int dur){ this.dur = dur; }
    
    public int getDur(){ return this.dur; }
    
    public void setRoom(Room room){ this._room_ = room; }
    
    public Room getRoom(){ return this._room_; }
    
}
