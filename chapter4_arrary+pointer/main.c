#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_INPUT 256

int array2ptr(void);
int alloc_ptr(void);
int word_grade(void);
int prime_num(void);

int twoDarray(void);
int row_column(void);

int main() {
    /* you can't not initialize array with variable!
     * for example...

     * int size:
     * int array[size] = {0} > compile error
    */

    const int size = 10;
    int array[size] = {0}; // all array item is initialized by 0.

    // basic pointer and arrays example
//    array2ptr();
//    alloc_ptr();
//    word_grade();
//    prime_num();

    //multi-dimensional array example
    twoDarray();
    row_column();

    return 0;
}

int array_print(int *array, int len);
/*
 * those expresions are doing same actions!
 * how pointer & array works
 */
int array2ptr(void)
{
    int array[3];
    int *ptr;
    ptr = array;
    ptr[0] = 0;
    ptr[1] = 10;
    ptr[2] = 20;
    array_print(ptr, 3);

    int array2[3];
    int *ptr2;
    ptr2 = &array2[0];
    *ptr2 = 0;
    *(ptr2 + 1) = 10;
    *(ptr2 + 2) = 20;
    array_print(ptr2, 3);

    int array3[3];
    int *ptr3;
    ptr3 = &array3[0];
    *(ptr3) = 0;
    *(++ptr3) = 10;
    *(++ptr3) = 20;
    array_print(ptr3 - 2, 3);

    return 0;
};

int array_print(int *array, int len)
{
    for(int i = 0; i < len; i ++){
        printf("array[%d] = %d\n", i, array[i]);
    }
    return 0;
}

int alloc_ptr(void)
{
    int *ptr = (int *)malloc(sizeof(int) * 20);
    *ptr = 0;

    array_print(ptr, 20);

    free(ptr);
    return 0;
}


/*
 * practice problems
 */
int word_grade()
{
    char input[MAX_INPUT];
    fgets(input, MAX_INPUT, stdin);
    char *ptr = input;

    input[strlen(input) - 1] = '\0'; // delete "\n" from user input

    int sum = 0;
    while(*ptr != '\0') // or you can just type (*ptr), because '\n' counts as 0.
    {
        if(*ptr >= 'a' && *ptr <= 'z')
            sum += (int)(*ptr - 'a') + 1;

        if(*ptr >= 'A' && *ptr <= 'Z')
            sum += (int)(*ptr - 'A') + 1;

        ptr ++;
    }

    printf("the word %s's grade = %d", input, sum);

    return 0;
}

int prime_num(void)
{
    int size = 0;
    printf("input size of integer");
    scanf("%d", &size);
    // jetbrain IDE recommands to use strtol(char* nptr, char *endptr, int base)
    // it has benefit to check whether there was error to convert str > int.

    int *nums = (int *)malloc(sizeof(int) * size);

    int i = 2, j = 0;
    for(; i < size; i ++) {
        for(j = i + i; j < size; j += i) {
            nums[j] = 1;
        }
    }

    array_print(nums, size);

    printf("prime numbers smaller than %d: ", size);
    for(i = 2; i < size; i ++) {
        if(!nums[i]) {
            printf(" %d", i);
        }
    }
    return 0;
}



// two dimensional examples
int twoDarray(void)
{
    /* declaration of two-d arrays */
    // 1. bad examples
    // int array[][] = {{1, 2}, {1, 2}};
    // int array[][] = {{1, 2}, {1, 2}};
    int array[][2] = {{1, 2}, {1, 2}};
    int array2[2][2] = {{1, 2}, {1, 2}};

    return 0;
}


/* practice problem */
int row_column(void)
{
    int r = 0, c = 0, i, j;
    printf("input row, column size: ");
    scanf("%d %d", &r, &c);
    printf("input value: %d %d\n", r, c);
    int **matrix = (int **)malloc(sizeof(int *) * r);
    for(i = 0; i < r; i ++) {
        matrix[i] = (int *)malloc(sizeof(int) * c);
    }

    for(i = 0; i < r; i ++) {
        printf("input %d's row numbers", i);
        for(j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < r; i ++) {
        for(j = 0; j < c; j ++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < r; i ++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}