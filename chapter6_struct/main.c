#include <stdio.h>
#include <stdlib.h>

struct Point
{
    int x;
    int y;
};

/*
 * struct can use itself as member variable
 * by using pointer!
 */
struct line_corner
{
    int x;
    int y;
    struct linecorner *next;
};

#define MAX_NAME 20
#define SUBJECTS 3

typedef struct {
    char name[MAX_NAME];
    int score[SUBJECTS];
    int total;
    double average;
} Grade;

int get_grades(void);

int main() {
    struct Point pt[3] = {{1, 2}, {2, 3}, {3, 4}};
    struct Point *ptr = pt;
    // access to member variable from pointer
    // 1. get variable from  ptr
    printf("first member variable in pt is... {%d, %d}\n", (*ptr).x, (*ptr).y);

    // 2. use ->
    printf("we are able to get same value with \'-\'> ...{%d, %d}\n", (*ptr).x, (*ptr).y);

    get_grades();
    return 0;
}

/*
 * practice problem
 */
int get_grades() {
    int s_num, i, j;
    Grade *grades = NULL;

    printf("input students number\n");
    scanf("%d", &s_num);

    grades = (Grade *) malloc(sizeof(Grade) * s_num);

    for(i = 0; i < s_num; i ++) {
        printf("input %dth student's name\n", i + 1);
        scanf("%s", grades[i].name);
        printf("input student's grades\n");
        printf("english: ");
        scanf("%d", &grades[i].score[0]);
        printf("math: ");
        scanf("%d", &grades[i].score[1]);
        printf("conputer science: ");
        scanf("%d", &grades[i].score[2]);

        grades[i].total = grades[i].score[0] + grades[i].score[1] + (grades + i) -> score[2];
        printf("total is %d\n", (grades+i)->total);
        grades[i].average = (double)grades[i].total / 3;
        printf("total is %0.1lf\n", (grades+i)->average);
    }

    return 0;
}