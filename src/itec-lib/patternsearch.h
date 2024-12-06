#pragma once

/**
 * Finds all occurrences of the pattern in the text and
 * marks the positions with 1 in the bitmap
 * 
 * @param pattern: string containing the search pattern
 * @param text: string containing the hole text
 * @param bitmap: bitmap as return structure. The bitmap has to have the same size as the length of text.
 * 
 */
void pattern_search_all(char* pattern, char* text, int* bitmap);

/**
 * Finds the first occurrences of the pattern in the text and
 * marks the positions with 1 in the bitmap
 * 
 * @param pattern: string containing the search pattern
 * @param text: string containing the hole text
 * 
 * @return the first index in text where the pattern matches. If no match was found it returns -1.
 */
int pattern_search(char* pattern, char* text);