#include <queue>
#include <iostream>
using namespace std;

class newStack{
private:
  queue<int> mainQ;
  queue<int> altQ;
  int size = 0;
public:
  void stackPush(int input);
  int stackPop();
  int getSize();
};

void newStack::stackPush(int a){
  size++;
  altQ.push(a);
  while(!mainQ.empty()){
    altQ.push(mainQ.front());
    mainQ.pop();
  }
  queue<int> tempQ = mainQ;
  mainQ = altQ;
  altQ = tempQ;
}

int newStack::stackPop(){
  size--;
  int temp = mainQ.front();
  mainQ.pop();
  return temp;
}

int newStack::getSize(){
  return size;
}

int main(){
  newStack a;

  for(int i = 1; i <= 10; i++){
    a.stackPush(i);
  }

  cout << "Popped elements: ";
  while(a.getSize() != 0){
    cout << a.stackPop() << " ";
  }
  cout << endl << endl;


  return 0;
}
