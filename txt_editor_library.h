#ifndef _TXT_EDITOR_LIBRARY_H_
#define _TXT_EDITOR_LIBRARY_H_

#include <stdio.h>
#include <string.h>

#define G_MAX_WORD_LENGTH 256
#define G_MAX_WORDS 512

char G_STRING[G_MAX_WORDS][G_MAX_WORD_LENGTH];
char G_DECISION_STRING[G_MAX_WORD_LENGTH];
char G_DECISION_STRING_REPLACE[G_MAX_WORD_LENGTH];
unsigned int G_DECISION;
unsigned int G_FILE_LOADED;

void read_file (char file[G_MAX_WORD_LENGTH]);
void print_file ();
void save_to_file (char file[G_MAX_WORD_LENGTH]);
void find_word (char word_to_find[G_MAX_WORD_LENGTH]);
void find_number_occurrence (char word_to_find[G_MAX_WORD_LENGTH]);
void replace_word (char word_to_replace[G_MAX_WORD_LENGTH], char word_replace_with[G_MAX_WORD_LENGTH]);
void replace_word_number (char word_to_replace[G_MAX_WORD_LENGTH], char word_replace_with[G_MAX_WORD_LENGTH], unsigned int occurrence_number);
void sort_to_file_occurrence(char file[G_MAX_WORD_LENGTH]);
void sort_to_file_alphabetical(char file[G_MAX_WORD_LENGTH]);
unsigned int return_find_number_occurrence(char word_to_find[G_MAX_WORD_LENGTH]);

#endif
