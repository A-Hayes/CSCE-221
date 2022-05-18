/******************************************************************************
	Programming Assignment 2 CSCE 221-506
	Skinkis, Dakota		Wegner, Jeslyn		Hayes, Asa
	dakotaskinkis@tamu.edu		jeslynwegner@tamu.edu		asahayes@tamu.edu
******************************************************************************/

//sort.h

#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "flight.h"
using namespace std;
enum SortOption {
  ByDestination,
  ByDepartureTime
};

//implement each of these functions for their respective sort
std::vector<Flight> selection_sort(std::vector<Flight> flights,
				   SortOption sortOpt);

std::vector<Flight> insertion_sort(std::vector<Flight> flights,
				   SortOption sortOpt);

std::vector<Flight> bubble_sort(std::vector<Flight> flights,
				SortOption sortOpt);
