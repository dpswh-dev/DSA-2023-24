#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef struct {
  int data;
  int link;
} NodeType;

typedef struct node {
  NodeType elems[MAX];
  int front;
  int rear;
  int Avail;
} QUEUE;

//* Utility Functions
void  initQueue (QUEUE *main);
bool  isEmpty   (QUEUE main);
bool  isFull    (QUEUE main);
void  display   (QUEUE main);

//* Main Functions
void  enqueue   (QUEUE *main, int newData);
void  dequeue   (QUEUE *main);
int   front     (QUEUE main);   // Alternatively called "peek"