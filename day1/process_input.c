#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    FILE * file_ptr;

    // open file
    file_ptr = fopen("puzzle_input.txt", "r");

    if (file_ptr == NULL) {
        printf("The file is not opened.");
        return 1;
    }

    // The lock can goes from 0-99 and starts at position 50
    // We need to process the combination and determine the number of times the dial is left pointing at 0.
    int dial_position = 50u;
    uint32_t answer = 0u;
    uint16_t num_of_puzzle_inputs = 4186u;

    while(!feof(file_ptr))
    {
        char * string;
        char direction;
        // Determine direction
        direction = fgetc(file_ptr);
        if ((direction != 'L') && (direction != 'R'))
        {
            printf("%c", direction);
            return 12;
        }

        // Determine number of turns
        fgets(string, 5, file_ptr);

        // Remove newline character from string
        // Unsure if this is necessary?
        // string[sizeof(string) - 1u] = NULL;

        int num_of_turns = atoi(string);
        for(int index = 0; index < num_of_turns; index++)
        {
            if ('L' == direction)
            {
                dial_position = (((dial_position - 1) + 100) % 100);
            }
            else if ('R' == direction)
            {
                dial_position = ((dial_position + 1) % 100);
            }
            
            if (0 == dial_position)
            {
                answer++;
            }
        }
    }
    printf("%d", answer);


    return 0;
}