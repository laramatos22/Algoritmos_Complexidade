// NMEC: 95228
// NICK: Lara Catarina da Silva Matos

// Complete the functions (marked by ...)
// so that it passes all tests in Tests.

#include "PersonSet.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SortedList.h"

// NOTE THAT:
// - Field capacity was eliminated.
// - Field size was eliminated, because size==ListGetSize(...).

// Definition of the structure
struct _PersonSet_ {
  List *persons;  // points to a SortedList of Person pointers
};

// Comparison function to be used in generic SortedList.
// Comparison is based on Person ID
static int cmpP(const void *a, const void *b) {
  Person *p1 = (Person *)a;
  Person *p2 = (Person *)b;
  int d = p1->id - p2->id;
  return (d > 0) - (d < 0);
}

// Create a PersonSet.
PersonSet *PersonSetCreate() {
  // You must allocate space for the struct and create an empty persons list!
  //...

  PersonSet* ps = (PersonSet*) malloc(sizeof(*ps));


  if (ps == NULL)
  {
    perror("PersonSetCreate");
    exit(2);
  }

  ps->persons = ListCreate(cmpP);

  if (ps->persons == NULL)
  {
    free(ps);
    perror("PersonSetCreate");
    exit(2);
  }
  
  ListTestInvariants(ps->persons); //testar se os atributos da lista foram bem testados

  return ps;
  
}

// Destroy PersonSet *pps
void PersonSetDestroy(PersonSet **pps) {
  assert(*pps != NULL);
  //...

  free(*pps);
  *pps = NULL;
  
}

int PersonSetSize(const PersonSet *ps) { return ListGetSize(ps->persons); }

int PersonSetIsEmpty(const PersonSet *ps) { return ListIsEmpty(ps->persons); }

void PersonSetPrint(const PersonSet *ps) {
  printf("{\n");
  for (ListMoveToHead(ps->persons); ListCurrentIsInside(ps->persons);
       ListMoveToNext(ps->persons)) {
    Person *p = (Person *)ListGetCurrentItem(ps->persons);
    PersonPrintf(p, ";\n");
  }
  printf("}(size=%d)\n", PersonSetSize(ps));
  ListTestInvariants(ps->persons);
}

// Find node in list ps->persons of person with given id.
// (INTERNAL function.)
static int search(const PersonSet *ps, int id) {
  Person dummyperson;
  dummyperson.id = id;
  return ListSearch(ps->persons, &dummyperson);
}

// Add person *p to *ps.
// Do nothing if *ps already contains a person with the same id.
void PersonSetAdd(PersonSet *ps, Person *p) {
  //...

  // Search for the first node with a value that compares==0 with *p.
  int ls = ListSearch(ps->persons, p);
  
  if (ls == -1)
  {
    // Insert a node.
    ListInsert(ps->persons, p);
  }

}

// Pop one person out of *ps.
Person *PersonSetPop(PersonSet *ps) {
  assert(!PersonSetIsEmpty(ps));
  // It is easiest to pop and return the person in the first position!
  //...

  // Remove the head of the list and make its next node the new head.
  Person* person = ListRemoveHead(ps->persons);

  return person;

}

// Remove the person with given id from *ps, and return it.
// If no such person is found, return NULL and leave set untouched.
Person *PersonSetRemove(PersonSet *ps, int id) {
  // You may call search here!
  //...

  int s = search(ps, id); //pesquisa

  if (s == 0)
  {
    //retorna a pessoa removida
    return (Person*) ListRemoveCurrent(ps->persons);
  }

  //caso contrario return NULL
  return NULL; 
  
  
}

// Get the person with given id of *ps.
// return NULL if it is not in the set.
Person *PersonSetGet(const PersonSet *ps, int id) {
  // You may call search here!
  //...

  int s = search(ps, id);   // pesquisa

  if (s == 0)
  {
    // return da pessoa pretendida
    return (Person*) ListGetCurrentItem(ps->persons);
  }
  
  //caso contrario return NULL
  return NULL;
  
}

