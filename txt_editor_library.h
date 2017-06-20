/**

* @file txt_editor_library.h

* @brief Main header of our program where we can find the declaration of our functions.

*

* @author  © Marica Adrian-Gabriel

*

* @date 20/06/2017

*/
#ifndef _TXT_EDITOR_LIBRARY_H_
#define _TXT_EDITOR_LIBRARY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define G_MAX_WORD_LENGTH 256 /*!< Maximum length of a word */
#define G_MAX_WORDS 512 /*!< Maximum words that will be read */

char G_STRING[G_MAX_WORDS][G_MAX_WORD_LENGTH]; /*!< Our array where we will store our text*/
char G_DECISION_STRING[G_MAX_WORD_LENGTH]; /*!< Decision from our main file*/
char G_DECISION_STRING_REPLACE[G_MAX_WORD_LENGTH]; /*!< Decision from main file regarding which file to replace*/
char G_CURRENT_FILE[G_MAX_WORD_LENGTH]; /*!< Current file that we read text from*/
unsigned int G_DECISION; /*!< Decision from our main file regarding which option to choose*/
unsigned int G_FILE_LOADED; /*!< Global variable that checks if at least one file has been loaded */

/*!
 * Heads of our functions
 */

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
