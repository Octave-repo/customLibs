#include <stdlib.h>
#include "slinkedlib.h"

Liste sAddHead(Liste l, Liste a)
{
    if (!l)
    {
        a->s = NULL;
        l = a;
        return l;
    }

    a->s = l;
    l = a;
    return l;
}

Liste sAddTail(Liste l, Liste a)
{
    Liste current;

    current = l;
    
    if (!l)
    {
        l->s = NULL;
        return l;
    }

    while (current->s)
        current = current->s;
    
    a->s = NULL;
    current->s = a;
    return l;
}

void sPrintLinked(Liste l, void (*printFun) (Liste l))
{
    if (l)
    {
        printFun(l);
        sPrintLinked(l->s, printFun);
    }
}

Liste sInsert(Liste l, Liste a, int i)
{
    Liste temp;
    Liste current;

    if (i <= 0)
    {
        return sAddHead(l, a);
    }

    current = l;
    i--;
    if (!l)
    {
        l->s = NULL;
        return l;
    }

    while (i && current->s)
    {
        i--;
        current = current->s;
    }

    if (i)
    {
        return sAddTail(l, a); 
    }
    else
    {
        temp = current->s;
        current->s =a;
        a->s = temp;
    }
    return l;
}

Liste sSortedInsert(Liste l , Liste a, int (*compar)(Liste a, Liste b))
{
    Liste current;
    int i;

    i = 0;
    current = l;

    while ((current) && (compar(current, a) < 0))
    {
        current = current->s;
        i++;
    }
    return sInsert(l, a, i);
}

int sSize(Liste l)
{
    if (!l)
        return 0;
    return 1+sSize(l->s);
}

Liste sRemoveHead(Liste l, void (*freefun) (void *o))
{
    Liste supp;

    supp = l;
    l = l->s;
    freefun(supp->o);
    free(supp);
    return l;
}

Liste sRemoveTail(Liste l, void (*freefun) (void *o))
{
    Liste current;
    Liste prec;

    current = l;
    prec = l;

    while(current->s)
    {
        prec = current;
        current = current->s;
    }

    if (current == l)
    {
        freefun(l->o);
        free(l);
        l = NULL;
        return NULL;
    }

    prec->s = NULL;
    freefun(current->o);
    free(current);
    return l;
}

Liste sFind(Liste l, Liste a, int (*compar)(Liste a, Liste b))
{
    Liste current;

    current = l;

    while ((current) && (compar(current, a)))
        current = current->s;
    return current;
}

int sFindIndex(Liste l, Liste a, int (*compar)(Liste a, Liste b))
{

    Liste current;
    int i;

    current = l;
    i = 0;

    while ((current) && (compar(current, a)))
    {
        current = current->s;
        i++;
    }

    return current ? i : -1;
}

Liste sRemoveI(Liste l, int i, void (*freefun) (void *o))
{
    Liste temp;
    Liste current;
    Liste prec;

    if (i <= 0)
    {
        return sRemoveHead(l, freefun);
    }

    current = l;

    while (i && current->s)
    {
        i--;
        prec = current;
        current = current->s;
    }

    prec->s = current->s;
    freefun(current->o);
    free(current);
    return l;
}