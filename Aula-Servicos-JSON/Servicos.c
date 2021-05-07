/*
Exportar JSON para ficheiro
lufer

Adaptado de:
https://www.codeproject.com/Articles/887604/jWrite-a-really-simple-JSON-writer-in-C

*/
#include <stdio.h>
#include <string.h>
#include "jWrite.h"
#include <conio.h>
#include <stdbool.h>

#pragma warning (disable:4996)

bool  WriteFileJson(char fileName[]);
bool  WriteFileJsonII(char fileName[]);

int main() {

    bool aux = WriteFileJsonII("dados2.json");
    aux = WriteFileJson("dados1.json");
    getch();
    return 0;
 }

/// <summary>
/// Usando "biblioteca"
/// </summary>
/// <param name="fileName"></param>
/// <returns></returns>
bool  WriteFileJson(char fileName[]) {

    FILE* fp;
    char buffer[1024];
    unsigned int buflen = 1024;
    int err;
    fp = fopen(fileName, "w");
    if (!fp) return 0;
    jwOpen(buffer, buflen, JW_OBJECT, JW_PRETTY);   //// json root object
    jwObj_string("clube", "Benfica");				// add object key:value pairs
    jwObj_int("int", 1);
    jwObj_double("double", 1.234);
    jwObj_null("nullThing");
    jwObj_bool("bool", 1);
    jwObj_array("ArrayVazio");
    // empty array
    jwEnd();
    err = jwClose();
    fprintf(fp, "%s\n", buffer);
    strcpy(buffer,"");


    jwOpen(buffer, buflen, JW_OBJECT, JW_PRETTY);
    jwObj_array("anArray");					// array with elements
        jwArr_string("array one");
        jwArr_int(-2);
        jwArr_double(1234.567);
        jwArr_null();
        jwArr_bool(0);
        jwArr_object();							// object in array
            jwObj_string("obj3_one", "one");
            jwObj_string("obj3_two", "two");
        jwEnd();
        jwArr_array();							// array in array
            jwArr_int(0);
            jwArr_int(1);
            jwArr_int(2);
        jwEnd();
    jwEnd();
    err = jwClose();

    fprintf(fp, "%s", buffer);

    fclose(fp);
    return true;
}


typedef struct Dados {
    int idade;
    char nome[50];
}Dados;

/// <summary>
/// Gerar diretamento JSON
/// </summary>
/// <param name="fileName"></param>
/// <returns></returns>
bool  WriteFileJsonII(char fileName[]) {

    Dados pessoa = { 12,"António" };

    FILE* fp;
    char buffer[1024];
    unsigned int buflen = 1024;
    int err;

    fp = fopen(fileName, "w");
    if (!fp) return 0;

    fprintf(fp, "%s\n", "{");
    fprintf(fp, "\"%s\" : %d\n", pessoa.nome,pessoa.idade );
    fprintf(fp, "%s\n", "}");
    
    fclose(fp);
    return true;
}