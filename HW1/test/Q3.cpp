//
//   Test code for CSCE-221-506 - HW1 - Problem 3
//
using namespace std;
#include <iostream>
#include <vector>

// Problem 3; Takes in vector, returns true if any 2 values in array have odd product
// Most likely more efficient way to do this, haven't learned yet 
bool oddCheck(vector<int> a){
	for(int i = 0; i < a.size() - 1; i++){
		for(int j = i + 1; j < a.size(); j++){
			if( ( (a[i] * a[j]) % 2 ) != 0 ){
				return true;
			}
		}
	}
	return false;
}

int main(){
	vector<int> a = {1,2,8,4,6,5};
	cout << "oddCheck a?: " << oddCheck(a) << endl; 
	vector<int> b = {1,2,8,4,6};
	cout << "oddCheck b?: " << oddCheck(b) << endl; 
}