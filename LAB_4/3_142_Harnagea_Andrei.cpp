#include<iostream>

using namespace std;
struct Node {

  int Data;
  Node * Next;

}* stiva = NULL;

void push(int Val) {
  Node * p = new Node[sizeof(Node) + 1];
  if (p == NULL)
    cout << "Overflow!" << endl;
  else {
    p -> Data = Val;
    p -> Next = stiva;
    stiva = p;

  }
}

void pop() {
  int X;
  Node * p;
  if (stiva == NULL)
    cout << "Underflow!" << endl;
  else {
    p = stiva;
    X = p -> Data;
    stiva = stiva -> Next;
    delete p;

  }
}

int main() {
  Node * p = new Node();
  int pereche[101], n, i;

  cin >> n;

  for (i = 0; i < n; i++) {
    cin >> pereche[i];

    if (stiva == NULL)
      push(pereche[i]);
    else {
      if (pereche[i] == stiva -> Data)
        pop();
      else
        push(pereche[i]);
    }
  }

  if (stiva == NULL)
    cout << "E ok";
  else
    cout << "Nu e ok";

  return 0;
}
