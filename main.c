


/**
 * C program to delete a word from file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000


void removeAll(char * str, const char * toRemove);


int main()
{
    FILE * fPtr;
    FILE * fTemp;
    
    char path[100];
    char toRemove[100];
    
    char buffer[1000];

    
    /* Input source file path path */
 
    // if you want use to choose the file
//        printf("Enter path of source file: ");
//        scanf("%s", path);
    
    
//    fgets(path, sizeof("/Users/mac/Desktop/documents/inputfile.txt"), stdin);

//    printf("Enter word to remove: ");
//    scanf("%s", toRemove);
//    fgets(toRemove, sizeof(" "), stdin);
//    toRemove[0] = getchar();
//    toRemove[1] = getchar();

//    toRemove[0] = ' ';
//    toRemove[1] = '\0';
    
    printf("\n");
    
    
    /*  Open files */
    fPtr  = fopen("input_file.txt", "r");
    fTemp = fopen("output_file.txt", "w");

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }

    
    if (fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\n2Unable to open file.\n");
        printf("2Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }

    /*
     * Read line from source file and write to destination
     * file after removing given word.
     */
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        printf("1. %s\n",buffer);

        // Remove all occurrence of word from current line
        removeAll(buffer, toRemove);
        printf("2. %s\n",buffer);

        // Write to temp file
        fputs(buffer, fTemp);
        printf("3. %s\n",buffer);
    }


    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);


    /* Delete original source file */
//    remove(path);

    /* Rename temp file as original file */
    rename("delete.tmp", path);


    printf("\nAll occurrence of '%s' removed successfully.\n", toRemove);

    return 0;
}



/**
 * Remove all occurrences of a given word in string.
 */
void removeAll(char * str, const char * toRemove)
{
    int strIndex, compareIndex, stringLen, toRemoveLen;
    int found;

    stringLen   = strlen(str);      // Length of string
    toRemoveLen = strlen(toRemove); // Length of word to remove


    for(strIndex=0; strIndex <= stringLen - toRemoveLen; strIndex++)
    {
        /* Match word with string */
        // i = first letter of the word.
        found = 1;
        for(compareIndex=0; compareIndex < toRemoveLen; compareIndex++)
        {
            //j = letter of the detected word.
            if(str[strIndex + compareIndex] != toRemove[compareIndex])
            {
                found = 0;
                printf("--strIndex = %d, compareIndex = %d--\n",strIndex,compareIndex); // test to understand how for loop works
                // you can remove these printf, they have nothing to do with removing progress
                printf(" %c, %c\n",str[strIndex + compareIndex],toRemove[compareIndex]);// test to understand how for loop works
                break;
            }
            
            if(str[strIndex + compareIndex] == toRemove[compareIndex])
            {
                printf("--strIndex = %d, compareIndex = %d--\n",strIndex,compareIndex); // test to understand how for loop works
                printf(" %c, %c\n",str[strIndex + compareIndex],toRemove[compareIndex]);// test to understand how for loop works
            }
        }

        /* If it is not a word */
        if(str[strIndex + compareIndex] != ' ' && str[strIndex + compareIndex] != '\t' && str[strIndex + compareIndex] != '\n' && str[strIndex + compareIndex] != '\0')
        {
            found = 0;
            printf("%c\n",str[strIndex+compareIndex]); //test to understand how for loop works
            printf("__1__\n"); //test to understand how for loop works
        }

        /*
         * If word is found then shift all characters to left
         * and decrement the string length
         */
        if(found == 1)
        {
            printf("Found!\n");
            for(compareIndex=strIndex; compareIndex <= stringLen - toRemoveLen; compareIndex++)
            {
                str[compareIndex] = str[compareIndex + toRemoveLen+1]; // remember why +1
                printf(" %c",str[compareIndex]); //test to understand how for loop works
                printf("(compareIndex = %d)\n",compareIndex); //test to understand how for loop works
            }

            stringLen = stringLen - toRemoveLen;
            printf("__2__\n"); //test to understand how for loop works
            // We will match next occurrence of word from current index.
            strIndex--;
        }
        printf("\n");
    }
    printf("<<<strIndex = %d, j=%d.>>>\n",strIndex,compareIndex); //test to understand how for loop works
}
//  /Users/mac/Desktop/documents/inputfile.txt

