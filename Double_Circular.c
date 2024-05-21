#include <stdio.h>
#include <stdlib.h>

typedef struct Node *NodePointer;

struct Node
{
  int value;
  NodePointer next;
  NodePointer prev;
} *head = NULL, *tail = NULL;

NodePointer createNode(int val)
{
  NodePointer temp = (NodePointer)malloc(sizeof(struct Node));
  temp->value = val;
  temp->next = NULL;
  temp->prev = NULL;
  return temp;
}

void insert_last(int val)
{
  NodePointer temp = createNode(val);
  if (head == NULL)
  {
    head = tail = temp;
    head->next = head;
    head->prev = head;
  }
  else
  {
    temp->next = head;
    temp->prev = tail;
    tail->next = temp;
    head->prev = temp;
    tail = temp;
  }
}

void swap_nodes(NodePointer a, NodePointer b)
{
  if (a == b)
    return;

  NodePointer aPrev = a->prev;
  NodePointer aNext = a->next;
  NodePointer bPrev = b->prev;
  NodePointer bNext = b->next;

  if (a->next == b)
  {
    a->next = bNext;
    a->prev = b;
    b->next = a;
    b->prev = aPrev;

    if (aPrev != NULL)
      aPrev->next = b;
    if (bNext != NULL)
      bNext->prev = a;
  }
  else if (b->next == a)
  {
    b->next = aNext;
    b->prev = a;
    a->next = b;
    a->prev = bPrev;

    if (bPrev != NULL)
      bPrev->next = a;
    if (aNext != NULL)
      aNext->prev = b;
  }
  else
  {

    a->next = bNext;
    a->prev = bPrev;
    b->next = aNext;
    b->prev = aPrev;

    if (aNext != NULL)
      aNext->prev = b;
    if (aPrev != NULL)
      aPrev->next = b;
    if (bNext != NULL)
      bNext->prev = a;
    if (bPrev != NULL)
      bPrev->next = a;
  }

  if (head == a)
  {
    head = b;
  }
  else if (head == b)
  {
    head = a;
  }

  if (tail == a)
  {
    tail = b;
  }
  else if (tail == b)
  {
    tail = a;
  }
}

void sort_ascending()
{
  if (head == NULL)
    return;

  int swapped;
  NodePointer ptr1;
  NodePointer lptr = NULL;

  do
  {
    swapped = 0;
    ptr1 = head;

    do
    {
      if (ptr1->next != head && ptr1->value > ptr1->next->value)
      {
        swap_nodes(ptr1, ptr1->next);
        swapped = 1;
      }
      ptr1 = ptr1->next;
    } while (ptr1->next != head);

    lptr = ptr1;
  } while (swapped);
}

void print_list()
{
  if (head == NULL)
    return;

  NodePointer temp = head;
  do
  {
    printf("Address: %p, Data: %d\n", (void *)temp, temp->value);
    temp = temp->next;
  } while (temp != head);
  printf("\n");
}

int main()
{
  int num_elements, i, jumlah;

  scanf("%d", &num_elements);

  if (num_elements < 1 || num_elements > 10)
  {
    printf("Jumlah data harus antara 1 dan 10.\n");
    return 1;
  }

  for (i = 0; i < num_elements; i++)
  {
    printf("", i + 1);
    scanf("%d", &jumlah);
    insert_last(jumlah);
  }

  printf("\n");
  print_list();

  sort_ascending();

  print_list();

  return 0;
}