#include <stdio.h>


int array2ptr(void);

int main() {
    /* you can't not initialize array with variable!
     * for example...

     * int size:
     * int array[size] = {0} > compile error
    */

    const int size = 10;
    int array[size] = {0}; // all array item is initialized by 0.

    array2ptr();

    return 0;
}

int array_print(short array[3]);
/*
 * those expresions are doing same actions!
 * how pointer & array works
 */
int array2ptr(void)
{
    short array[3];
    short *ptr;
    ptr = array;
    ptr[0] = 0;
    ptr[1] = 10;
    ptr[2] = 20;
    array_print(ptr);

    short array2[3];
    short *ptr2;
    ptr2 = &array2[0];
    *ptr2 = 0;
    *(ptr2 + 1) = 10;
    *(ptr2 + 2) = 20;
    array_print(ptr2);

    short array3[3];
    short *ptr3;
    ptr3 = &array3[0];
    *(ptr3) = 0;
    *(++ptr3) = 10;
    *(++ptr3) = 20;
    array_print(ptr3 - 2);

};

int array_print(short array[3])
{
    for(int i = 0; i < 3; i ++){
        printf("array[%d] = %d\n", i, array[i]);
    }
    return 0;
}