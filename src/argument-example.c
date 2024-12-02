#include <stdio.h>  //printf
#include <stdlib.h> //memcpy
#include <string.h> //strlen

struct sehenswuerdigkeit { int rating; char name[]; };

struct sehenswuerdigkeit t2 = { 1, { 'a' } };
int main(){
    struct sehenswuerdigkeit *s1 = malloc(sizeof (struct sehenswuerdigkeit) + 64);
    char tmp_name[] = "Der eine Turm";
    memcpy(s1->name, tmp_name, strlen(tmp_name));
    s1->rating = 2;
    printf("Rating %d, name: %s \n", s1->rating, s1->name);

    free(s1);
}