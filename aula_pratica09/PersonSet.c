//NMEC: 95228
//NICK: Lara Catarina da Silva Matos

// O tipo PERSONSET usa um vetor (“array”) para armazenar o conjunto de instâncias do tipo
// PERSON, sem qualquer critério de ordem associado

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
  PersonSet* ps = (PersonSet*) malloc(sizeof(*ps));

  // The array should be created with INITIAL_CAPACITY elements.
  // (The array will be reallocated if necessary, when elements are appended.)
  //Person** array;
  ps->array = (Person**) malloc(sizeof(*ps)*INITIAL_CAPACITY);
  ps->capacity = 4; // = INITIAL_CAPACITY
  ps->size = 0;

  if (ps == NULL)
  {
    perror("PersonSetCreate");
    exit(2);
    return NULL;
  }

  if (ps->array == NULL)
  {
    free(ps);
    return NULL;
  }
  

  return ps;
  
}

// Destroy PersonSet *pps
void PersonSetDestroy(PersonSet **pps) {
  assert(*pps != NULL);
  
  free(*pps);
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

  int i=0;

  for(; i < ps->size; i++){
    if(id == ps->array[i]->id)
	  return i;
  }
  return -1;
  
}

// Append person *p to *ps, without verifying presence.
// Use only when sure that *p is not contained in *ps!
// (INTERNAL function.)
static void append(PersonSet *ps, Person *p) {
  // MODIFY the function so that if the array is full,
  // use realloc to double the array capacity!

  int s = search(ps, p->id);    //pesquisa a ver se a pessoa existe no array

  if (!s)   // se nao existir...
  {
    ps->array = (Person**) realloc(ps->array, sizeof(ps->array)*2);

    //a capacidade passa para o dobro
    ps->capacity = ps->capacity*2;

  }

  //adicao da nova pessoa
  ps->array[ps->size] = p;
  ps->size++;

}


// Add person *p to *ps.
// Do nothing if *ps already contains a person with the same id.
void PersonSetAdd(PersonSet *ps, Person *p) {
  // You may call the append function here!
  
  int s = search(ps, p->id);  //pesquisar

  if (s < 0) 
  {
    append(ps, p);
  }
  
}

// Pop one person out of *ps.
Person* PersonSetPop(PersonSet *ps) {
  assert(!PersonSetIsEmpty(ps));
  // It is easiest to pop and return the person in the last position!
  
  Person* pp = ps->array[(ps->size-1)];

  ps->array[(ps->size-1)] = NULL;

  ps->size--;

  return pp;
  
}

// Remove the person with given id from *ps, and return it.
// If no such person is found, return NULL and leave set untouched.
Person *PersonSetRemove(PersonSet *ps, int id) {
  // You may call search here!

  Person* person = NULL;

  int s = search(ps, id);

  if (s >= 0){

    person = ps->array[s];
    ps->array[s] = ps->array[ps->size - 1];
    ps->array[--(ps->size)] = NULL;
    return person;

  }

  return NULL;  
  
}


// Get the person with given id of *ps.
// return NULL if it is not in the set.
Person *PersonSetGet(const PersonSet *ps, int id) {
  // You may call search here!
  //...

  int s = search(ps, id);   //faz a pesquisa

  if (s >= 0)    // se s existe no array:
  {
    return ps->array[s];  // obter o id do person se ele existir
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
  PersonSet *ps = PersonSetCreate();  // criacao de um novo PersonSet para unir *ps1 e *ps2
  //...

  if (ps == NULL)   // se a alocacao falhar
  {
    perror("PersonSetUnion");
    PersonSetDestroy(&ps);
    exit(2);
  }

  int i;
  
  for (i = 0; i < ps1->size; i++)
  {
    append(ps, ps1->array[i]); 
  }

  for (i = 0; i < ps2->size; i++)
  {
    PersonSetAdd(ps, ps2->array[i]); 
  }

  return ps;

}

// Return a NEW PersonSet with the intersection of *ps1 and *ps2.
// Return NULL if allocation fails.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetIntersection(const PersonSet *ps1, const PersonSet *ps2) {
  //...

  PersonSet *pSet = PersonSetCreate();

  int i;

  if (pSet == NULL)
  {
    perror("PersonSetIntersection");
    PersonSetDestroy(&pSet);
    return NULL;
  }
  
  for (i = 0; i < ps2->size; i++)
  {
    int s = search(ps1, ps2->array[i]->id);   //faz a pesquisa

    if (s >= 0)
    {
      PersonSetAdd(pSet, ps2->array[i]);
    }
    
  }
  
  return pSet;
  
}

// Return a NEW PersonSet with the set difference of *ps1 and *ps2.
// Return NULL if allocation fails.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetDifference(const PersonSet *ps1, const PersonSet *ps2) {
  //...

  PersonSet *pSet = PersonSetCreate();

  int i;

  if (pSet == NULL)
  {
    perror("PersonSetDifference");
    PersonSetDestroy(&pSet);
    return NULL;
  }

  for (i = 0; i < ps1->size; i++)
  {

    int s = search(ps2, ps1->size);   //faz a pesquisa

    if (s != 0)
    {
      append(pSet, ps1->array[i]);
    }
    
  }

  return pSet;  

}

// Return true iff *ps1 is a subset of *ps2.
int PersonSetIsSubset(const PersonSet *ps1, const PersonSet *ps2) {
  //...

  int i;

  for (i = 0; i < ps1->size; i++)
  {
    int s = search(ps2, ps1->array[i]->id);   //faz a pesquisa
    
    if (s < 0)
    {
      return 0;
    }
    
  }
  
  return 1;
  
}

// Return true if the two sets contain exactly the same elements.
int PersonSetEquals(const PersonSet *ps1, const PersonSet *ps2) {
  // You may call PersonSetIsSubset here!
  //...

  return PersonSetIsSubset(ps2, ps1) == 1 && PersonSetIsSubset(ps1, ps2) == 1;
  
}


