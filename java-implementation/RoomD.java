public class RoomD extends Room
{
    private static int peopleLim = 3;
    public RoomD(int capacity, double price)
    {
        super(capacity, price);
    }

    public boolean addBook(Booking book){
        boolean flag = true;
        for( int i = book.getDay(); i < book.getDay()+book.getDur(); i++){
            if(_books_[i] == null){
                flag = false;
            }
        }
        if(flag == true){
            flag = false;
            if((book.getPeople() <= capacity) && (book.getPeople() == peopleLim)){ // Cap is valid.
                flag = true;
                for( int i = book.getDay(); i < book.getDay()+book.getDur(); i++){
                    if(_books_[i] == null){
                        _books_[i] = book; // Set at records.
                    }
                }
                book.setRoom(this); // Set on book object.
            }
        }
        return flag;
    }
    
    
    public double roomCost(){
        double ret = 0;
        for(int i=0; i < _books_.length ; i++) {
            if(_books_[i] != null){
                ret += _books_[i].getDur()*price;
            }
        }
        return ret;
    }
}
