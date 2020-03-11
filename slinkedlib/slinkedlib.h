#include <stdlib.h>
#include <stdio.h>

#ifndef _SLINKED_
#define _SLINKED_

typedef struct Cell
{
    void *o;
    struct Cell *s;
} Cellule;

typedef Cellule *Liste;

Liste sInsert(Liste l, Liste a, int i);
Liste sSortedInsert(Liste l , Liste a, int (*compar)(Liste a, Liste b));
Liste sAddHead(Liste l, Liste a);
void sPrintLinked(Liste l, void (*printFun) (Liste l));
Liste sAddTail(Liste l, Liste a);
int sSize(Liste l);
Liste sRemoveHead(Liste l, void (*freefun) (void *o));
Liste sRemoveTail(Liste l, void (*freefun) (void *o));
Liste sRemoveI(Liste l, int i, void (*freefun) (void *o));
Liste sFind(Liste l, Liste a, int (*compar)(Liste a, Liste b));
int sFindIndex(Liste l, Liste a, int (*compar)(Liste a, Liste b));

#endif