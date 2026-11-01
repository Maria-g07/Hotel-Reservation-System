import java.util.*;

public class Hotel
{
    private String name;
    private ArrayList<Room> rooms = new ArrayList<Room>();
    private List<Booking> books = new ArrayList<Booking>();
    
    public Hotel(String name)
    {
       this.name = name; // Set Hotel Name
    }

    public String getName(){ return this.name; }
    
    public void addRoom(Room room){
        rooms.add(room);
    }
        
    public Room getRoom(int code){
        for(int i = 0 ; i < rooms.size() ; i++ ){
            if(rooms.get(i).getCode() == code)
                return rooms.get(i);
        }
        return null;
    }
    
    public Booking getBook(int code){
        for(int i = 0 ; i < books.size() ; i++ ){
            if(books.get(i).getCode() == code)
                return books.get(i);
        }
        return null;
    }

    public boolean setRoomBooking(Booking book, int code){
        Room temp = getRoom(code);
        if(temp.addBook(book)){
            System.out.println(">Booked successfully.");
            temp.addBook(book);
            books.add(book);
            return true;
        }
        System.out.println(">Book error.");
        return false;
    }
    
    public boolean setBooking(Booking book){
        for(int i = 0 ; i < rooms.size() ; i++ ){
            if(rooms.get(i).addBook(book)){
                books.add(book);
                System.out.format(">Reservation[%03d] added to Room %d\n", book.getCode(), rooms.get(i).getCode());
                return true;
            }
        }
        System.out.println(">Reservation cannot be added");
        return false;
    }
    
    
    public void cancel(int code){
        Booking temp = getBook(code);
        if(temp.getRoom().cancel(code)){
            System.out.println(">Reservation canceled successfully.");
            books.remove(temp);
            
        }
        else {
            System.out.println(">Reservation cancel error.");
        }
    }
    
    public double Profit(){
        double ret = 0;
        for(int i = 0 ; i < rooms.size() ; i++ ){
            ret += rooms.get(i).roomCost();
        }
        return ret;
    }
    
    public double Profit(int code){
        double ret = 0;
        for(int i = 0 ; i < rooms.size() ; i++ ){
            if(rooms.get(i).getCode() == code){
                ret += rooms.get(i).roomCost();
                break;
            }
        }
        return ret;
    }
    
    public void printPlan(){
        System.out.println("Rooms Plan\n------------------------------");
        System.out.print("Room ID |");
        for(int i = 0 ; i < 30; i++){
            System.out.format(" %02d", i+1);
        }
        System.out.println("");
        for(int i = 0 ; i < rooms.size() ; i++ ){
            System.out.format("%03d     |", rooms.get(i).getCode());
            Booking[] temp = rooms.get(i).getBooks();
            for(int j = 0; j < temp.length; j++ ){
                if(temp[j] == null){
                    System.out.print("  _");
                }else{
                    System.out.print("  *");
                }
            }
            System.out.println("");
        }
    }
    
    public void printReserv(){
        System.out.println("Reservations Info\n------------------------------");
        System.out.format("Room.Code| Name         |Res.Code\n");
        for(int i = 0 ; i < books.size() ; i++ ){
            System.out.format("%03d      | %s          | %03d\n", books.get(i).getCode(), books.get(i).getName(), books.get(i).getRoom().getCode());
        }
    
    }
    
    public void printRoomInf(){
        System.out.println("Rooms Info\n------------------------------");
        System.out.format("Code | Capacity  | Profits\n");
        for(int i = 0 ; i < rooms.size() ; i++ ){
            System.out.format("%03d  |    %02d     | %2f\n", rooms.get(i).getCode(), rooms.get(i).getCap(), rooms.get(i).roomCost());
        }
    
    }
    
    public Booking getRandBook(){
       Random rn = new Random();
       if(books.size() > 0){
           int temp = rn.nextInt( books.size() );
           return books.get(temp);
       }else{
            return null;
       }
    }
}
