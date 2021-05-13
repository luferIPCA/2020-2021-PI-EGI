/*
* Expressões Regulares
* Biblioteca POSIX
* Ver: https://www.educative.io/edpresso/how-to-write-regular-expressions-in-c
* lufer
**/

#include <stdio.h>
#include "regex.h"

#pragma warning (disable: 4996);

void printResult(int return_value) {
    if (return_value == 0) {
        printf("Pattern found.\n");
    }
    else if (return_value == REG_NOMATCH) {
        printf("Pattern not found.\n");
    }
    else {
        printf("An error occured.\n");
    }
}

int main2() {
    regex_t regex;
    int return_value;
    int return_value2;
    return_value = regcomp(&regex, "ice", 0);
    return_value = regexec(&regex, "icecream", 0, NULL, 0);
    return_value2 = regcomp(&regex, "ice", 0);
    return_value2 = regexec(&regex, "frozen yoghurt", 0, NULL, 0);
    printResult(return_value);
    printResult(return_value2);

    char name[15];
    // Taking a name as an input.
    // name can only include alphabets
    puts("Nome: ");
    scanf("%[a-zA-Z ]", name);
    printf("%s", name);

    return 0;
}