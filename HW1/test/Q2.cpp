//
//   Test code for CSCE-221-506 - HW1 - Problem 2
//
using namespace std;
#include <iostream>
#include <vector>

// Problem 2: Takes in 2 vector<int>, returns vector<int> where c[i] = a[i] * b[i]
vector<int> MultVectors(vector<int> a, vector<int> b){
	vector<int> c;
	for(int i = 0; i < a.size(); i++){
		c.push_back(a[i]*b[i]);
	}
	return c;
}

int main(){
	vector<int> a = {1, 2, 3, 4};
	vector<int> b = {1, 2, 3, 4};
	vector<int> c = MultVectors(a,b);
	
	cout << "a: " << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << endl;
	cout << "b: " << b[0] << " " << b[1] << " " << b[2] << " " << b[3] << endl;
	cout << "c: " << c[0] << " " << c[1] << " " << c[2] << " " << c[3] << endl;
}