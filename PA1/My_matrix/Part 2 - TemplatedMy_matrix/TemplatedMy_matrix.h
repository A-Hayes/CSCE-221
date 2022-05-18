#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

// Definitions of user defined type exceptions 
struct invalid_input : public exception {
  virtual const char* what() const throw()
  { return "Invalid matrix input"; }
};

struct incompatible_matrices : public exception {
  virtual const char* what() const throw()
  { return "Incompatible matrices"; }
};

template <typename T>
class My_matrix{
	
  //member variables
  int n, m;
  T **ptr;
  //void allocate_memory();  // optional
  
public:	
  //member functions
  My_matrix();  // default constructor
  My_matrix(int n1, int m1); // parameter constructor
  ~My_matrix(); // destructor
  My_matrix(const My_matrix<T>& mat); // copy constructor
  //My_matrix(My_matrix&& mat);  // move constructor (optional)
  My_matrix& operator=(const My_matrix<T>& mat); //copy assignment operator
  //My_matrix& operator=(My_matrix&& mat); // move assignment operator (optional)
  int number_of_rows() const; 
  int number_of_columns() const;
  T* operator()(int i) const; // overloaded to access to ith row
  T& operator()(int i, int j); // overloaded to access (i,j) element
  T operator()(int i, int j) const; // overloaded to access (i,j) element
  T elem(int i, int j) const; // overloaded to access (i,j) element
  T& elem(int i, int j); // overloaded to access (i,j) element
};

// see the handout for the description of these operators
template <typename T>
ostream& operator<<(ostream& out, const My_matrix<T>& mat);
template <typename T>
istream& operator>>(istream& in, My_matrix<T>& mat);
template <typename T>
My_matrix<T> operator+(const My_matrix<T>& mat1, const My_matrix<T>& mat2);
template <typename T>
My_matrix<T> operator*(const My_matrix<T>& mat1, const My_matrix<T>& mat2);



//
//     END OF HEADER SECTION / START OF FUNCTIONS
// 



// default constructor (for empty matrix)
template <typename T>
My_matrix<T>::My_matrix() : n(0), m(0), ptr(nullptr)
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
template <typename T>
My_matrix<T>::My_matrix(int n1, int m1)
{
  if(n1 > 0 && m1 > 0){
    this->n = n1;
    this->m = m1;
  }else{
	throw out_of_range("Indexes cannot be negative");
  }
  
  ptr = new T*[n1];
  for(int i = 0; i < n1; i++){
	ptr[i] = new T[m1];
  }
}

//copy constructor
template <typename T>
My_matrix<T>::My_matrix(const My_matrix& mat) 
{
  n = mat.n; 
  m = mat.m;
  
  ptr = new T*[n];
  for(int i = 0; i < n; i++){
	ptr[i] = new T[m];
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

template <typename T>
My_matrix<T>::~My_matrix()
{
  for(int i = 0; i < n; i++){
	delete [] ptr[i];
  }
  delete [] ptr;
  ptr = NULL;
}

// Copy Assignment operator
template <typename T>
My_matrix<T>& My_matrix<T>::operator=(const My_matrix& mat)
{
  if(this == &mat){
	return *this;
  }
  
  n = mat.n; 
  m = mat.m;
  
  ptr = new T*[n];
  for(int i = 0; i < n; i++){
	ptr[i] = new T[m];
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

template <typename T>
int My_matrix<T>::number_of_rows() const
{
  return this->n;
}

template <typename T>
int My_matrix<T>::number_of_columns() const
{
  return this->m;
}

template <typename T>
T* My_matrix<T>::operator()(int i) const
{
  return this->ptr[i];
}

template <typename T>
T My_matrix<T>::operator()(int i, int j) const
{
  return this->ptr[i][j];
}

template <typename T>
T& My_matrix<T>::operator()(int i, int j)
{
  return this->ptr[i][j];
}

template <typename T>
T My_matrix<T>::elem(int i, int j) const
{
  if (i < 0 || i >= n) throw out_of_range("Out of range");
  if (j < 0 || j >= m) throw out_of_range("Out of range");
  
  return ptr[i][j];
}

template <typename T>
T& My_matrix<T>::elem(int i, int j)
{
  if (i < 0 || i >= n) throw out_of_range("Out of range");
  if (j < 0 || j >= m) throw out_of_range("Out of range");
  
  return ptr[i][j];
}

template <typename T>
ostream& operator<<(ostream& out, const My_matrix<T>& mat)
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
template <typename T>
istream& operator>>(istream& in, My_matrix<T>& mat)
{
  T temp = 0;
  for (int i = 0; i < mat.number_of_rows(); i++ ) {
		for (int j = 0; j < mat.number_of_columns(); j++ ) {
			if (in >> temp){
			  mat.elem(i,j) = temp;
			} else {
			  cout << "Error: Not enough data." << endl;
			  break;
			}
		}
    }
	return in;
}

template <typename T>
My_matrix<T> operator+(const My_matrix<T>& mat1, const My_matrix<T>& mat2)
{
  if( mat1.number_of_columns() != mat2.number_of_columns() || mat1.number_of_rows() != mat2.number_of_rows() ){ 
    throw incompatible_matrices();
  }
  
  My_matrix<T> mat3add(mat1.number_of_rows(), mat1.number_of_columns());
  
  for(int i = 0; i < mat1.number_of_rows(); i++){
	for(int j = 0; j < mat1.number_of_columns(); j++){
	  mat3add.elem(i,j) = mat1.elem(i,j) + mat2.elem(i,j);
	}
  }
  
  return mat3add;
}

template <typename T>
My_matrix<T> operator*(const My_matrix<T>& mat1, const My_matrix<T>& mat2)
{
  if( mat1.number_of_columns() != mat2.number_of_rows() ){ 
	throw incompatible_matrices();
  }
  
  My_matrix<T> mat3mult(mat1.number_of_rows(), mat2.number_of_columns());
  
  T temp = 0;
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
