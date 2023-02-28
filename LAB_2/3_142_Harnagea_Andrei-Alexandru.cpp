#include<iostream>

#include<math.h>

using namespace std;

struct Node {
  int Grade, Coef;
  Node * Next;
};

void afisare(Node * p) {
  Node * nod = NULL;
  nod = p;
  while (nod != NULL) {
    cout << "Grad " << nod -> Grade << " Coef " << nod -> Coef << " " << endl;
    nod = nod -> Next;
  }
}

void scalar_inm(Node * p) {
  Node * nod = NULL;
  int scl;
  cin >> scl;
  nod = p;
  while (nod != NULL) {
    cout << nod -> Coef * scl << " grad " << nod -> Grade << endl;
    nod = nod -> Next;
  }

}

void fdex(Node * p) {
  Node * nod = NULL;
  int x;
  cin >> x;
  int rez = 0;

  nod = p;
  while (nod != NULL) {
    rez = rez + pow(x, nod -> Grade) * nod -> Coef;
    nod = nod -> Next;
  }
  cout << rez << endl;
}

void suma(Node * p, Node * q) {
  Node * n1 = NULL;
  Node * n2 = NULL;

  n1 = p;
  n2 = q;
  int i = 0;

  while (n1 != NULL && n2 != NULL) {
    cout << "Gradul " << i << " Coef " << n1 -> Coef + n2 -> Coef << endl;
    i++;
    n1 = n1 -> Next;
    n2 = n2 -> Next;
  }

  while (n1 != NULL) {
    cout << "Gradul " << i << " Coef " << n1 -> Coef << endl;
    n1 = n1 -> Next;
  }

  while (n2 != NULL) {
    cout << "Gradul " << i << " Coef " << n2 -> Coef << endl;
    n2 = n2 -> Next;
  }
}

int i;
int main() {
  Node * p = NULL;
  Node * q = NULL;
  Node * nod = NULL;
  Node * pred = NULL;
  int n;
  cout << "n ";
  cin >> n;

  for (i = 0; i < n; i++) {
    nod = new Node();
    cout << "Grad " << i << " ";
    nod -> Grade = i;
    cout << "Coef ";
    cin >> nod -> Coef;
    nod -> Next = NULL;
    if (p == NULL) {
      p = nod;
      pred = p;
    } else {
      pred -> Next = nod;
      pred = nod;
    }

  }

  int m;
  cout << "m ";
  cin >> m;

  for (i = 0; i < m; i++) {
    nod = new Node();
    cout << "Grad " << i << " ";
    cout << "Coef ";
    cin >> nod -> Coef;
    nod -> Next = NULL;
    if (q == NULL) {
      q = nod;
      pred = q;
    } else {
      pred -> Next = nod;
      pred = nod;
    }

  }

  scalar_inm(p);
  fdex(p);
  suma(p, q);
  return 0;

}
