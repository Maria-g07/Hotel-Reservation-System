import java.util.*;

public class Simulator
{

    public static void main(String [] args) {
       System.out.println("Java Project Simulator");
       System.out.println("-------------------------");
       System.out.println(">Creating Hotel Object..");
       /* Initialize Hotel Object.*/
       Hotel test = new Hotel("Upatras");
       try {
           Thread.sleep(500);
        } catch(InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
       System.out.println(">Creating Room Objects..");
       Random rn = new Random();
       int temp = 10 + rn.nextInt( 10 );
       // Initialize Hotel with Room Objects.
       for(int i = 0; i < temp ; i++){
           System.out.println(">Creating Room Object[" + (i+1) + "]..");
           try {
               Thread.sleep(100);
            } catch(InterruptedException ex) {
                Thread.currentThread().interrupt();
            }
           int cap = 1 + rn.nextInt( 4 );
           double price = 5 + (50 - 5) * rn.nextDouble();
           int roomType = rn.nextInt(15);
           if(roomType < 5){
               Room room = new Room(cap, price);
               test.addRoom(room);
           } else if(roomType < 6){
               RoomA room = new RoomA(cap, price);
               test.addRoom(room);
           } else if(roomType < 8){
               double disc = 15 + (15 - 5) * rn.nextDouble();
               RoomB room = new RoomB(cap, price, disc);
               test.addRoom(room);
           }else if(roomType < 10){
               RoomC room = new RoomC(cap, price, 1+rn.nextInt(3), 1+rn.nextInt(5));
               test.addRoom(room);
           }else if(roomType < 13){
               RoomD room = new RoomD(cap, price);
               test.addRoom(room);
           }else {
               RoomE room = new RoomE(cap, price);
               test.addRoom(room);
           }
           
           
           
       }
       System.out.println(">Simulation start..");
       try {
           Thread.sleep(100);
       } catch(InterruptedException ex) {
           Thread.currentThread().interrupt();
       }       
       int selection = menu();
       while(selection != 8){
           Booking book = new Booking(randomName(), 1 + rn.nextInt( 29 ), 1 + rn.nextInt( 3 ), 1 + rn.nextInt( 4 )); // Create Random Reservation.
           test.setBooking(book); // Add Reservation.
           int canc = rn.nextInt(4);
           if(canc == 3 ){
               test.cancel(test.getRandBook().getCode());
           }
           switch (selection) {
                case 1:  
                    break;
                case 2:
                    userReservation(test);
                    break;
                case 3:
                    cancelRes(test);
                    break;
                case 4:
                    test.printReserv();
                    break;
                case 5:
                    test.printRoomInf();
                    break;
                case 6:
                    test.printPlan();
                    break;
                case 7:
                    printProfs(test);
                case 8:
                    break;
                default: 
                    break;
            }
           selection = menu();
       }
    }
    
    private static int menu() {
        int selection;
        Scanner input = new Scanner(System.in);
        System.out.println("\n\nChoose from above choices");
        System.out.println("-------------------------\n");
        System.out.println("1 - Next Iteration");
        System.out.println("2 - Add Reservation");
        System.out.println("3 - Cancel Reservation");
        System.out.println("4 - Print Reservations");
        System.out.println("5 - Print Room Info");
        System.out.println("6 - Print Room Plans");
        System.out.println("7 - Print Profits");
        System.out.println("8 - Quit");
        selection = input.nextInt();
        while(selection < 1 || selection > 9 ){
            System.out.println("Wrong Input! Input must be in range of(1-9)");
            selection = input.nextInt();
        }
        return selection;    
    }

    private static void printProfs(Hotel hotel){
        Scanner input = new Scanner(System.in);
        System.out.print(">Give room id(-1 to skip) : (");
        int room = input.nextInt();
        if(room != - 1){
            Room temp = hotel.getRoom(room);
            if(temp != null){
                System.out.println(">Room profit is : " + temp.roomCost() );
            }else{
                System.out.println(">Invalid Room Id!");
            }
        }else{
            System.out.println(">Hotel Profit is : " + hotel.Profit());
        }
    }
    
    private static void userReservation(Hotel hotel){
        Scanner input = new Scanner(System.in);
        System.out.print(">Give Reservation name : ");
        String name = input.next();
        System.out.print(">Give day of arival : ");
        int day = input.nextInt();
        System.out.print(">Give Reservation's duration : ");
        int dur = input.nextInt();
        System.out.print(">Give Reservation's people : ");
        int people = input.nextInt();
        System.out.print(">Give room id(-1 to skip) : ");
        int room = input.nextInt();
        Booking temp = new Booking(name, day, people, dur);
        if( room == - 1){
            hotel.setBooking(temp); // Inser at random room.
        } else {
            if( hotel.getRoom(room) == null ){
                System.out.println(">Invalid Room Id!");
            } else {
                
                hotel.setRoomBooking(temp,room); // Insert at a specific room
            }
        }
    }
    
    private static void cancelRes(Hotel hotel){
        int selection;
        Scanner input = new Scanner(System.in);
        System.out.print(">Give Reservation code : ");
        selection = input.nextInt();
        hotel.cancel(selection);
    }
    
    
    private static String randomName(){
       Random rn = new Random();

       String[] names = {"Alex Worth","George Will","Nick Monter","Julia Hop","Nickolas Hunter",
            "George Manus","Helen Ulter","Peter Pan","Crish Cros","Cristina Noon","John Null","Nick After","Juli Pan","After Dark","Java Lang","Other User","Roor root","Windows Vista","Bill Gates","Steve Jobs"};
       int temp = rn.nextInt( names.length );
       return names[temp];
    }
    
}
