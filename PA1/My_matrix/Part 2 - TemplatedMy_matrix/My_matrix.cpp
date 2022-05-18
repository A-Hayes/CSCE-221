/* 
Implementation of the class My_matrix
*/
#include "My_matrix.h"
#include <stdexcept>
using namespace std;

// default constructor (for empty matrix)
My_matrix::My_matrix() : n(0), m(0), ptr(nullptr)
{
  //no contents
}

/* 
void My_matrix::allocate_memory()
{
  // currently unused
} 
*/

//usable constructor, n1 = rows, m1 = columns for new matrix
My_matrix::My_matrix(int n1, int m1)
{
  if(n1 > 0 && m1 > 0){
    this->n = n1;
    this->m = m1;
  }else{
	throw out_of_range("Indexes cannot be negative");
  }
  
  ptr = new int*[n1];
  for(int i = 0; i < n1; i++){
	ptr[i] = new int[m1];
  }
}

//copy constructor
My_matrix::My_matrix(const My_matrix& mat) 
{
  n = mat.n; 
  m = mat.m;
  
  ptr = new int*[n];
  for(int i = 0; i < n; i++){
	ptr[i] = new int[m];
  }

  for(int i = 0; i < n; i++){
	for(int j = 0; j <  m; j++){
	  this->elem(i,j) = mat.elem(i,j);
    }
  }
}

/* 
// move constructor (optional)
My_matrix::My_matrix(My_matrix&& mat)
{
  // add your code here
} 
*/

My_matrix::~My_matrix()
{
  for(int i = 0; i < n; i++){
	delete [] ptr[i];
  }
  delete [] ptr;
  ptr = NULL;
}

// Copy Assignment operator
My_matrix& My_matrix::operator=(const My_matrix& mat)
{
  if(this == &mat){
	return *this;
  }
  
  /* for(int i = 0; i < n; i++){
	delete []ptr[i];
  }
  delete []ptr;
  ptr = NULL; */
  
  n = mat.n; 
  m = mat.m;
  
  ptr = new int*[n];
  for(int i = 0; i < n; i++){
	ptr[i] = new int[m];
  }
  
  for(int i = 0; i < n; i++){
	for(int j = 0; j <  m; j++){
	  this->elem(i,j) = mat.elem(i,j);
    }
  }
  
  return *this;
}

/* 
// move assignment operator (optional)
My_matrix& My_matrix::operator=(My_matrix&& mat)
{
  // add your code here
} 
*/

int My_matrix::number_of_rows() const
{
  return this->n;
}

int My_matrix::number_of_columns() const
{
  return this->m;
}

int* My_matrix::operator()(int i) const
{
  return this->ptr[i];
}

int My_matrix::operator()(int i, int j) const
{
  return this->ptr[i][j];
}

int& My_matrix::operator()(int i, int j)
{
  return this->ptr[i][j];
}

int My_matrix::elem(int i, int j) const
{
  if (i < 0 || i >= n) throw out_of_range("Out of range");
  if (j < 0 || j >= m) throw out_of_range("Out of range");
  
  return ptr[i][j];
}

int& My_matrix::elem(int i, int j)
{
  if (i < 0 || i >= n) throw out_of_range("Out of range");
  if (j < 0 || j >= m) throw out_of_range("Out of range");
  
  return ptr[i][j];
}

ostream& operator<<(ostream& out, const My_matrix& mat)
{
  out << flush;
  for(int i = 0; i < mat.number_of_rows(); i++){
	for(int j = 0; j < mat.number_of_columns(); j++){
	  out << mat.elem(i,j) << " ";
    }
	out << endl;
  }
  return out;
}

//overloaded input operator, requires dimensions of mat to be set before calling
istream& operator>>(istream& in, My_matrix& mat)
{
  int temp = 0;
  for (int i = 0; i < mat.number_of_rows(); i++ ) {
		for (int j = 0; j < mat.number_of_columns(); j++ ) {
			if (in >> temp){
			  mat.elem(i,j) = temp;
			} else {
			  cout << "Error: not enough data." << endl;
			  break;
			}
		}
    }
	return in;
}

My_matrix operator+(const My_matrix& mat1, const My_matrix& mat2)
{
  if( mat1.number_of_columns() != mat2.number_of_columns() || mat1.number_of_rows() != mat2.number_of_rows() ){ 
    throw incompatible_matrices();
  }
  
  My_matrix mat3add(mat1.number_of_rows(), mat1.number_of_columns());
  
  for(int i = 0; i < mat1.number_of_rows(); i++){
	for(int j = 0; j < mat1.number_of_columns(); j++){
	  mat3add.elem(i,j) = mat1.elem(i,j) + mat2.elem(i,j);
	}
  }
  
  return mat3add;
}

My_matrix operator*(const My_matrix& mat1, const My_matrix& mat2)
{
  if( mat1.number_of_columns() != mat2.number_of_rows() ){ 
	throw incompatible_matrices();
  }
  
  My_matrix mat3mult(mat1.number_of_rows(), mat2.number_of_columns());
  
  int temp = 0;
  for(int i = 0; i < mat3mult.number_of_rows(); i++){
	for(int j = 0; j < mat3mult.number_of_columns(); j++){
	  for(int k = 0; k < mat1.number_of_columns(); k++){
		temp = temp + ( mat1.elem(i,k) * mat2.elem(k,j) );
	  }
	  mat3mult.elem(i,j) = temp;
	  temp = 0;
	}
  }
  
  return mat3mult;
}
