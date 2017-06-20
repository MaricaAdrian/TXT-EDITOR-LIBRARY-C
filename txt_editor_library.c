/**

* @file txt_editor_library.c

* @brief This file contains all functions that are used in the main file.


*

* @author  © Marica Adrian-Gabriel

*

* @date 20/06/2017

*/
#include "txt_editor_library.h"


/**

* This function is made for reading all content from a file and storing it.

*

* @param file File from where we will read our content.

*

*/
void read_file (char file[G_MAX_WORD_LENGTH]) {

    unsigned int counter = 0;
    FILE *f = fopen(file, "r");

    if (f == NULL)
    {
        printf("\nError opening file!");
		return;
    }

	strcpy(G_CURRENT_FILE, file);

    while (fscanf(f, " %255s", G_STRING[counter]) == 1 && counter != G_MAX_WORDS) {
        ++counter;
    }
	
    fclose(f);

	if(counter > 0){
		G_FILE_LOADED++;
		printf("\nFile read successfully.");
	} else {
		printf("\nNo words found in the file.");
	}

}

/**

* Function that is printing all stored content to the console.

*

*/
void print_file(){
	
	FILE *f = fopen(G_CURRENT_FILE, "r");
	char aux;

	if(G_FILE_LOADED == 0){

		printf("\nNo file loaded. Read a file before trying to do operations.");
		return;

	}

	printf("\nYour file content is: ");

	while(!feof(f)){
        aux = fgetc(f);
		printf("%c", aux);
    }
	
	fclose(f);

}

/**

* Function that is saving our file.

* @param file File where our content will be saved.

*/

void save_to_file(char file[G_MAX_WORD_LENGTH]){

	if(G_FILE_LOADED == 0){

		printf("\nNo file loaded. Read a file before trying to do operations.");
		return;

	}

    int counter = 0;

    FILE *f = fopen(file, "w+");

    if (f == NULL)
    {
        printf("\nError saving to file!");
        return;
    }

    while(G_STRING[counter][0] != '\0'){

        fprintf(f, "%s ", G_STRING[counter]);
        ++counter;

    }

    fclose(f);

    printf("\nYour content has been saved to file \"%s\".", file);

}

/**

* Function that is searching through our content and tries to find the given word. Prints information about the given word.

* @param word_to_find The word we want to find.

*/

void find_word(char word_to_find[G_MAX_WORD_LENGTH]){

	if(G_FILE_LOADED == 0){

		printf("\nNo file loaded. Read a file before trying to do operations.");
		return;

	}


    unsigned int counter = 0;
    unsigned int position_of_instances[G_MAX_WORDS] = {0};
    unsigned int instances = 0;

    while(G_STRING[counter][0] != '\0'){

        if(strcmp(word_to_find, G_STRING[counter]) == 0){
            position_of_instances[instances++] = counter + 1;
        }

        ++counter;

    }

    if(instances == 0){
        printf("\nWord \"%s\" is not present in the text.", word_to_find);
    } else if(instances == 1) {

        printf("\nOne instance of the word \"%s\" was found in the text, word with number %d.", word_to_find, position_of_instances[0]);

    } else {

        printf("\nMultiple instances of the word \"%s\" were found.", word_to_find);
        for(counter = 0; counter < instances; counter++){

            switch(counter){
                case 0: printf("\nFirst instance of the word \"%s\" is the word with number %d.", word_to_find, position_of_instances[counter]);
                        break;
                case 1: printf("\nSecond instance of the word \"%s\" is the word with number %d.", word_to_find, position_of_instances[counter]);
                        break;
                case 2: printf("\nThird instance of the word \"%s\" is the word with number %d.", word_to_find, position_of_instances[counter]);
                        break;
                default: printf("\n%dth instance of the word \"%s\" is the word with number %d.", counter + 1,word_to_find, position_of_instances[counter]);
                        break;
            }

        }

    }
}

/**

* Function that is printing the number of occurrences of a word in our file.

* @param word_to_find The word we want to find occurrences for.

*/

void find_number_occurrence(char word_to_find[G_MAX_WORD_LENGTH]){

	if(G_FILE_LOADED == 0){

		printf("\nNo file loaded. Read a file before trying to do operations.");
		return;

	}


    unsigned int counter = 0;
    unsigned int occurrence = 0;

    while(G_STRING[counter][0] != '\0'){

        if(strcmp(word_to_find, G_STRING[counter]) == 0){
            ++occurrence;
        }

        ++counter;

    }

    if(occurrence == 0){
        printf("\nWord \"%s\" is not present in the text.", word_to_find);
    } else {

        printf("\nNumber of occurrences for the word \"%s\" is %d.", word_to_find, occurrence);

    }
}

