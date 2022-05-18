/******************************************************************************
	Programming Assignment 2 CSCE 221-506
	Skinkis, Dakota		Wegner, Jeslyn		Hayes, Asa
	dakotaskinkis@tamu.edu		jeslynwegner@tamu.edu		asahayes@tamu.edu
******************************************************************************/

//PA2.cpp

#include <sstream>
#include <iostream>
#include <fstream>

#include "sort.h"


std::vector<Flight> readFlights(std::string fileName);
void printFlight(Flight f); //outputs individual flight to file
void printFlights(std::vector<Flight> flights, string fileName); //outputs all flights to file
void dispFlights(std::vector<Flight> flights); // outputs flights to terminal
void dispFlight(Flight f); //outputs individual flight to terminal

const string INPUT_PATH = "PA2-18a-InputData/";
const string CSV_FILE_FORMAT = ".csv";
const string ASCEN = "ascen";
const string DESCEN = "descen";
const string RAND = "rand";
const string TXT_FILE_FORMAT = ".txt";
const string SORTED_DEST = "sorted_dest_";
const string SORTED_TIME = "sorted_time_";
const string OUTPUT_PATH = "PA2-18a-InputData/";
ofstream outFile;

int main()
{
  //reads all files
  
  
  // prints ascending order flights by departure time
  // change the bound of I to 10000 to print all files
  
	//loop for sorting by departure time
	
	cout << endl;
	cout << "The sorted output files are written to the " <<OUTPUT_PATH<< " folder." << endl;
	cout << "Change destination by changing the variable OUTPUT_PATH." << endl;
	cout << endl << "This is the amount of comparisons sorted by departure time." << endl << endl;

  for(int i = 10; i <= 10000; i*=10){
    const string ascenFile = INPUT_PATH + ASCEN + std::to_string(i) + CSV_FILE_FORMAT;
    const string descenFile = INPUT_PATH + DESCEN + std::to_string(i) + CSV_FILE_FORMAT;
    const string randFile = INPUT_PATH + RAND + std::to_string(i) + CSV_FILE_FORMAT;
    const string ascenOutFile = OUTPUT_PATH + SORTED_TIME + ASCEN + std::to_string(i) + TXT_FILE_FORMAT;
    const string descenOutFile = OUTPUT_PATH + SORTED_TIME + DESCEN + std::to_string(i) + TXT_FILE_FORMAT;
    const string randOutFile = OUTPUT_PATH + SORTED_TIME + RAND + std::to_string(i) + TXT_FILE_FORMAT;
    
	//if the file size is = 10, print it to the terminal
	if(i == 10){
		dispFlights(selection_sort(readFlights(ascenFile),ByDepartureTime));
		dispFlights(insertion_sort(readFlights(descenFile),ByDepartureTime));
		dispFlights(bubble_sort(readFlights(randFile),ByDepartureTime));
	}
	 cout << endl << endl;
	 cout << "Size of file: " << i ;
	 cout << endl;
     printFlights(selection_sort(readFlights(ascenFile),ByDepartureTime),ascenOutFile);
	 cout << endl;
	 printFlights(insertion_sort(readFlights(descenFile),ByDepartureTime),descenOutFile);
	 cout << endl;
	 printFlights(bubble_sort(readFlights(randFile),ByDepartureTime),randOutFile);
  }
  
 
  cout << endl << endl << endl << "This is the amount of comparisons sorted by destination." << endl << endl;

  for(int i = 10; i <= 10000; i*=10){
    const string ascenFile = INPUT_PATH + ASCEN + std::to_string(i) + CSV_FILE_FORMAT;
    const string descenFile = INPUT_PATH + DESCEN + std::to_string(i) + CSV_FILE_FORMAT;
    const string randFile = INPUT_PATH + RAND + std::to_string(i) + CSV_FILE_FORMAT;
    const string ascenOutFile = OUTPUT_PATH + SORTED_DEST + ASCEN + std::to_string(i) + TXT_FILE_FORMAT;
    const string descenOutFile = OUTPUT_PATH + SORTED_DEST + DESCEN + std::to_string(i) + TXT_FILE_FORMAT;
    const string randOutFile = OUTPUT_PATH + SORTED_DEST + RAND + std::to_string(i) + TXT_FILE_FORMAT;

	
	//if the file size is = 10, print it to the terminal
	if(i == 10){
		dispFlights(selection_sort(readFlights(ascenFile),ByDepartureTime));
		dispFlights(insertion_sort(readFlights(descenFile),ByDepartureTime));
		dispFlights(bubble_sort(readFlights(randFile),ByDepartureTime));
	}
	 cout << endl << endl;
	 cout << "Size of file: " << i;
	 cout << endl;
     printFlights(selection_sort(readFlights(ascenFile),ByDestination),ascenOutFile);
	 cout << endl;
     printFlights(insertion_sort(readFlights(descenFile),ByDestination),descenOutFile);
	 cout << endl;
     printFlights(bubble_sort(readFlights(randFile),ByDestination),randOutFile);
  }
  
  return 0;
}

//read in the flights from the input file at fileName and store them in a vector
std::vector<Flight> readFlights(std::string fileName)
{
  
  std::vector<Flight> flights;
	
	std::ifstream inFile;
	
//opens the file and notifies user if it fails
		inFile.open(fileName);
    if(!inFile.is_open()){
      cout << "Failure opening file, please a different file.";
      return flights;
    }
    //throws away the first line
    string dummyLine; 
    std::getline(inFile, dummyLine);
    
    while(inFile.peek() != EOF){

//reads the file term by term, line denoted by a ',' except for gateNum due to file formatting
      Flight f1;
  		std::getline(inFile,f1.flightNum, ',');
  		std::getline(inFile,f1.destination, ','); 
  		std::getline(inFile,f1.departureTime, ',');
  		std::getline(inFile,f1.gateNum);
  		flights.push_back(f1);
    }
  
  return flights;
}

//writes an individual flight to the output file
void printFlight(Flight f){
  outFile  << endl << f.flightNum << "," << '\t' << f.destination << "," << '\t' << f.departureTime << "," << '\t' << f.gateNum;
  }

//writes all the flights and formats the table on the output file
//I could not figure out how to create a folder using c++, otherwise i would have wrote them to a new folder
void printFlights(std::vector<Flight> flights, string fileName){
 
  outFile.open(fileName);

  if(outFile.is_open()){
    outFile << "Flight Number" << '\t' << "Destination" << '\t' << "Departure Time" << '\t' << "Gate Number";
  for(int i = 0; i < flights.size(); i++){
    printFlight(flights[i]);
  }
  outFile.close();
}

}
//prints flight to terminal 
void dispFlight(Flight f){
	cout << endl << f.flightNum << "," << '\t' << f.destination << "," << '\t' << f.departureTime << "," << '\t' << f.gateNum;
}
//prints all flights of file size = 10 to terminal
void dispFlights(std::vector<Flight> flights){
	cout << endl << "Flight Number" << '\t' << "Destination" << '\t' << "Departure Time" << '\t' << "Gate Number";
	for(int i = 0; i < flights.size(); i++){
    dispFlight(flights[i]);
  }
}
