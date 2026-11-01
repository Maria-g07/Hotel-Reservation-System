public class RoomC extends Room
{
    private int minPeople;
    private int minDays;
    
    public RoomC(int capacity, double price, int minPeople, int minDays)
    {
        super(capacity, price);
        this.minPeople = minPeople;
        this.minDays = minDays;
    }


    public boolean addBook(Booking book){
        boolean flag = true;
        for( int i = book.getDay()-1; i < book.getDay()+book.getDur()-1; i++){
            if(_books_[i] != null){
                flag = false;
            }
        }
        if(flag == true){
            flag = false;
            if((book.getPeople() <= capacity) && (book.getPeople() >= minPeople) && (book.getDur() >= minDays)){ // Cap is valid.
                flag = true;
                for( int i = book.getDay()-1; i < book.getDay()+book.getDur()-1; i++){
                    if(_books_[i] == null){
                        _books_[i] = book; // Set at records.
                    }
                }
                book.setRoom(this); // Set on book object.
            }
        }
        return flag;
    }
    
}
