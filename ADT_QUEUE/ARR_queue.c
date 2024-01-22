#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef struct node {
  int elems[MAX];
  int front;
  int rear;
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

int main(){
  QUEUE Rewind;
  initQueue(&Rewind);

  printf("%d\n", isEmpty(Rewind));

  enqueue(&Rewind, 1);
  enqueue(&Rewind, 2);
  enqueue(&Rewind, 3);
  enqueue(&Rewind, 4);
  enqueue(&Rewind, 5);

  dequeue(&Rewind);

  display(Rewind);
}

//* Utility Functions
void  initQueue (QUEUE *main){
  main->front = -1;
  main->rear = -1;
  printf("initQueue()\n");
}
bool  isEmpty   (QUEUE main){
  return main.front == -1 && main.rear == -1;
}
bool  isFull    (QUEUE main){
  return main.rear == MAX-1;
}
void  display   (QUEUE main){
  QUEUE temp;
  int x;
  initQueue(&temp);
  if (!isEmpty(main)){
    for (x = 0 ; main.front != -1 ; x++){
      temp.elems[x] = front(main);
      printf("[%d]->", temp.elems[x]);
      dequeue(&main);
    }
    printf("NULL\n");
  } else {
    printf("Empty queue.\n");
  }
}

//* Main Functions
void  enqueue   (QUEUE *main, int newData){
  if (isEmpty(*main)) {
    main->front++;
    main->rear = main->front;
    main->elems[main->front] = newData;
  } else {
    if (!isFull(*main)) {
      main->rear++;
      main->elems[main->rear] = newData;
    } else {
      printf("Queue overflow\n");
    }
  } 
}
void  dequeue   (QUEUE *main){
  if (isEmpty(*main)){
    printf("Nothing to dequeue.\n");
  } else if (main->front == main->rear){
    main->front = -1;
    main->rear = -1;
  } else {
    main->front++;
  }
}
int   front     (QUEUE main){
  if (!isEmpty(main)){
    return main.elems[main.front];
  } else {
    printf("Error\n");
  }
}   // Alternatively called "peek"

