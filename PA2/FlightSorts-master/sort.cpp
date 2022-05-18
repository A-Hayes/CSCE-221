/******************************************************************************
	Programming Assignment 2 CSCE 221-506
	Skinkis, Dakota		Wegner, Jeslyn		Hayes, Asa
	dakotaskinkis@tamu.edu		jeslynwegner@tamu.edu		asahayes@tamu.edu
******************************************************************************/

//sort.cpp

#include <iostream>
#include "sort.h"

//use this to keep track of comparisons
int num_cmps = 0;

std::vector<Flight> selection_sort(std::vector<Flight> flights, SortOption sortOpt)
{
  	//selection sort
  	for(int i = 0; i < flights.size(); i++){
  	Flight smallest = flights[i];
  	int smallestIndex = i;

		for(int m = i+1; m < flights.size(); m++){
			string left = flights[m].destination;
			string right = smallest.destination;
			if(sortOpt == ByDepartureTime){
				left = flights[m].departureTime;
				right = smallest.departureTime;
			}
			++num_cmps;
			if (left < right){
				smallest = flights[m];
				smallestIndex = m;
			}
		}
		std::swap(flights[i], flights[smallestIndex]);
  	}
  cout << "# of comparisons(selection_sort): " << num_cmps;
  num_cmps = 0;
  return flights;
 }

  
  


std::vector<Flight> insertion_sort(std::vector<Flight> flights, SortOption sortOpt)
{
	//insertion sort
  int curr;
  
  if(sortOpt == ByDepartureTime){
	  for(int i = 0; i < flights.size(); ++i){
		  curr = i;
		  if(curr <= 0 || flights[curr].departureTime >= flights[curr-1].departureTime)
			  ++num_cmps;
		  while(curr > 0 && flights[curr].departureTime < flights[curr-1].departureTime){
			  std::swap(flights[curr],flights[curr-1]);
			  --curr;
			  ++num_cmps;
		  }
	  }
  } else{
	  for(int i = 0; i < flights.size(); ++i){
		  curr = i;
		  if(curr <= 0 || flights[curr].destination >= flights[curr-1].destination)
			  ++num_cmps;
		  while(curr > 0 && flights[curr].destination < flights[curr-1].destination){
			  std::swap(flights[curr],flights[curr-1]);
			  --curr;
			  ++num_cmps;
		  }
	  }
  }
    cout <<"# of comparisons(insertion_sort): " << num_cmps;
	num_cmps=0;
  return flights;
}

std::vector<Flight> bubble_sort(std::vector<Flight> flights, SortOption sortOpt)
{
	//bubble sort
	bool swapped;
	
	if(sortOpt == ByDepartureTime){
		for(int i = 0; i < flights.size()-1; ++i){
			swapped = false;
			for(int j = 0; j < flights.size()-i-1; ++j){
				++num_cmps;
				if(flights[j].departureTime > flights[j+1].departureTime){
					std::swap(flights[j], flights[j+1]);
					swapped = true;
				}
			}
			if(swapped == false)
				break;
		}
	} else{
		for(int i = 0; i < flights.size()-1; ++i){
			swapped = false;
			for(int j = 0; j < flights.size()-i-1; ++j){
				++num_cmps;
				if(flights[j].destination > flights[j+1].destination){
					std::swap(flights[j], flights[j+1]);
					swapped = true;
				}
			}
			if(swapped == false)
				break;
		}
	}
  cout << "# of comparisons(bubble_sort): " << num_cmps;
  num_cmps=0;
  return flights;
}
