/******************************************************************************
	Programming Assignment 2 CSCE 221-506
	Skinkis, Dakota		Wegner, Jeslyn		Hayes, Asa
	dakotaskinkis@tamu.edu		jeslynwegner@tamu.edu		asahayes@tamu.edu
******************************************************************************/

//flight.cpp

#include "flight.h"

Flight::Flight() : flightNum(""), destination(""), departureTime(""), gateNum("")
{

}

// fn = Flight Number, dest = Destination, dt = Departure Time, gn = Gate Number
Flight::Flight(std::string fn, std::string dest, std::string dt, std::string gn)
{
	flightNum = fn;
	destination = dest;
	departureTime = dt;
	gateNum = gn;
}

//Flight::~Flight()
//{
	
//}

bool compareToDestination(Flight f1, Flight f2)
{
  if(f1.destination == f2.destination){
	return true;
  }
  return false;
}

bool compareToDepartureTime(Flight f1, Flight f2)
{
  if(f1.departureTime == f2.departureTime){
	return true;
  }
  return false;
}
