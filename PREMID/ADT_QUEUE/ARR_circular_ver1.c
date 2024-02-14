// AUTHOR   :   LANUTAN, ACHILLE LORENZO - 22103514
// DATE     :   MONDAY, JANUARY 22, 2024
// DESC     :   This is a circular array implementation of a list VERSION 1. Meaning, we are not
//              sacrificing one cell/element in order to tell if the list is EMPTY or FULL.

#include <stdio.h>
#include <stdbool.h>
#define MAX 7

typedef struct {
  int elem[MAX];
  int count;
  int front;
  int rear;
} QUEUE;

//* Utility Functions
QUEUE initQueue     (int rear, int front);
bool isFull         (QUEUE main);
bool isEmpty        (QUEUE main);
void displayQueue   (QUEUE main);

//* Main Functions
void enqueue        (QUEUE *main, int newData);
void dequeue        (QUEUE *main);

int main(){
  QUEUE GTR;
  GTR = initQueue(3,4);

  enqueue(&GTR, 1);
  enqueue(&GTR, 2);
  enqueue(&GTR, 3);
  enqueue(&GTR, 4);
  enqueue(&GTR, 5);
  enqueue(&GTR, 6);
  enqueue(&GTR, 7);

  displayQueue(GTR);
}

//* Utility Functions
QUEUE initQueue     (int rear, int front){
  QUEUE newQueue;
  newQueue.count = 0;
  newQueue.rear = rear;
  newQueue.front = front;
  return newQueue;
}
bool isFull         (QUEUE main){
  return main.count == MAX-1;
}
bool isEmpty        (QUEUE main){
  return main.count == 0;
}
void displayQueue   (QUEUE main){
  int x;
  int stopper;
  if (!isEmpty(main)){
    for (x = main.front, stopper = 0 ; stopper < main.count ; x = (x + 1) % MAX){
      printf("[%d]->", main.elem[x]);
      stopper++;
    }
    printf("NULL\n");
  } else {
    printf("Queue empty\n");
  }
}

//* Main Functions
void enqueue        (QUEUE *main, int newData){
  if (!isFull(*main)){
    main->rear = (main->rear + 1) % MAX;
    main->elem[main->rear] = newData;
    main->count++;
  } else {
    printf("Queue is full\n");
  }
}
void dequeue        (QUEUE *main){
  if (!isEmpty(*main)){
    main->front = (main->front + 1) % MAX;
    main->count--;
  } else {
    printf("Queue is empty\n");
  }
}