/**

* Function that is replacing all words that are the same with our given word with another given word.

* @param word_to_replace The word we want to be replaced.

* @param word_replace_with The word that will take place of our old word.

*/

void replace_word(char word_to_replace[G_MAX_WORD_LENGTH], char word_replace_with[G_MAX_WORD_LENGTH]){

	if(G_FILE_LOADED == 0){

		printf("\nNo file loaded. Read a file before trying to do operations.");
		return;

	}


    unsigned int counter = 0;
    unsigned int occurence = 0;


    while(G_STRING[counter][0] != '\0'){

        if(strcmp(word_to_replace, G_STRING[counter]) == 0){
            strcpy(G_STRING[counter], word_replace_with);
            ++occurence;
        }

        ++counter;

    }

    if(occurence != 0){
        printf("\n%d occurrences of the word \"%s\" replaced with \"%s\".", occurence, word_to_replace, word_replace_with);
    } else {
        printf("\nWord \"%s\" is not present in the text.", word_to_replace);
    }

}

/**

* Function that is replacing the occurrence X of an word with another given word.

* @param word_to_replace The word we want to be replaced.

* @param word_replace_with The word that will take place of our old word.

* @param occurrence_number The nth occurrence that we want to replace.

*/

void replace_word_number(char word_to_replace[G_MAX_WORD_LENGTH], char word_replace_with[G_MAX_WORD_LENGTH], unsigned int occurrence_number){

	if(G_FILE_LOADED == 0){

		printf("\nNo file loaded. Read a file before trying to do operations.");
		return;

	}


    unsigned int counter = 0;
    unsigned int occurence = 0;


    while(G_STRING[counter][0] != '\0'){

        if(strcmp(word_to_replace, G_STRING[counter]) == 0){

            ++occurence;
        }

        if(occurence == occurrence_number && strcmp(word_to_replace, G_STRING[counter]) == 0){
            strcpy(G_STRING[counter], word_replace_with);
            printf("\nThe occurrence %d of the word \"%s\" was replaced with \"%s\".", occurrence_number, word_to_replace, word_replace_with);
            return;
        }

        ++counter;

    }

    if(occurence != 0){
        printf("\n%d occurrence of the word \"%s\" does not exist.", occurrence_number, word_to_replace);
    } else {
        printf("\nWord \"%s\" is not present in the text.", word_to_replace);
    }

}

/**

* Function that is sorting to a file our content by the number of occurrences of the current word.

* @param file File where our words and their number of occurrences will be stored.

*/

void sort_to_file_occurrence(char file[G_MAX_WORD_LENGTH]){

	if(G_FILE_LOADED == 0){

		printf("\nNo file loaded. Read a file before trying to do operations.");
		return;

	}


    unsigned int first_counter = 0;
    unsigned int second_counter = first_counter + 1;
    unsigned int max = 0;
    unsigned int aux;
    unsigned int i;
    unsigned int j;
    char G_STRING_SORTED[G_MAX_WORDS * 2][G_MAX_WORD_LENGTH * 2];
    char G_STRING_SORTED_LIST[G_MAX_WORDS * 2][G_MAX_WORD_LENGTH * 2];
    char G_AUX_WORD[G_MAX_WORD_LENGTH * 2];
    unsigned int sorted_list[G_MAX_WORDS] = {0};

    while(G_STRING[first_counter][0] != '\0'){

        strcpy(G_STRING_SORTED[first_counter], G_STRING[first_counter]);
        ++first_counter;
        ++max;
    }

    first_counter = 0;


    while(G_STRING_SORTED[first_counter][0] != '\0' && first_counter != max - 2){
            second_counter = first_counter + 1;
            while(G_STRING_SORTED[second_counter][0] != '\0' && second_counter != max - 1) {
                if (strcmp(G_STRING_SORTED[first_counter], G_STRING_SORTED[second_counter]) > 0) {
                    strcpy(G_AUX_WORD, G_STRING_SORTED[first_counter]);
                    strcpy(G_STRING_SORTED[first_counter], G_STRING_SORTED[second_counter]);
                    strcpy(G_STRING_SORTED[second_counter], G_AUX_WORD);
                }
                ++second_counter;
            }
            ++first_counter;
    }

    first_counter = 0;




    FILE *f = fopen(file, "w+");


    if (f == NULL)
    {
        printf("\nError saving to file!");
        return;
    }

    while(G_STRING_SORTED[first_counter][0] != '\0'){

        if(strcmp(G_STRING_SORTED[first_counter],G_STRING_SORTED[first_counter + 1]) < 0){
            strcpy(G_STRING_SORTED_LIST[first_counter], G_STRING_SORTED[first_counter]);
            sorted_list[first_counter] = return_find_number_occurrence(G_STRING_SORTED_LIST[first_counter]);
        }
        ++first_counter;

    }


    for(i = 0; i < G_MAX_WORDS - 1; i++){
        if(sorted_list[i] != 0){
            for(j = i + 1; j < G_MAX_WORDS; j++){
                if(sorted_list[i] < sorted_list[j]){
                    strcpy(G_AUX_WORD, G_STRING_SORTED_LIST[i]);
                    strcpy(G_STRING_SORTED_LIST[i],G_STRING_SORTED_LIST[j]);
                    strcpy(G_STRING_SORTED_LIST[j], G_AUX_WORD);
                    aux = sorted_list[i];
                    sorted_list[i] = sorted_list[j];
                    sorted_list[j] = aux;
                }

            }
        }
    }

    for(i = 0; i < G_MAX_WORDS; i++){
        if(sorted_list[i] != 0){
            fprintf(f,"\n%s - %d", G_STRING_SORTED_LIST[i], sorted_list[i]);
        }
     }

    printf("\nA sorted list of words by the number of occurrences was saved in the document \"%s\".", file);

    fclose(f);

}

