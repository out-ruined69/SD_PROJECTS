#include<iostream>

using namespace std;

struct Node {
  int Data;
  Node * Next;
};

Node * spate;
Node * fata;

int pop() {
  if (fata == NULL)
    cout << "Underflow!" << endl;
  else {
    int x = fata -> Data;
    Node * aux = fata;
    fata = fata -> Next;
    delete aux;
    if (fata == NULL)
      spate = NULL;
  }
}
void push(int val) {
  Node * p = new Node;
  if (p == NULL)
    cout << "Overflow!" << endl;
  else {
    p -> Data = val;
    p -> Next = NULL;
    if (spate == NULL)
      fata = p;
    else
      spate -> Next = p;
    spate = p;
  }
}

int main() {
  int aux, n, apa = 0, h1 = 0, h2 = 0;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> aux;
    push(aux);
  }

  while (fata != spate) {
    if (fata -> Data < spate -> Data) {
      if (fata -> Data > h1)
        h1 = fata -> Data;
      else
        apa += h1 - fata -> Data;
      pop();
    } else {
      if (spate -> Data <= h2)
        apa += h2 - spate -> Data;
      else
        h2 = spate -> Data;
      Node * p1;
      Node * p2;
      p2 = fata;

      while (p2 != spate) {
        p1 = p2;
        p2 = p2 -> Next;
      }
      spate = p1;
    }
  }
  cout << apa;
  return 0;
}
