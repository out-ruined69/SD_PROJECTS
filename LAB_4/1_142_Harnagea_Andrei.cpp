#include<iostream>
using namespace std;

struct Node {

  int data;
  Node * next;
  int prt;

}* fata = NULL, * spate = NULL;

void push(int val, int prioritate) {
  Node * p = new Node;
  if (p == NULL)
    cout << "Overflow!" << endl;
  else {
    p -> prt = prioritate;
    p -> data = val;
    p -> next = NULL;

    if (spate == NULL)
      fata = p;
    else {
      if (fata -> prt > prioritate) {
        p -> next = fata;
        fata = p;
      } else {
        Node * aux = fata;
        while (aux -> next != NULL && aux -> next -> prt <= prioritate)
          aux = aux -> next;
        p -> next = aux -> next;
        aux -> next = p;
        spate -> next = p;
      }
    }

    spate = p;
  }

}

void pop() {
  if (fata = NULL)
    cout << "Underflow!" << endl;
  else {
    int val = fata -> data;
    Node * aux = fata;
    fata = fata -> next;
    delete aux;
    if (fata == NULL)
      spate = NULL;
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x;
    cin >> y;
    push(x, y);
  }

  Node * p = NULL;
  p = fata;
  while (p != NULL) {
    cout << p -> data << " ";
    p = p -> next;
  }

  return 0;
}