/**

* Function that is sorting to a file our content in a alphabetical order.

* @param file File where our sorted words will be stored.

*/

void sort_to_file_alphabetical(char file[G_MAX_WORD_LENGTH]){

	if(G_FILE_LOADED == 0){

		printf("\nNo file loaded. Read a file before trying to do operations.");
		return;

	}


    unsigned int first_counter = 0;
    unsigned int second_counter = first_counter + 1;
    unsigned int max = 0;
    char G_STRING_SORTED[G_MAX_WORDS * 2][G_MAX_WORD_LENGTH * 2];
    char G_AUX_WORD[G_MAX_WORD_LENGTH * 2];

    while(G_STRING[first_counter][0] != '\0'){

        strcpy(G_STRING_SORTED[first_counter], G_STRING[first_counter]);
        ++first_counter;
        ++max;
    }

    first_counter = 0;


    while(G_STRING_SORTED[first_counter][0] != '\0' && first_counter != max - 2){
            second_counter = first_counter + 1;
            while(G_STRING_SORTED[second_counter][0] != '\0' && second_counter != max - 1) {
                if (strcmp(G_STRING_SORTED[first_counter], G_STRING_SORTED[second_counter]) > 0) {
                    strcpy(G_AUX_WORD, G_STRING_SORTED[first_counter]);
                    strcpy(G_STRING_SORTED[first_counter], G_STRING_SORTED[second_counter]);
                    strcpy(G_STRING_SORTED[second_counter], G_AUX_WORD);
                }
                ++second_counter;
            }
            ++first_counter;
    }

    first_counter = 0;


    FILE *f = fopen(file, "w+");


    if (f == NULL)
    {
        printf("\nError saving to file!");
        return;
    }

    while(G_STRING_SORTED[first_counter][0] != '\0'){

        if(strcmp(G_STRING_SORTED[first_counter],G_STRING_SORTED[first_counter + 1]) < 0){
            fprintf(f,"\n%s", G_STRING_SORTED[first_counter]);
        }
        ++first_counter;
    }


    printf("\nA sorted list of words by alphabetical order was saved in the document \"%s\".", file);

    fclose(f);

}

/**

* Function that is returning the number of occurrences of a word.

* @param word_to_find The word we want to find his number of occurrences.

* @return Number of occurrences of the given word.

*/

unsigned int return_find_number_occurrence(char word_to_find[G_MAX_WORD_LENGTH]){

	if(G_FILE_LOADED == 0){

		printf("\nNo file loaded. Read a file before trying to do operations.");
		return;

	}


    unsigned int counter = 0;
    unsigned int occurrence = 0;

    if(strlen(word_to_find) == 0 || word_to_find[0] == '\0' ){
        return 0;
    }

    while(G_STRING[counter][0] != '\0'){

        if(strcmp(word_to_find, G_STRING[counter]) == 0){
            ++occurrence;
        }

        ++counter;

    }

    return occurrence;

}