// Return true (!= 0) if set contains person wiht given id, false otherwise.
int PersonSetContains(const PersonSet *ps, int id) {
  return search(ps, id) >= 0;
}

// Return a NEW PersonSet with the union of *ps1 and *ps2.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetUnion(const PersonSet *ps1, const PersonSet *ps2) {
  PersonSet *ps = PersonSetCreate();

  // Merge the two sorted lists (similar to mergesort).
  //...

  ListMoveToHead(ps1->persons);
  ListMoveToHead(ps2->persons);

  Person* person;

  int position = 0;   //posicao inicial
  int size_ps1 = ListGetSize(ps1->persons);   // tamanho da lista de pessoas de ps1
  int size_ps2 = ListGetSize(ps2->persons);   // tamanho de lista de pessoas de ps2

  while (position < size_ps1 || position < size_ps2)
  {
    if (position < size_ps1)
    {
      // person é o item correspondente à posicao que está
      person = (Person *) ListGetCurrentItem(ps1->persons);
      ListInsert(ps->persons, person);  // insercao do novo node
      ListMoveToNext(ps1->persons);     // mover para o seguinte
    }

    if (position < size_ps2)
    {
      person = (Person *) ListGetCurrentItem(ps2->persons);
      ListInsert(ps->persons, person);
      ListMoveToNext(ps2->persons);
    }
    
    position++;

  }
  
  return ps;

}

// Return a NEW PersonSet with the intersection of *ps1 and *ps2.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetIntersection(const PersonSet *ps1, const PersonSet *ps2) {
  PersonSet *ps = PersonSetCreate();
  //...

  ListMoveToHead(ps1->persons);

  Person* person;

  int position = 0;
  int size_ps1 = ListGetSize(ps1->persons);

  while (position != size_ps1)
  {
    person = (Person*) ListGetCurrentItem(ps1->persons);

    // pesquisa na lista
    int ls = ListSearch(ps2->persons, person);

    if (ls == 0)
    {
      // insercao do novo node
      ListInsert(ps->persons, person);
    }

    position++;
    ListMoveToNext(ps1->persons);   // passa para o item seguinte
    
  }
  
  return ps;

}

// Return a NEW PersonSet with the set difference of *ps1 and *ps2.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetDifference(const PersonSet *ps1, const PersonSet *ps2) {
  PersonSet *ps = PersonSetCreate();
  //...

  ListMoveToHead(ps1->persons);   // começa no inicio da lista (head)

  Person* person;

  int position = 0;
  int size_ps1 = ListGetSize(ps1->persons);

  while (position != size_ps1)
  {
    person = (Person*) ListGetCurrentItem(ps1->persons);

    // pesquisa na lista
    int ls = ListSearch(ps2->persons, person);

    if (ls == -1)   // se nao existe...
    {
      // inserir novo node
      ListInsert(ps->persons, person);
    }

    position++;
    ListMoveToNext(ps1->persons); // passa para o seguinte
    
  }
  
  return ps;

}

// Return true iff *ps1 is a subset of *ps2.
int PersonSetIsSubset(const PersonSet *ps1, const PersonSet *ps2) {
  //...

  ListMoveToHead(ps1->persons);

  Person* person;

  int position = 0;
  int size_ps1 = ListGetSize(ps1->persons);

  while (position != size_ps1)
  {
    person = (Person*) ListGetCurrentItem(ps1->persons);

    int ls = ListSearch(ps2->persons, person);

    if (ls == -1)
    {
      return 0;
    }

    position++;
    ListMoveToNext(ps1->persons);
    
  }
  
    return 1;

}

// Return true if the two sets contain exactly the same elements.
int PersonSetEquals(const PersonSet *ps1, const PersonSet *ps2) {
  // You may call PersonSetIsSubset here!
  //...
  
  return (PersonSetIsSubset(ps1, ps2) && ListGetSize(ps1->persons) == ListGetSize(ps2->persons));

}
