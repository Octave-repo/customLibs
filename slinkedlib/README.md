# TYPES

## The type *Liste* is the basic type used for this library.

It contains two elements :
 - _struct Cell *s_ is used to reference the next element of the linked list.
 - _void *o_ this the datas you want to put in you list.


# FUNCTIONS

## This is how each functions of the library works

1. `Liste sAddHead(Liste l, Liste a)`
    - Insert the element 'a' as the new head of the list.

2. `Liste sAddTail(Liste l, Liste a)`
    - Insert the element 'a' as the new tail of the list.

3. `Liste sInsert(Liste l, Liste a, int i)`
    - Insert the element 'a' at the index 'i' in the list 'l'.
    - If 'i' is lower than 0 it will put the element as the head of the list.
    - If 'i' is higher than the size of the list it will put the element as the tail of the list. 

4. `Liste sSortedInsert(Liste l , Liste a, int (*compar)(Liste a, Liste b))`
    - Insert the element 'a' in the list 'l' in a sorted way using the 'compar' function.
    - The comparaison function must return an integer :
        - Lower than 0 if 'a' is considered lower than 'b'.
        - Equal to 0 if 'a' is considered equal to 'b'.
        - Greater than 0 if 'a' is considered greater than 'b'.

5. `void sPrintLinked(Liste l, void (*printFun) (Liste l))`
    - Prints the linked list from head to tail using 'printFun' as the print funtion.
    - The function 'printFun' is used to print each element from the list.

6. `int sSize(Liste l)`
    - Returns the amount of elements in the list 'l'.

7. `Liste sRemoveHead(Liste l, void (*freefun) (void *o))`
    - Removes the head of the list and frees it.
    - The function 'freefun' is used to free the datas you put in 'o' of each list.

8. `Liste sRemoveTail(Liste l, void (*freefun) (void *o))̀`
    - Removes the tail of the list and frees it.
    - The function 'freefun' is used to free the datas you put in 'o' of each list.

9. `Liste sRemoveI(Liste l, int i, void (*freefun) (void *o))`
    - Removes the element at the index 'i' in the list 'l'.
    - If 'i' is lower than 0 it will remove the element at the head of the list.
    - If 'i' is higher than the size of the list it will remove the element at the tail of the list.

10. `Liste sFind(Liste l, Liste a, int (*compar)(Liste a, Liste b))`
    - Returns the first element in the list 'l' matching the element 'a' using the 'compar' function.
    - The function will return the NULL pointer if no matching element are found.
    - The 'compar' must return 0 if the elements are matching.

11. `int sFindIndex(Liste l, Liste a, int (*compar)(Liste a, Liste b))`
    - Returns the first index where the element 'a' in the list 'l' is found using the 'compar' function.
    - The function will return -1 if no matching element are found.
    - The 'compar' must return 0 if the elements are matching.