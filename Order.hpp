//August
#ifndef ORDER_HPP
#define ORDER_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Time.hpp"
using namespace std;

class Order {
public:
    Order();
    Order(Time t, string info);
    void departure() throw(logic_error);
    void deliver(Time t) throw(logic_error);
    int timeTillDelivery() throw(logic_error);
    string stringOrder();
private:
    Time orderTime, deliveredTime;
    string order;
    enum Status{toBeDelivered, enroute, delivered};
    Status status;
};

Order::Order():order(""), status(toBeDelivered) {
  //Post: Creates an order with default values for data members. 
}

Order::Order(Time t, string info): status(toBeDelivered) {
  //Post: Creates an order with the given order time and information. 
    orderTime = t;
    order = info;
}

void Order::departure() throw(logic_error) {
  //Pre: Order is at the restaurant. 
  //Post: Order is out for delivery. 

    if(status == enroute || status == delivered) {
        throw logic_error("Order has already departed");
    }
    status = enroute;
}

void Order::deliver(Time t) throw(logic_error) {
  //Pre: Order is out for delivery. 
  //Post: Order is delivered. Time to delivery is recorded.

    if(status == toBeDelivered || status == delivered) {
        throw logic_error("Order is not enroute");
    }
    status = delivered;
    deliveredTime = t;
}

int Order::timeTillDelivery() throw(logic_error) {
  //Pre: Order is delivered. 
  //Post: Returns the minutes until the order is delivered (i.e., between “order” and “deliver” commands). 

    int minTill = Time::elapsedTime(orderTime, deliveredTime);
    return minTill;
}

string Order::stringOrder() {
  //Post: Returns a string containing the order time and info. 
    string tempOrder = "Time: " + orderTime.stringTime() + '\n' +
                       "Order: " + order;
}

#endif
