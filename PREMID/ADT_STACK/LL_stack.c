#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  int data;
  struct node* link;
} NODE;

typedef struct stack {
  NODE *top;
} STACK;

//* Utility functions
void initStack  (STACK *main);
void display    (STACK main);
bool isEmpty    (STACK main);
// bool isFull     (STACK main);    Not applicable to Linked Lists

//* Main Functions
int top         (STACK main);
int pop         (STACK *main);
void push       (STACK *main, int newData);

int main(){
  STACK dishes;
  initStack(&dishes);

  push(&dishes, 1);
  push(&dishes, 2);
  push(&dishes, 3);

  pop(&dishes);

  display(dishes);
  // display(dishes);
  
}

// Utility functions
void initStack  (STACK *main){
  main->top = NULL;
  printf("initStack() successful\n");
}
void display    (STACK main){
  STACK temp;
  initStack(&temp);

  printf("display()\n");
  while (!isEmpty(main)){
    push(&temp, top(main));
    printf("[%d]\n", top(temp));
  }
  // while (!isEmpty(temp)){
  //   push(&main, pop(&temp));
  // }
}
bool isEmpty    (STACK main){
  return main.top == NULL;
}
// bool isFull     (STACK main)     Not applicable to Linked Lists

// Main functions
int top         (STACK main){
  if (!isEmpty(main)){
    return main.top->data;
  }
}
int pop         (STACK *main){
  // Basically deleteFirst
  NODE *temp;
  int poppedValue;
  if (!isEmpty(*main)){
    poppedValue = main->top->data;
    temp = main->top;
    main->top = temp->link;
    free(temp);
    // printf("pop(%d) successful\n", poppedValue);
  }
  return poppedValue;
}
void push       (STACK *main, int newData){
  // Basically insertFirst
  NODE *newNode = (NODE*)malloc(sizeof(struct node));
  if (newNode != NULL){
    newNode->data = newData;
    newNode->link = main->top;
    main->top = newNode;
    printf("push(%d) successful\n", newData);
  }
}