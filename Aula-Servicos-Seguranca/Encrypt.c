/*
Encriptar ficheiro
lufer
*/

#include <stdio.h>
#include <conio.h>

#define KEY 130

#pragma warning (disable:4996)

/// <summary>
/// 
/// </summary>
/// <param name="fname"></param>
/// <returns></returns>
int Encript(char fname[])
{
    char  ch;
    FILE *fps, *fpt;

    fps = fopen(fname, "r");
    if (fps == NULL)
        return 0;

    //ficheiro temporário
    fpt = fopen("temp.txt", "w");
    if (fpt == NULL)
        return 0;

    //lê ficheiro carater a caracter
    ch = fgetc(fps);
    while (ch != EOF)
    {
        ch = ch + KEY;
        fputc(ch, fpt);
        ch = fgetc(fps);
    }
    fclose(fps);
    fclose(fpt);

    //"destroi" ficheiro original e cria novo encriptado
    fps = fopen(fname, "w");
    if (fps == NULL)
        return 0;
    fpt = fopen("temp.txt", "r");
    if (fpt == NULL)
        return 0;
    ch = fgetc(fpt);
    while (ch != EOF)
    {
        ch = fputc(ch, fps);
        ch = fgetc(fpt);
    }
    fclose(fps);
    fclose(fpt);

    return 1;
}

int Encript2(char src[]) {
    FILE* fs, * ft;
    char tgt[50];
    char ch;

    fs = fopen(src, "r");
    if (fs == NULL)
    {     
        return 0;
    }
    //Cria novo nome a partir do nome original do ficheiro
    sprintf(tgt, "%s.cry", src); 

    ft = fopen(tgt, "w");
    while ((ch = fgetc(fs)) != EOF)
        fputc(~ch, ft);         //complemento para 1
    fclose(fs);
    fclose(ft);
    remove(src);
    rename(tgt, src);
    return 1;
}