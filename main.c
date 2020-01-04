#include "monty.h"

/**
 * 
 */
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        /** TODO:
         * If the user does not give any file or more than one argument to your program,
         * print the error message USAGE: monty file, followed by a new line,
         * and exit with the status EXIT_FAILURE
         */
        printf("USAGE: monty file");
        exit(EXIT_FAILURE);
    }
    /** TODO:
     *  Open the file
     */
    open_file(argv[1]);
    return 0;
}
