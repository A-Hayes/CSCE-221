#include <iostream>
using namespace std;

int maxRecur(int[], int, int, int);

int main(){
  // Test 1: Values 1-10, chosen randomly, used for testing
  int arr1[10] = {7,1,5,2,8,6,10,3,9,4};
  cout << "Max 1: " << maxRecur(arr1, sizeof(arr1) / sizeof(arr1[0]), 0, 0) << endl;

  // Test 2: Randomly generated ints from range 1-100, from random.org
  int arr2[10] = {41,6,8,14,56,76,86,84,21,94};
  cout << "Max 2: " << maxRecur(arr2, sizeof(arr2) / sizeof(arr2[0]), 0, 0) << endl;

  // Test 3: Randomly generated ints from range 1-1000, from random.org
  int arr3[10] = {848,895,67,930,723,392,139,174,889,863};
  cout << "Max 3: " << maxRecur(arr3, sizeof(arr3) / sizeof(arr3[0]), 0, 0) << endl;

}

// note: passing arrSize as argument reduces amount of total calculations,
//       also was causing issue when calculated inside of maxRecur.
int maxRecur(int* a, int arrSize, int index, int max){
  cout << "Current Max: " << max << endl;
  cout << "Remaining Elements: ";
  // this loop does not count against the question, as it is only for testing/demonstration purposes
  for(int i = index; i < arrSize; i++){
    cout << a[i] << " ";
  }
  cout << endl;

  // productive code
  if(index == arrSize){
    return max;
  } else {
    int newMax = (a[index] > max) ? a[index] : max;
    return maxRecur(a, arrSize, index + 1, newMax);
  }
}
