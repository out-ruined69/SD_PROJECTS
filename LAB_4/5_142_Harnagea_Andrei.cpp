#include <iostream>

using namespace std;
struct node {
  int data;
  node * next;
};

int pop(node * & Front, node * & Rear) {
  if (Front == NULL)
    cout << "Underflow";
  else {
    int x = Front -> data;
    node * temp = Front;
    Front = Front -> next;
    delete temp;
    if (Front == NULL)
      Rear = NULL;
  }
}
void push(node * & Front, node * & Rear, int dat) {
  node * p = new node;
  if (p == NULL)
    cout << "Overflow";
  else {
    p -> data = dat;
    p -> next = NULL;
    if (Rear == NULL)
      Front = p;
    else
      Rear -> next = p;
    Rear = p;
  }
}

int main() {
  node * Rear = NULL;
  node * Front = NULL;
  push(Front, Rear, 3);
  push(Front, Rear, 6);
  push(Front, Rear, 9);
  push(Front, Rear, 2);
  push(Front, Rear, 4);
  push(Front, Rear, 7);
  push(Front, Rear, 1);
  push(Front, Rear, 8);
  push(Front, Rear, 5);
  node * p = new node();
  p = Front;

  while (p != NULL) {
    cout << p -> data << " ";
    p = p -> next;
  }

  node * q1front = NULL;
  node * q1rear = NULL;
  node * q2front = NULL;
  node * q2rear = NULL;
  node * q3front = NULL;
  node * q3rear = NULL;

  p = Front;
  bool ok = 1;
  while (p != NULL && ok == 1) {
    if (q1front == NULL) {
      push(q1front, q1rear, p -> data);
    } else
    if (q1rear -> data < p -> data)
      push(q1front, q1rear, p -> data);
    else
    if (q2front == NULL) {
      push(q2front, q2rear, p -> data);
    } else
    if (q2rear -> data < p -> data)
      push(q2front, q2rear, p -> data);
    else
    if (q3front == NULL) {
      push(q3front, q3rear, p -> data);
    } else
    if (q3rear -> data < p -> data)
      push(q3front, q3rear, p -> data);
    else
      ok = 0;

    p = p -> next;
  }

  cout << endl;

  node * finalrear = NULL;
  node * finalfront = NULL;
  node * finalrear2 = NULL;
  node * finalfront2 = NULL;
  node * f = NULL;

  if (ok == 0)
    cout << "Nu!";
  else {
    node * q1 = new node();
    node * q2 = new node();
    node * q3 = new node();
    q1 = q1front;
    q2 = q2front;
    q3 = q3front;

    while (q1 != NULL && q2 != NULL) {
      if (q1 -> data > q2 -> data) {
        push(finalfront, finalrear, q2 -> data);
        q2 = q2 -> next;
      } else {
        push(finalfront, finalrear, q1 -> data);
        q1 = q1 -> next;
      }
    }

    while (q1 != NULL) {
      push(finalfront, finalrear, q1 -> data);
      q1 = q1 -> next;
    }

    while (q2 != NULL) {
      push(finalfront, finalrear, q2 -> data);
      q2 = q2 -> next;
    }

    //avem finalfront1
    f = finalfront;

    while (f != NULL && q3 != NULL) {
      if (f -> data < q3 -> data) {
        push(finalfront2, finalrear2, f -> data);
        f = f -> next;
      } else {
        push(finalfront2, finalrear2, q3 -> data);
        q3 = q3 -> next;
      }
    }

    while (f != NULL) {
      push(finalfront2, finalrear2, f -> data);
      f = f -> next;
    }

    while (q3 != NULL) {
      push(finalfront2, finalrear2, q3 -> data);
      q3 = q3 -> next;
    }

  }

  p = finalfront2;
  while (p != NULL) {
    cout << p -> data << " ";
    p = p -> next;
  }

  return 0;
}
