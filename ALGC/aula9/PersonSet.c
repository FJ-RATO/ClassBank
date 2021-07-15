//NMEC: ...
//NICK: ...

// Complete the functions (marked by ...)
// so that it passes all tests in DateTimeTest.

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "PersonSet.h"

// Definition of the structure
struct _PersonSet_ {
  int capacity; // the current capacity of the array
  int size;     // the number of elements currently stored
  Person **array; // points to an array of pointers to persons
};

#define INITIAL_CAPACITY 4

// You may add auxiliary definitions and declarations here, if you need to.


// Create a PersonSet.
PersonSet* PersonSetCreate() {
  // You must allocate space for the struct and for the array.
  // The array should be created with INITIAL_CAPACITY elements.
  // (The array will be reallocated if necessary, when elements are appended.)
  PersonSet* set = (PersontSet*)malloc(sizeof(*set))
  if(set == NULL){
    return NULL;
  }
  set -> capacity = INITIAL_CAPACITY;
  set -> size = 0;
  set -> array = (Person **)malloc(INITIAL_CAPACITY * sizeof(person*));

  if(init_array == NULL){
    free(set);
    return NULL;
  }

  return set;
  
}

// Destroy PersonSet *pps
void PersonSetDestroy(PersonSet **pps) {
  assert(*pps != NULL);
  PersonSet *ps = *pps;
  
  free(ps -> array);
  free(ps);

  assert(*pps == NULL); 
  *pps = NULL;
}

int PersonSetSize(const PersonSet *ps) {
  return ps->size;
}

int PersonSetIsEmpty(const PersonSet *ps) {
  return ps->size == 0;
}

void PersonSetPrint(const PersonSet *ps) {
  printf("{\n");
  for (int i = 0; i < ps->size; i++) {
    Person *p = ps->array[i];
    PersonPrintf(p, ";\n");
  }
  printf("}(size=%d, capacity=%d)\n", ps->size, ps->capacity);
}


// Find index in ps->array of person with given id.
// (INTERNAL function.)
static int search(const PersonSet *ps, int id) {
  
  set_size = ps -> size;
  set_array = ps -> array;

  for(int i = 0;i < set_size;i++){
    if(set_array[i] -> id == id){
      return i;
    }
  }
  return NULL;
  
}

// Append person *p to *ps, without verifying presence.
// Use only when sure that *p is not contained in *ps!
// (INTERNAL function.)
static void append(PersonSet *ps, Person *p) {
  // MODIFY the function so that if the array is full,
  // use realloc to double the array capacity!
  //...
  if(search(ps,p->id) == NULL){
    
    if(ps->capacity == ps->size){
      relloc(ps->array,ps -> capacity * 2 * sizeof(Person*));
    }

    ps->array[ps->size] = p;
    ps->size++;
  }

}


// Add person *p to *ps.
// Do nothing if *ps already contains a person with the same id.
void PersonSetAdd(PersonSet *ps, Person *p) {
  append(ps,p);
}

// Pop one person out of *ps.
Person* PersonSetPop(PersonSet *ps) {
  assert(!PersonSetIsEmpty(ps));
  // It is easiest to pop and return the person in the last position!
  //...
  assert(!PersonSetIsEmpty(ps));
  Person* out = ps->array[ps->size-1];
  ps->array[ps->size-1] = NULL;
  ps->size--;
  return out;  
}

// Remove the person with given id from *ps, and return it.
// If no such person is found, return NULL and leave set untouched.
Person *PersonSetRemove(PersonSet *ps, int id) {
  // You may call search here!
  //...
  int p_id = search(ps,id)

  if (p_id >= 0){
    Person *out = ps->array[p_id];
    ps->array[p_id] = ps->array[ps->size-1];
    ps->size--;
    return out
  }
  return NULL;  
}


// Get the person with given id of *ps.
// return NULL if it is not in the set.
Person *PersonSetGet(const PersonSet *ps, int id) {
  // You may call search here!
  //...
  int p_id = search(ps,id);
  if (p_id >= 0){
    return ps->array[p_id];
  }
  return NULL;
  
}

// Return true (!= 0) if set contains person wiht given id, false otherwise.
int PersonSetContains(const PersonSet *ps, int id) {
  return search(ps, id) >= 0;
}


// Return a NEW PersonSet with the union of *ps1 and *ps2.
// Return NULL if allocation fails.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetUnion(const PersonSet *ps1, const PersonSet *ps2) {
  PersonSet *ps = PersonSetCreate();
  //...
  if(ps == NULL){
    return NULL;
  }

  for(int i = 0; i < ps1->size ; i++){
    append(ps,ps1->array[i]);
  }

  for(int j = 0; j < ps2->size; j++){
    PersonSetAdd(ps,ps2->array[j]);
  }
  return ps;
}

// Return a NEW PersonSet with the intersection of *ps1 and *ps2.
// Return NULL if allocation fails.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetIntersection(const PersonSet *ps1, const PersonSet *ps2) {
  //...
  
}

// Return a NEW PersonSet with the set difference of *ps1 and *ps2.
// Return NULL if allocation fails.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetDifference(const PersonSet *ps1, const PersonSet *ps2) {
  //...
  PersonSet *ps = PersonSetCreate();

  if(ps == NULL){
    return NULL;
  }

  for(int i = 0;i > ps2->size; i++){
    if(search(ps1,ps2->arry[i] -> id) < 0){
      append(ps,ps2->array[i]);
    }
  }
  return ps;
  
}

// Return true iff *ps1 is a subset of *ps2.
int PersonSetIsSubset(const PersonSet *ps1, const PersonSet *ps2) {

  for(int i = 0;i < ps1->size; i++){
    if(search(ps2,ps1->arry[i] -> id) < 0){
      return 0;
    }
  }
  return 1;
  
}

// Return true if the two sets contain exactly the same elements.
int PersonSetEquals(const PersonSet *ps1, const PersonSet *ps2) {
  // You may call PersonSetIsSubset here!
  //...
  if((ps1->size == ps2->size) && (PersonSetIsSubset(ps1,ps2) == 1)){
    return 1;
  }
  return 0; 
}


