/*
* Finda and Replace
* lufer
* 
* Adptado de: https://ideone.com/2kgeW
* 
* memcpy:
* void *memcpy(void *dest, const void * src, size_t n)
* Copia n caracteres de origem para destino!
* https://www.tutorialspoint.com/c_standard_library/c_function_memcpy.htm
* 
* strstr:
* char *strstr(const char *fonte, const char *motivo)
* Devolve apontador para a 1ª ocorrência de "motivo" na string "fonte"
* 
* https://www.tutorialspoint.com/c_standard_library/c_function_strstr.htm
* 
*/

#include <stdio.h>
#include "regex.h"

#pragma warning (disable: 4996);

int main()
{
    FILE* input = stdin;
    FILE* output = stdout;

    char buffer[512];
    //Lê do teclado (stdin)
    while (fgets(buffer, sizeof(buffer), input) != NULL)
    {
        /* The text to find */
        static const char findText[] = "xyz";

        /* The text to replace it with */
        static const char text_to_replace[] = "abc";

        char* pos = strstr(buffer, findText);
        if (pos != NULL)
        {
            /* Allocate memory for temporary buffer */
            char* temp = calloc(
                strlen(buffer) - strlen(findText) + strlen(text_to_replace) + 1, 1);

            /* Copy the text before the text to replace */
            memcpy(temp, buffer, pos - buffer);

            /* Copy in the replacement text */
            memcpy(temp + (pos - buffer), text_to_replace, strlen(text_to_replace));

            /* Copy the remaining text from after the replace text */
            memcpy(temp + (pos - buffer) + strlen(text_to_replace),
                pos + strlen(findText),
                1 + strlen(buffer) - ((pos - buffer) + strlen(findText)));

            fputs(temp, output);

            free(temp);
        }
        else
            fputs(buffer, output);
    }

    return 0;
}