#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP
//Rekik
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Restaurant{
private:
    vector<Driver> employees;
    vector<Order> cooking;
    vector<Order> departure;
    int totalDelivery;
    int totalTime;
public:
    Restaurant();
    void status();
    void summary();
    Driver * getDriver(string name);
    void addDriver(Driver* driver);
    void addOrder(/*Order* order*/ Time t, string info);
    void serveNextOrder() throw (logic_error);
    void departNextOrder(Driver driver, Time time) throw (logic_error);
    void deliver(Driver driver, Time time, float tip);
};

#endif

//Sarah  
Restaurant:: Restaurant(): totalDelivery(0), totalTime(0){
  //Post: Creates a restaurant in an initial state, with no drivers or orders. 
}
void Restaurant:: status(){
//Post: Prints status of orders and logged-in drivers, as specified by the “status” command description. 
}
void Restaurant ::summary(){

}
Driver * getDriver(string name){

}
void Restaurant:: addDriver(Driver* driver){

}
void Restaurant:: addOrder(/*Order* order*/ Time t, string info){ //if errors check here !!!

}
void Restaurant:: serveNextOrder() throw (logic_error){

}
void Restaurant::departNextOrder(Driver driver, Time time) throw (logic_error){

}
void Restaurant:: deliver(Driver driver, Time time, float tip){

}
