#ifndef DRIVER_H
#define DRIVER_H
//Rekik

#include <iostream>
#include <vector>
#include <string>
#include "Order.hpp"


using namespace std;

class Driver : Order,Time{
private:
    string name;
    bool loggedIn = false;
    float totalTip = 0.0;
    Order curOrder;
    Time orderTime;
    Time departTime;
    Time deliverTime; //added
    Time arriveTime;
    int totalOrders = 0;
    int totalDeliveryTime = 0;
    int totalDelivery = 0; //added
    int totalDrivingTime = 0;
    enum Status{atRestaurant, driving, delivering};
    Status status;

public:
    Driver(string Driver_name);
    void login();
    void logout();
    string getName();
    void depart(Order order, Time time)throw (logic_error);
    void deliver(Time time, float tip)throw (logic_error);
    void arrive(Time time)throw (logic_error);
    int getTotalMinDelivering();
    int getTotalDeliveries();
    float getTotalTips();
    Order getOrder()throw (logic_error);
    int getTotalMinDriving();
    string toString();


};

#endif

Driver:: Driver(string Driver_name){
 // Post: Creates a logged-in driver with the given name. 
    this -> name = Driver_name;
}
void Driver:: login(){
  //Pre: Driver is not logged in. 
  //Post: Logs the driver in. 
if(loggedIn = true)
    loggedIn = true;
}
void Driver:: logout(){
  //Pre: Driver is logged in and at the restaurant. 
//Post: Logs the driver out. 

    loggedIn = false;
}

void Driver:: depart(Order order, Time time)throw (logic_error){
  //Pre: Driver is logged in and at the restaurant. 
  //Post: Driver is delivering. Departure time is recorded. 

    if(status != atRestaurant && loggedIn != true) {
        throw logic_error("Lazy Driver! Driver is not available");
    }else{
        status = delivering;
        departTime = time;
    }
}

void Driver:: deliver(Time time, float tip)throw (logic_error){
  //Pre: Driver is delivering, tip >= 0. 
//Post: Driver is not delivering. Driver’s stats are updated. 

    if(status != delivering ) {
        throw logic_error("Driver is not delivering");
    }else{
        status = driving;
        totalTip += tip;
        totalDelivery ++;
        deliverTime = time;
    }
}
void Driver:: arrive(Time time)throw (logic_error){
  //Pre: Driver is driving but not delivering. 
  //Post: Driver is at the restaurant. Driver’s stats are updated. 

    if(status != driving){
        throw logic_error("Driver is not driving");
    }else{
        status = atRestaurant;
        arriveTime = time;
    }
}
string Driver:: getName(){
  //Post: Returns the driver’s name. 
    return name;
}

int Driver:: getTotalDeliveries(){
  //Post: Returns the total number of completed deliveries. 
    return totalDelivery;
}

int Driver:: getTotalMinDelivering(){
  //Post: Returns the total minutes spent delivering (i.e., between “depart” and “deliver” commands). 
    return elapsedTime(departTime, deliverTime);
}
int Driver:: getTotalMinDriving(){
  //Post: Returns the total minutes spent driving (i.e., between “depart” and “arrive” commands). 
    return elapsedTime(departTime, arriveTime);
}
float Driver:: getTotalTips(){
  //Post: Returns the total tips received, in dollars. 
    return totalTip;
}
 

Order getOrder()throw (logic_error){
  //Pre: Driver is delivering. 
//Post: Returns the order being delivered. 

  if(status != delivering)

    return theOrder;
}
 


string Driver::toString(){
  //Post: Returns a string containing the driver’s name, state (e.g., not logged in), and, if the driver is delivering an order, the departure time and toString of the order being delivered. 
    string temp;
    if(loggedIn == true){
        if(status == driving){
            temp = "Name: " + name + "\n" + "Status: " + "Logged In " +
                    "\n" + "Departure Time: " + departTime.stringTime() + "\n" + curOrder.stringOrder();
           }
        else{
            temp = "Name: " + name + "\n" + "Status: " + "Logged In ";
        }
    }
    else{
        temp = "Name: " + name + "\n" + "Status: " + "Logged Out ";
    }

    return temp;
}
