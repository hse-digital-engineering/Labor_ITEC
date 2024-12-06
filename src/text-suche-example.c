
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "itec-lib/patternsearch.h"
#include "itec-lib/itec.h"

int main() {
    char text[] = "ottos mops trotzt\n ottotto: fort mops fort\n ... Ernst Jandl"; 
    char pattern[] = "otto";

    int *bitmap; //typ :int *

    int text_length = strlen(text);
    bitmap = malloc(text_length * sizeof(int)); //dynamische speicher alloc auf dem heap muss wieder freigegeben werden

    pattern_search_all(pattern, text, bitmap);

    printf("Text length is %i\n", text_length);
    printf("Found pattern at:\n");
    printf_array(text_length, bitmap);

    free(bitmap); //Freigabe des Speichers

    return 0;
}