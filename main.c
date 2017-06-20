/**

* @file main.c

* @brief Our main file where user can choose options for actions to be performed.

*

* @author  © Marica Adrian-Gabriel

*

* @date 20/06/2017

*/

#include "txt_editor_library.h"



int main(){


while(1){

    G_DECISION_STRING[0] = '\0';
    G_DECISION_STRING_REPLACE[0] = '\0';

    printf("\n\n\tMenu");

    printf("\n1. Read content from a file");
    printf("\n2. Print the content from the last read file");
    printf("\n3. Save current content to a file");
    printf("\n4. Find a word");
    printf("\n5. Find number of occurrences of a word");
    printf("\n6. Replace a word with another word");
    printf("\n7. Replace instance of a word with another word");
    printf("\n8. Sort content of a file by number of words occurrences to another file ");
    printf("\n9. Sort content of a file alphabetical to another file");
    printf("\n10. Exit");

    printf("\nChoose a number for the next step: ");
    scanf("%d", &G_DECISION);
    switch(G_DECISION){
        case 1: printf("\nFrom which file do you want to read(same folder): ");
                scanf("%s", &G_DECISION_STRING);
                read_file(G_DECISION_STRING);
                break;

        case 2: print_file();
                break;

        case 3: printf("\nTo which file do you want to save: ");
                scanf("%s", &G_DECISION_STRING);
                save_to_file(G_DECISION_STRING);
                break;

        case 4: printf("\nWhich word do you want to find: ");
                scanf("%s", &G_DECISION_STRING);
                find_word(G_DECISION_STRING);
                break;

        case 5: printf("\nFor which word do you want to find the number of occurrences: ");
                scanf("%s", &G_DECISION_STRING);
                find_number_occurrence(G_DECISION_STRING);
                break;

        case 6: printf("\nWhich word do you want to replace: ");
                scanf("%s", &G_DECISION_STRING);
                printf("\nWhat's the word you want to replace with: ");
                scanf("%s", &G_DECISION_STRING_REPLACE);
                replace_word(G_DECISION_STRING, G_DECISION_STRING_REPLACE);
                break;

        case 7: printf("\nWhich word do you want to replace: ");
                scanf("%s", &G_DECISION_STRING);
                printf("\nWhat's the word you want to replace with: ");
                scanf("%s", &G_DECISION_STRING_REPLACE);
                printf("\nWhich instance of the word do you want to replace: ");
                scanf("%d", &G_DECISION);
                replace_word_number(G_DECISION_STRING, G_DECISION_STRING_REPLACE, G_DECISION);
                break;

        case 8: printf("\nTo which file do you want to save: ");
                scanf("%s", &G_DECISION_STRING);
                sort_to_file_occurrence(G_DECISION_STRING);
                break;

        case 9: printf("\nTo which file do you want to save: ");
                scanf("%s", &G_DECISION_STRING);
                sort_to_file_alphabetical(G_DECISION_STRING);
                break;
				
		case 10: break;

        default: printf("\nInvalid step. Please try again.");
                 G_DECISION = 0;
                 break;
    }

	if(G_DECISION == 10)
		break;

}


}
