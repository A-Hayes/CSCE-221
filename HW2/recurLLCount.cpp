#include <iostream>
#include "LinkedList.h"
using namespace std;

int listCount(Node*, int);

int main(){
  LinkedList ll("Test List");

  for(int i = 1; i <= 15; i++){
    ll.insert_back(i);
  }

  cout << listCount(ll.get_head(), 0) << endl;

  return 0;
}

int listCount(Node* cur, int count){
  count++;
  if(cur->next == nullptr){
    cout << count << " ";
    return count;
  } else {
    cout << count << " ";
    return listCount(cur->next, count);
  }
}
