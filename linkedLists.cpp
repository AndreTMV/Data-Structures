#include <iostream>
using std::cout, std::endl;

struct Node {
  int value;
  Node *next;
};

void print(Node *head) {
  while (head != NULL) {
    cout << head->value << endl;
    head = head->next;
  }
}

void insertAtTheFront(Node **head, int value) {}

int main() {
  Node *head = new Node();
  Node *first = new Node();
  Node *second = new Node();
  head->value = 39;
  head->next = first;
  first->value = 40;
  first->next = second;
  second->value = 50;
  second->next = NULL;
  print(head);
}
