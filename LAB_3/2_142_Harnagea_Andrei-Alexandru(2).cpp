#include<iostream>

using namespace std;

struct Node {

  int Data;
  Node * Next;

};

int main() {

  Node * head1 = NULL;
  Node * head2 = NULL;
  Node * nod = NULL;
  Node * pred = NULL;
  int n, i, m;

  cin >> n;
  for (i = 0; i < n; i++) {

    nod = new Node();
    cin >> nod -> Data;
    nod -> Next = NULL;
    if (head1 == NULL) {

      head1 = nod;
      pred = head1;

    } else

    {

      pred -> Next = nod;
      pred = nod;

    }
  }

  cin >> n;
  for (i = 0; i < n; i++) {

    nod = new Node();
    cin >> nod -> Data;
    nod -> Next = NULL;
    if (head2 == NULL) {

      head2 = nod;
      pred = head2;

    } else

    {

      pred -> Next = nod;
      pred = nod;

    }
  }

  nod = head1;
  int nr1 = 0, l = 1;

  while (nod != NULL) {
    nr1 = nod -> Data * l + nr1;
    l = l * 10;
    nod = nod -> Next;
  }

  nod = head2;
  int nr2 = 0;
  l = 1;

  while (nod != NULL) {
    nr1 = nr1 + l * nod -> Data;
    l = l * 10;
    nod = nod -> Next;
  }

  cout << nr1;

  return 0;
}
