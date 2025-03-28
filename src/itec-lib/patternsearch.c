#include <string.h>

#include "itec-lib/patternsearch.h"

#include <assert.h>

void pattern_search_all(char* pattern, char* text, int* bitmap) {
    int M = strlen(pattern);
    int N = strlen(text);

    assert(M >= 0 && N >= 0);

    memset(bitmap, 0, N);

    if (M < 1 || N < 1) {
        return;
    }

    for (int i_txt = 0; i_txt <= N - M; i_txt++) {

        int j_pat = 0;

        for (j_pat = 0; j_pat < M; j_pat++) {
            if (text[i_txt + j_pat] != pattern[j_pat]) {
                break;
            }
        }

        if (j_pat == M) {
            bitmap[i_txt] = 1; 
        }
    }
}

int pattern_search(char* pattern, char* text) {
    int M = strlen(pattern);
    int N = strlen(text);

    if(N == 0 || M == 0 ){
        return -1;
    }
    
    for (int i_txt = 0; i_txt <= N - M; i_txt++) {

        int j_pat = 0;

        for (j_pat = 0; j_pat < M; j_pat++) {
            if (text[i_txt + j_pat] != pattern[j_pat]) {
                break;
            }
        }

        if (j_pat == M) {
            return i_txt;
        }
    }

    //noting found
    return -1;
}