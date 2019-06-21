#include <stdlib.h>
#include <stdio.h>
struct Node {
  int data;
  struct Node *next;
};
void printList(struct Node *n)
{
  printf("Nodes: \n");
  while (n != NULL)
  {
    printf("%d\n", n->data);
    n = n->next;
  }
}
void addNode(struct Node **n, int data)
{
  /*  n is a pointer to a pointer, head */
  struct Node* newNode = NULL;
  newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  /* allocating memory assigning value to new node */
  newNode->next = *n;
  /* it's next value points to the current first node in the list */
  *n = newNode;
  /* the reference to the first node in the list, head, now points to newNode */ 
  return;
}
void appendNode(struct Node **n, int data)
{
  /* appends new node to list */
  struct Node *cursor = *n;
  /* duplicates head */
  struct Node* newNode = NULL;
  newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  /* initializes newNode with data, and next value pointing to null, as it will be last in list */
  if (*n == NULL)
  {
    /* if head references null, list is empty, so it should reference newNode */
    *n = newNode;
    return;
  }
  else
  {
    while (cursor->next != NULL)
    {
      /* iterate through list until null pointer indicates last item reached */
      cursor = cursor->next;
    }
    /* last item next pointer points to newNode */
    cursor->next = newNode;
    return;
  }
}
void insertAfter(struct Node *prev, int data)
{
  /* functions takes a node, and a value to be placed after the node */
  struct Node* newNode = NULL;
  newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  /* allocate new node */
  newNode->next = prev->next;
  /* newNode points at whatever the preceding node was pointing at */
  prev->next = newNode; 
  /* the previous node now points at newNode */
  return;
}
void deleteNode(int key, struct Node **head_ref)
{
  /* deletes given node, by traversing the list until ->next is nodeToDelete */
  /* assign prevnode->next to nodeToDelete->next, then free nodeToDelete */
  struct Node *cursor = *head_ref, *prev;
  if (cursor->data == key)
  {
    *head_ref = cursor->next;
    free(cursor);
    return;
  }
  /* while cursor is not null and its data is not key */
  while (cursor != NULL && cursor->data != key)
  {
    /* store prev node, and change cursor to look at next node */
    prev = cursor;
    cursor = cursor->next;
  }
  if (cursor == NULL)
  {
    return;
  }
  prev->next = cursor->next;
  free(cursor);
}
int main(void)
{
  struct Node* first = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;
  first = malloc(sizeof(struct Node));
  second = malloc(sizeof(struct Node));
  third = malloc(sizeof(struct Node));
  first->data = 1;
  first->next = second;
  second->data = 2;
  second->next = third;
  third->data = 3;
  third->next = NULL;
  int val = 4;
  struct Node *head = first;
  /* head is a pointer to the first node */
  printList(head);
  /* addNode is passed the address of head and a value to add */
  appendNode(&head,  val);
  printList(head);
  insertAfter(second, 5);
  printList(head);
  deleteNode(5, &head);
  printList(head);
  return 0;
}
