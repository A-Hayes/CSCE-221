//
//   Test code for CSCE-221-506 - HW1 - Problem 4
//
using namespace std;
#include <iostream>
#include <vector>

// Problem 4: Generic binary search on sorted vector<T>
template <typename T>
int GenBinSearch(vector<T> a, T x){
	int bot = 0, top = a.size()-1, mid = (a.size()-1) / 2;
	
	// early return if element is not within vector's sorted range
	if(x < a[0] || x > a[a.size()-1]){
		return -1;
	}
	
	// main sort loop
	while(top > bot){
		mid = bot + ( (top - bot) / 2 );
		if(x == a[mid]){
			return mid;
		}else if(x > a[mid]){
			bot = mid+1;
		}else{
			top = mid-1;
		}
	}
	return -1;
}

int main(){
	vector<int> a = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
	cout << "Search for 13: " << a[GenBinSearch(a,13)] << endl;
	vector<double> b = {1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0};
	cout << "Search for 1.3: " << b[GenBinSearch(b,1.3)] << endl;
}