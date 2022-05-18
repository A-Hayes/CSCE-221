// main.cpp
// Tests all functionality of the class My_matrix class.

using namespace std;
#include <iostream>
#include <fstream>
#include "TemplatedMy_matrix.h"

int main(){
  
  // Some test cases are expected to throw an exception.
  // Add more try and catch blocks as necessary for your code
  // to finish execution.
	
  try{
    
    // Test 1
    // * Create an object of type My_matrix, called m1, using constructor
    // * Initialize m1 in main (by assigning numbers to matrix elements)
    // * Display m1 on the screen using the operator <<
	

	//Initialize new My_matrix and verifies dimensions
	cout << endl << "Test 1: " << endl;
	My_matrix<int> m1(2,2);
	cout << "m1 created, type <int>" << endl;
	cout << "m1 - Rows: " << m1.number_of_rows() << endl;
	cout << "m1 - Columns: " << m1.number_of_columns() << endl << endl;
	
	My_matrix<double> m1a(2,2);
	cout << "m1a created, type <double>" << endl;
	cout << "m1a - Rows: " << m1.number_of_rows() << endl;
	cout << "m1a - Columns: " << m1.number_of_columns() << endl << endl;
	
	My_matrix<long> m1b(2,2);
	cout << "m1b created, type <long>" << endl;
	cout << "m1b - Rows: " << m1.number_of_rows() << endl;
	cout << "m1b - Columns: " << m1.number_of_columns() << endl << endl;
	
	//assigns and demonstrates proper setting and getting of elements in My_matrix
	cout << "Manual setting of m1 + output with elem(i,j)" << endl;
	m1.elem(0,0) = 1; 
	cout << m1.elem(0,0) << " ";
	m1.elem(0,1) = 2;
	cout << m1.elem(0,1) << endl;
	m1.elem(1,0) = 3;
	cout << m1.elem(1,0) << " ";
	m1.elem(1,1) = 4;
	cout << m1.elem(1,1) << endl;
	
	cout << "Manual setting of m1a + output with elem(i,j)" << endl;
	m1a.elem(0,0) = 1.1;
	cout << m1a.elem(0,0) << " ";
	m1a.elem(0,1) = 2.2;
	cout << m1a.elem(0,1) << endl;
	m1a.elem(1,0) = 3.3;
	cout << m1a.elem(1,0) << " ";
	m1a.elem(1,1) = 4.4;
	cout << m1a.elem(1,1) << endl;
	
	cout << "Manual setting of m1b + output with elem(i,j)" << endl;
	m1b.elem(0,0) = 1;
	cout << m1b.elem(0,0) << " ";
	m1b.elem(0,1) = 2;
	cout << m1b.elem(0,1) << endl;
	m1b.elem(1,0) = 3;
	cout << m1b.elem(1,0) << " ";
	m1b.elem(1,1) = 4;
	cout << m1b.elem(1,1) << endl << endl;
	
	cout << "Overloaded << output for m1 " << endl << m1 << endl;
	cout << "Overloaded << output for m1b " << endl << m1a << endl;
	cout << "Overloaded << output for m1c " << endl << m1b << endl;
	
    
    // Test 2
    // * Create an object of type My_matrix, called m2, using (default)
    //   constructor
    // * Open an input file containing a matrix (row by row)
    // * Initialize m2 by reading from the input file using
    //   the operator >>
    // * Open an output file (can be empty)
    // * Write m2 to the output file using the operator <<
	
// Opens and creates streams for in/output files
  
	cout << endl << "Test 2: " << endl;
	
	// int >> and << test
	
	double temp = 0;
	int ntemp = 0, mtemp = 0;
	
	//opens and test in/out streams
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
	
	// takes in n and m values from input file
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
	
	My_matrix<int> m2(ntemp,mtemp);
	
	//writes from input file to m2
	infs >> m2;
	
	//writes m2 to output file
	outfs << m2.number_of_rows() << " " << m2.number_of_columns() << endl << m2;
	cout << endl << "Data sent to output file: " << endl << m2 << endl;
	
	// double >> and << test
	
	ifstream infsa("test_inputa.txt");
	ofstream outfsa("test_outputa.txt");
	if (!infs.is_open()) {
	  cerr << "Failed to open in file: " << endl;
	  return 1;
	}
	if (!outfs.is_open()) {
	  cerr << "Failed to open out file: " << endl;
	  return 1;
	}
	
	for (int i = 0; i < 2; ++i ) {
	  if (infsa >> temp){
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
	
	My_matrix<double> m2a(ntemp,mtemp);
	
	infsa >> m2a;
	
	outfsa << m2a.number_of_rows() << " " << m2a.number_of_columns() << endl << m2a;
	cout << endl << "Data sent to output file: " << endl << m2a << endl;
	
	// long >> and << test
	
	ifstream infsb("test_inputb.txt");
	ofstream outfsb("test_outputb.txt");
	if (!infsb.is_open()) {
	  cerr << "Failed to open in file: " << endl;
	  return 1;
	}
	if (!outfsb.is_open()) {
	  cerr << "Failed to open out file: " << endl;
	  return 1;
	}
	
	for (int i = 0; i < 2; ++i ) {
	  if (infsb >> temp){
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
	
	My_matrix<long> m2b(ntemp,mtemp);
	
	infsb >> m2b;
	
	outfsb << m2b.number_of_rows() << " " << m2b.number_of_columns() << endl << m2b;
	cout << endl << "Data sent to output file: " << endl << m2b << endl;
	

	
    // Test 3
    // * Use the copy constructor to make a copy of m1 called m3
    // * Apply the copy assignment to m1 called m4
    // * Display m3 and m4 on the screen using the operator <<
	
	cout << "Test 3: " << endl;
	
	// int copy construct and assign test
	
	cout << "m3 copy constructed from m1" << endl;
	My_matrix<int> m3(m1);
	cout << "m3:" << endl << m3 << endl;
	cout << "m1:" << endl << m1 << endl;
	cout << "m4 copy assigned from m3" << endl;
	My_matrix<int> m4;
	m4 = m3;
	cout << "m4:" << endl << m4 << endl;
	
	// double copy construct and assign test
	
	cout << "m3a copy constructed from m1" << endl;
	My_matrix<double> m3a(m1a);
	cout << "m3a:" << endl << m3a << endl;
	cout << "m1a:" << endl << m1a << endl;
	cout << "m4a copy assigned from m3" << endl;
	My_matrix<double> m4a;
	m4a = m3a;
	cout << "m4a:" << endl << m4a << endl;
	
	// long copy construct and assign test
	
	cout << "m3b copy constructed from m1" << endl;
	My_matrix<long> m3b(m1b);
	cout << "m3b:" << endl << m3b << endl;
	cout << "m1b:" << endl << m1b << endl;
	cout << "m4b copy assigned from m3" << endl;
	My_matrix<long> m4b;
	m4b = m3b;
	cout << "m4b:" << endl << m4b << endl;
	
    // Test 4
    // * Test the matrix multiplication operator (operator*)
    // * Apply the multiplication operator to valid and invalid cases
    // * Display the resulting matrix and its number of rows and columns

    cout << "Test 4: " << endl;
	
	// int *operator
	
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
	
	My_matrix<int> m5(ntemp,mtemp);
	
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
	
	My_matrix<int> m6(ntemp,mtemp);
	
	infs_4b >> m6;
	
	cout << "m6 from file:" << endl << m6 << endl;
	
	My_matrix<int> m7 = m5 * m6;
	
	cout << "m7 = m5 * m6: " << endl << m7 << endl;
	
	// double *operator
	
	ifstream infs_4aa("test_input1a.txt");
	ifstream infs_4ba("test_input2a.txt");
	if (!infs_4aa.is_open()) {
	  cerr << "Failed to open in file: " << endl;
	  return 1;
	}
	if (!infs_4ba.is_open()) {
	  cerr << "Failed to open in file: " << endl;
	  return 1;
	}
	
	temp = 0;
	ntemp = 0;
	mtemp = 0;
	
	for (int i = 0; i < 2; i++ ) {
	  if (infs_4aa >> temp){
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
	
	My_matrix<double> m5a(ntemp,mtemp);
	
	infs_4aa >> m5a;
	
	cout << "m5a from file:" << endl << m5a << endl;
	
	temp = 0;
	ntemp = 0;
	mtemp = 0;
	
	for (int i = 0; i < 2; i++ ) {
	  if (infs_4ba >> temp){
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
	
	My_matrix<double> m6a(ntemp,mtemp);
	
	infs_4ba >> m6a;
	
	cout << "m6a from file:" << endl << m6a << endl;
	
	My_matrix<double> m7a = m5a * m6a;
	
	cout << "m7a = m5a * m6a:" << endl << m7a << endl;
	
	// long *operator
	
	ifstream infs_4ab("test_input1b.txt");
	ifstream infs_4bb("test_input2b.txt");
	if (!infs_4ab.is_open()) {
	  cerr << "Failed to open in file: " << endl;
	  return 1;
	}
	if (!infs_4bb.is_open()) {
	  cerr << "Failed to open in file: " << endl;
	  return 1;
	}
	
	temp = 0;
	ntemp = 0;
	mtemp = 0;
	
	for (int i = 0; i < 2; ++i ) {
	  if (infs_4ab >> temp){
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
	
	My_matrix<long> m5b(ntemp,mtemp);
	
	infs_4ab >> m5b;
	
	cout << "m5b from file:" << endl << m5b << endl;
	
	temp = 0;
	ntemp = 0;
	mtemp = 0;
	
	for (int i = 0; i < 2; ++i ) {
	  if (infs_4bb >> temp){
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
	
	My_matrix<long> m6b(ntemp,mtemp);
	
	infs_4bb >> m6b;
	
	cout << "m6b from file:" << endl << m6b << endl;
	
	My_matrix<long> m7b = m5b * m6b;
	
	cout << "m7b = m5b * m6b:" << endl << m7b << endl;
	
	// incompatible matrices for *operator test, should give error as 6a is not a square matrix.
	try{
	cout << "m6:" << endl << m6 << endl;
	
	cout << "m10 = m6 + m6:" << endl;
	My_matrix<int> m10 = m6 * m6;
	cout << m10 << endl;
	
	} catch(exception &error){
    cerr << "Error: " << error.what() << endl;
    }


    // Test 5
    // * Test the matrix addition operator (operator+)
    // * Apply the multiplication operator to valid and invalid cases
    // * Display the resulting matrix and its number of rows and columns
	
	cout << endl << "Test 5: " << endl;
	
	// int +operator test
	
	cout << "m1:" << endl << m1 << endl;
	
	My_matrix<int> m8 = m1 + m1;
	cout << "m8 = m1 + m1: " << endl << m8 << endl;
	
	// double +operator test
	
	cout << "m1a:" << endl << m1 << endl;
	
	My_matrix<double> m8a = m1a + m1a;
	cout << "m8a = m1a + m1a: " << endl << m8a << endl;
	
	// long +operator test
	
	cout << "m1b:" << endl << m1b << endl;
	
	My_matrix<long> m8b = m1b + m1b;
	cout << "m8b = m1b + m1b: " << endl << m8b << endl;
	
	// Differently sized matrices, should give error
	try{
	cout << "m1:" << endl << m1 << endl;
	cout << "m2:" << endl << m2 << endl;
	
	cout << "m9 = m1 + m2: " << endl;
	My_matrix<int> m9 = m1 + m2;
	cout << m8 << endl;
	
	} catch(exception &error){
    cerr << "Error: " << error.what() << endl;
    }


  } catch(exception &error){
    cerr << "Error: " << error.what() << endl;
  }
  return 0;
}
