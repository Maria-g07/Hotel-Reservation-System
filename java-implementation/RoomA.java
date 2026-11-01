public class RoomA extends Room
{
    protected double costPerDay;

    public RoomA(int capacity, double price)
    {
        super(capacity, price);
    }

    public double roomCost(){
        double ret = 0;
        for(int i=0; i < _books_.length ; i++) {
            if(_books_[i] != null){
                ret += _books_[i].getPeople()*costPerDay;
            }
        }
        return ret;
    }
}
