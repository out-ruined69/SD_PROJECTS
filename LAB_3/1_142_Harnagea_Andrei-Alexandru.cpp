#include<iostream>

using namespace std;
struct Node {
  int Data;
  Node * Next;
};

void citire(Node * & head) {
  int n, i;
  cin >> n;
  Node * nod = NULL;
  Node * p = NULL;
  Node * pred = NULL;
  //Citire + ordonare
  for (i = 0; i < n; i++) {

    p = new Node();
    cin >> p -> Data;
    p -> Next = NULL;

    if (i == 0)
      head = p;
    else {
      if (head -> Data > p -> Data) {
        p -> Next = head;
        head = p;
      } else {
        nod = head -> Next;
        pred = head;

        while (nod != NULL) {

          if (p -> Data < nod -> Data) {

            pred -> Next = p;
            p -> Next = nod;
            break;

          }
          pred = nod;
          nod = nod -> Next;

        }

        if (nod == NULL)
          pred -> Next = p;

      }

    }
  }
}

void afisare(Node * head) {
  Node * p = NULL;
  p = head;
  while (p != NULL) {
    cout << p -> Data << " ";
    p = p -> Next;

  }
  cout << endl;
}

void eliminare(Node * & head) {
  Node * p = NULL;

  Node * nod = NULL;
  Node * pred = NULL;
  int el;
  cin >> el;
  pred = NULL;
  p = head;
  while (p != NULL && el != p -> Data) {
    pred = p;
    p = p -> Next;
  }
  if (p == NULL)
    cout << "nu se afla in lista\n";
  else {
    if (pred == NULL) {
      head = p -> Next;
      delete p;
    } else {
      pred -> Next = p -> Next;
      delete p;
    }
  }
}

void stergere_lista(Node * & head) {
  Node * x;

  while (head != NULL) {
    x = head -> Next;
    delete head;
    head = x;
  }
}

int main() {

  int n, i;

  Node * p = NULL;
  Node * head = NULL;
  Node * nod = NULL;
  Node * pred = NULL;

  citire(head);

  afisare(head);

  eliminare(head);

  afisare(head);

  stergere_lista(head);

  return 0;
}
