// main.cpp
// Tests all functionality of the class My_matrix class.

using namespace std;
#include <iostream>
#include <fstream>
#include "My_matrix.h"

int main(){
  
  // Some test cases are expected to throw an exception.
  // Add more try and catch blocks as necessary for your code
  // to finish execution.
	
  try{
    
    // Test 1
    // * Create an object of type My_matrix, called m1, using constructor
    // * Initialize m1 in main (by assigning numbers to matrix elements)
    // * Display m1 on the screen using the operator <<
	
//*	
	//Initialize new My_matrix and verifies dimensions
	cout << endl << "Test 1: " << endl;
	My_matrix m1(2,2);
	cout << "m1 created" << endl;
	cout << "m1 - Rows: " << m1.number_of_rows() << endl;
	cout << "m1 - Columns: " << m1.number_of_columns() << endl << endl;
	
	//assigns and demonstrates proper setting and getting of elements in My_matrix
	cout << "Manual setting + output with elem(i,j)" << endl;
	m1.elem(0,0) = 1;
	cout << m1.elem(0,0) << " ";
	m1.elem(0,1) = 2;
	cout << m1.elem(0,1) << endl;
	m1.elem(1,0) = 3;
	cout << m1.elem(1,0) << " ";
	m1.elem(1,1) = 4;
	cout << m1.elem(1,1) << endl;
	
	cout << "Overloaded << output for m1" << endl << m1 << endl;
	
	// Usually m1 is deleted, but it will be used in test 3.
	//delete m1;
//*/
    
    // Test 2
    // * Create an object of type My_matrix, called m2, using (default)
    //   constructor
    // * Open an input file containing a matrix (row by row)
    // * Initialize m2 by reading from the input file using
    //   the operator >>
    // * Open an output file (can be empty)
    // * Write m2 to the output file using the operator <<
	
// Opens and creates streams for in- and output files, currently commented out for debugging.
  
//*/
	cout << "Test 2: " << endl;

	ifstream infs("test_input.txt");
	ofstream outfs("test_output.txt");
	if (!infs.is_open()) {
	  cerr << "Failed to open in file: " << endl;
	  return 1;
	}
	if (!outfs.is_open()) {
	  cerr << "Failed to open out file: " << endl;
	  return 1;
	}
	
	int temp = 0, ntemp = 0, mtemp = 0; 
	for (int i = 0; i < 2; ++i ) {
	  if (infs >> temp){
	  	switch (i){
		  case 0: ntemp = temp;
		          break;
          case 1: mtemp = temp;
                  break;		  
		}
	  } else {
		cout << "Error: not enough data." << endl;
		return 1;
	  }
	}
	
	My_matrix m2(ntemp,mtemp);
	
	infs >> m2;
	
	outfs << m2.number_of_rows() << " " << m2.number_of_columns() << endl << m2;
	
	cout << endl << "Data sent to output file: " << endl << m2 << endl;
//*/
	
    // Test 3
    // * Use the copy constructor to make a copy of m1 called m3
    // * Apply the copy assignment to m1 called m4
    // * Display m3 and m4 on the screen using the operator <<
	
	cout << "Test 3: " << endl;

	cout << "m3 copy constructed from m1" << endl;
	My_matrix m3(m1);
	cout << "m3:" << endl << m3 << endl;
	cout << "m1:" << endl << m1 << endl;
	cout << "m4 copy assigned from m3" << endl;
	My_matrix m4;
	m4 = m3;
	cout << "m4:" << endl << m4 << endl;
	
    // Test 4
    // * Test the matrix multiplication operator (operator*)
    // * Apply the multiplication operator to valid and invalid cases
    // * Display the resulting matrix and its number of rows and columns
//*/
    cout << "Test 4: " << endl;
	
	ifstream infs_4a("test_input1.txt");
	ifstream infs_4b("test_input2.txt");
	if (!infs_4a.is_open()) {
	  cerr << "Failed to open in file: " << endl;
	  return 1;
	}
	if (!infs_4b.is_open()) {
	  cerr << "Failed to open in file: " << endl;
	  return 1;
	}
	
	temp = 0;
	ntemp = 0;
	mtemp = 0;
	
	for (int i = 0; i < 2; ++i ) {
	  if (infs_4a >> temp){
	  	switch (i){
		  case 0: ntemp = temp;
		          break;
          case 1: mtemp = temp;
                  break;		  
		}
	  } else {
		cout << "Error: not enough data." << endl;
		return 1;
	  }
	}
	
	My_matrix m5(ntemp,mtemp);
	
	infs_4a >> m5;
	
	cout << "m5 from file:" << endl << m5 << endl;
	
	temp = 0;
	ntemp = 0;
	mtemp = 0;
	
	for (int i = 0; i < 2; ++i ) {
	  if (infs_4b >> temp){
	  	switch (i){
		  case 0: ntemp = temp;
		          break;
          case 1: mtemp = temp;
                  break;		  
		}
	  } else {
		cout << "Error: not enough data." << endl;
		return 1;
	  }
	}
	
	My_matrix m6(ntemp,mtemp);
	
	infs_4b >> m6;
	
	cout << "m6 from file:" << endl << m6 << endl;
	
	//Both matrices read in from file, used example matrices from project document
	My_matrix m7 = m5 * m6;
	
	cout << "m7 = m5 * m6: " << endl << m7 << endl;
//*/
    // Test 5
    // * Test the matrix addition operator (operator+)
    // * Apply the multiplication operator to valid and invalid cases
    // * Display the resulting matrix and its number of rows and columns
	
	cout << "Test 5: " << endl;
	
	cout << "m1:" << endl << m1 << endl;
	
	My_matrix m8 = m1 + m1;
	cout << "m8 = m1 + m1: " << endl << m8 << endl;

  } catch(exception &error){
    cerr << "Error: " << error.what() << endl;
  }
  return 0;
}
