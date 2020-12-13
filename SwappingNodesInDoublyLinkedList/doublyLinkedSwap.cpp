#include "doublyLinkedSwap.h"

int main()
{
  return 0;
}


void swapWithNext(Node * p)
{
  if((p->prev != NULL) && (p->next != NULL) && (p->next->next != NULL))
  {
    Node *node = p->prev;
    Node *tail = p;
    Node *tempNode = p->next;
    Node *otherNode = p->next->next;
    node->next = tempNode;
    tail->prev = tempNode;
    tail->next = otherNode;
    tempNode->prev = node;
    tempNode->next = tail;
    otherNode->prev = tail;
  }
}
