public class Room
{
    
    protected static int code = 99; // ids start from 100.
    protected int id;
    protected int capacity;
    protected double price;
    protected Booking[] _books_ = new Booking[30]; // 30 per month
    
    public Room(int capacity, double price)
    {
        code++;
        id = code;
        this.capacity = capacity;
        this.price = price;
        InitRoom();
    }

    public int getCode(){ return this.id; }
    
    public void setCap(int cap){ this.capacity = cap; }
    
    public int getCap(){ return this.capacity; }
    
    public Booking[] getBooks(){ return this._books_; }
    
    public boolean addBook(Booking book){
        boolean flag = true;
        if( book.getDay()+book.getDur()-1 >= 30){
            return false;
        }
        for( int i = book.getDay()-1; i < book.getDay()+book.getDur()-1; i++){
            if(_books_[i] != null){
                flag = false;
            }
        }

        if(flag == true){

            flag = false;
            if(book.getPeople() <= capacity){ // Cap is valid.
                
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
    
    public double roomCost(){
        double ret = 0;
        for(int i=0; i < _books_.length ; i++) {
            if(_books_[i] != null){
                ret += _books_[i].getPeople()*price*_books_[i].getDur();
            }
        }
        return ret;
    }
    
    public boolean cancel(int code){
        boolean flag = false;
        for(int i=0; i < _books_.length ; i++) {
            if(_books_[i] != null){
                if(_books_[i].getCode() == code){
                    _books_[i] = null;
                    flag = true;
                }
            }
        }
        return flag;
    }
    
    public int complet(){
        int ret = 0;
        for(int i=0; i < _books_.length ; i++) {
            if(_books_[i] != null){
                ret++;
            }
        }
        return ret/_books_.length*10;
    }
    
    private void InitRoom(){
        for(int i=0; i < _books_.length ; i++) {
            _books_[i] = null;
        }
    }
}
