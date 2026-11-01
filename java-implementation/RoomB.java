public class RoomB extends RoomA
{
    private double discPerDay;

    public RoomB(int capacity, double price, double disc)
    {
        super(capacity, price);
        discPerDay = disc;
    }

    public double roomCost(){
        double ret = 0;
        double temp = discPerDay;
        double temp1 = 0;
        for(int i=0; i < _books_.length ; i++) {
            if(_books_[i] != null){
                for(int h = 0; h < _books_[i].getDur(); h++){
                    if(price-discPerDay*h >= price/2){
                        temp1 = price-discPerDay*h;
                    }else{
                        temp1 = price/2;
                    }
                    ret += _books_[i].getPeople()*temp1;
                }
            }
        }
        return ret;
    }
    
    public boolean cancel(int code){
        return false; // cannot cancel
    }
}
