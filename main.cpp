//Sarah, August and Rekik

#include "Driver.hpp"
#include "Order.hpp"
#include "Restaurant.hpp"
#include "Time.hpp"

#include <iostream>
using namespace std; 

//using the sample input from class 
//TO DO: 
  /*

  */
void print_help();
int main()
{ 
    Restaurant res1;
    Driver dan("Dan");
    Driver adam("Adam");
    res1.addDriver(&dan);
    res1.addDriver(&adam);
    
    Time time1(10, 00);
    Time time2(10, 15);
    Time time3(10, 30);
    Time time4(10, 45);
    Time time5(11, 00);

    res1.addOrder(time1, "2 cheese to 120 West Mango Lane");
    dan.login();
    
    res1.serveNextOrder();
    res1.departNextOrder(dan, time2);
    
    res1.addOrder(time3, "7 goats to 140 Milner Avenue");
    adam.login();
    
    res1.addOrder(time4, "12 bears to 12 Honey Badger Aquarium");
    res1.serveNextOrder();
   
    cout << "Report 1: "<< endl;
    res1.status();
    cout << endl;
    
    res1.deliver(dan, time4, 4.50);
    dan.arrive(time5);
    
    cout << "Report 2: "<< endl;
    res1.status();
    cout << endl;
    cout<< "\nSummary:\n";
    res1.summary();
    
// print_help();

    return 0;
}

void print_help() {
    cout << endl << "Commands:" << endl;
    cout << "Note: All times should be entered in standard military time format\n" << endl;
    cout << "  help    : Displays this message again" << endl;
    cout << "  login   : Used when driver reports for duty \n \t \tEx: login Sam" << endl;
    cout << "  logout  : Used when driver leaves for the day \n \t \tEx: logout Sam" << endl;
    cout << "  order   : Used to add new order to the system \n \t \t"
            "Ex: order 9:55 3 pepperoni to 123 Sesame Street" << endl;
    cout << "  serve   : Used when an order is done cooking and enqueued"
            "for delivery \n \t \tEx: serve 0:" << endl;
    cout << "  depart  : Used when driver goes out to deliver the next order"
            "enqueued for delivery \n \t \tEx: depart 13:09 Sam" << endl;
    cout << "  deliver : Used when driver delivers an order to a customer,"
            "the driver's tip is entered as a float"
            " \n \t \tEx: deliver 13:45 Sam 5.45" << endl;
    cout << "  arrive  : Used when driver returns from delivering an order"
            "\n \t \tEx: arrive 14:02 Sam" << endl;
    cout << "  status  : Displays status of orders and drivers" << endl;
    cout << "  summary : Displays summary statistics on orders and drivers" << endl;
    cout << "  quit    : Quits the program" << endl;
    cout << endl;
}

void rest (Restaurant r)
//for login
      case 1: {   
          if(x==-1) {
              cout << "\t" << "Please enter values after the command" << endl;
              break;
          }               
          if(r.getDriver(testData) == 0) {
              cout << "\t" << "Error: Driver does not exist. Use command 'Drivers' to see available drivers" << endl; 
                        break;
          } else {
              r.getDriver(testData)->login();
              cout << "\t" << testData << " The driver has logged in." << endl;  
          }
          break;
      } 
}
