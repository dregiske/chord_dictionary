#include "chord_dictionary.h"
#include "chord_dictionary.c"

/**
 * This is the main file.
 * It uses the header declaration file chord_dictionary.h
 * and the chord_dictionary.c file to run this program.
 */
#define MAX_INPUT 100

/**
 * This is the main() function.
 * This is where the input is read from the user
 * to interpret what they want to do with the dictionary.
 */
int main(){

    char input[MAX_INPUT];
    while(1){
        printf("\n");
        printf("How may I assist you? (Choose a chord to lookup or 'q' to quit).\n");

        if(fgets(input, MAX_INPUT, stdin) == NULL){
            printf("Error reading input.\n");
            return 1;
        }

        printf("\n");

        input[strcspn(input, "\n")] = 0;

        if(strcmp(input, "q") == 0 || strcmp(input, "Q") == 0){
            printf("Closing application. . .\n");
            break;
        }

        // C chords
        else if(strcmp(input, "cmaj") == 0){
            CMajor();
        }
        else if(strcmp(input, "cmin") == 0){
            CMinor();
        }

        // D chords
        else if(strcmp(input, "dmaj") == 0){
            DMajor();
        }
        else if(strcmp(input, "dmin") == 0){
            DMinor();
        }

        // E chords
        else if(strcmp(input, "emaj") == 0){
            EMajor();
        }
        else if(strcmp(input, "emin") == 0){
            EMinor();
        }

        // F chords
        else if(strcmp(input, "fmaj") == 0){
            FMajor();
        }
        else if(strcmp(input, "fmin") == 0){
            FMinor();
        }

        // G chords
        else if(strcmp(input, "gmaj") == 0){
            GMajor();
        }
        else if(strcmp(input, "gmin") == 0){
            GMinor();
        }

        // A chords
        else if(strcmp(input, "amaj") == 0){
            AMajor();
        }
        else if(strcmp(input, "amin") == 0){
            AMinor();
        }

        // B chords
        else if(strcmp(input, "bmaj") == 0){
            BMajor();
        }
        else if(strcmp(input, "bmin") == 0){
            BMinor();
        }

        // Invalid input
        else{
            printf("Invalid. Usage example: 'cmaj' for C major. 'cmin' for C minor.\n");
        }
    }
    return 0;
}