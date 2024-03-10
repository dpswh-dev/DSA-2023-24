#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 7
#define EMPTY -1
#define DELETED -2

typedef int DICTIONARY[MAX];

typedef struct node {
  DICTIONARY A;
  int count;
} SET, *SETptr;

void initDictionary       (SET* main);
int hash                  (int elem);
bool isMember             (SET main, int find);
void insert               (SET* main, int data[], int size);
void display              (SET main);
void delete               (SET* main, int delete);
SET populate              (SET main);
void insertSorted         (SET* main, int newData);

int main(){
  SET Webster;
  SET sortedWebster;
  initDictionary(&sortedWebster);
  initDictionary(&Webster);
  // int numbers[] = {3,3,33,44,21,93,73,22,32,40};
  // int numbers[] = {3,13,23,33,43,53,63,73,83,93};
  int numbers[] = {3,13,44,54,55,10,22,55,86,24,0};
  
  insert(&Webster, numbers, sizeof(numbers)/sizeof(numbers[0]));

  // insert(&Webster, 3);
  // insert(&Webster, 3);     // test case: uniqueness
  // insert(&Webster, 33);    // test case: collision (synonym)
  // insert(&Webster, 44);    // test case: displacement 
  // insert(&Webster, 21);    // test case: N\A
  // insert(&Webster, 93);    // test case: collision
  // insert(&Webster, 50);    // test case: full dictionary

  // delete(&Webster, 93);    // test case: delete feature
  display(Webster);

  // insert(&Webster, 73);    // test case: insert at DELETED

  // display(Webster);

  // sortedWebster = populate(Webster);
  // display(sortedWebster);
  // sortedWebster = insertSorted(Webster);
  // display(sortedWebster);
}
void initDictionary       (SET* main){
  int x;
  for (x = 0 ; x < MAX ; x++){
    main->A[x] = EMPTY;
  }
  main->count = 0;
  printf("Initialized dictionary.\n");
}
int hash                  (int elem){
  return elem % 10;
}
bool isMember             (SET main, int find){
  int hashVal;
  int x;

  for (hashVal = hash(find), x = 0; x < MAX && (main.A[hashVal] != EMPTY && main.A[hashVal] != find); hashVal = (hashVal + 1) % MAX, x++) {};
  
  return main.A[hashVal] == find;
}
void insert               (SET* main, int data[], int size){
  int x, y, hashVal, count;
  SET filter = {{EMPTY}, 0};

  for (x = 0; x < size; x++) {
    hashVal = hash(data[x]);
    if (!isMember(*main, data[x])) {
      if (main->count < MAX && main->A[hashVal] == EMPTY || main->A[hashVal] == DELETED) {
        printf("[%d] No collision. Inserting element to main dictionary.\n", data[x]);
        main->A[hashVal] = data[x];
        main->count++;
      } else {
        printf("[%d] produces collision. Moving to filter...\n", data[x]);
        filter.A[filter.count] = data[x];
        filter.count++;
      }
    } else {
      printf("[%d] Not unique.\n", data[x]);
    }
  }

  display(*main);


  for (x = 0; x < filter.count && main->count < MAX ; x++) {
    hashVal = hash(filter.A[x]);
    for (y = hashVal ; main->A[y] != EMPTY && main->A[y] != DELETED; y = (y+1) % MAX){};
    
    if (main->count < MAX) {
      printf("Inserted [%d] into main dictionary.\n", filter.A[x]);
      main->A[y] = filter.A[x];
      main->count++;
    } else {
      printf("Cannot insert [%d]. Your dictionary is full.\n", filter.A[x]);
    }
  }
}
void display              (SET main){
  int x;
  printf("HASH TABLE\n");
  printf("%8s|%s\n", "INDEX", "VALUE");
  printf("=============================\n");
  for (x = 0 ; x < MAX ; x++){
    printf("%8d|%8d\n", x, main.A[x]);
  }
}
void delete               (SET* main, int delete){
  int hashVal, x;
  if (main->count > 0){
    for (hashVal = hash(delete), x = 0 ; x < main->count && main->A[hashVal] != EMPTY && main->A[hashVal] != DELETED && main->A[hashVal] != delete ; hashVal = (hashVal + 1) % MAX, x++){};
    if (main->A[hashVal] == delete){
      main->A[hashVal] = DELETED;
      main->count--;
      printf("Deleted %d!\n", delete);
    } else {
      printf("Not a valid integer to delete.\n");
    }
  } else {
    printf("No elements in the dictionary.\n");
  }
}
void insertSorted  (SET* main, int newData){
  int x,y;
  for (x = 0 ; x < main->count && newData > main->A[x] ; x++){};
  for (y = main->count ; y != x ; y--){
    main->A[y] = main->A[y-1];
  }
  main->A[x] = newData;
  // printf("Inserted %d\n", newData);
}
SET populate     (SET main){
  SET new;
  initDictionary(&new);
  int x,y,z;

  //* With function
  // for (x = 0 ; x < main.count ; x++){
  //   insertSorted(&new, main.A[x]);
  //   new.count++;
  // }

  //* Manual
  for (x = 0 ; x < main.count ; x++){
    for (y = 0 ; y < new.count && main.A[x] > new.A[y] ; y++){};
    for (z = new.count ; z != y ; z--){
      new.A[z] = new.A[z-1];
    }
    new.A[y] = main.A[x];
    new.count++;
    printf("Inserted %d\n", main.A[x]);
  }
  return new;
}