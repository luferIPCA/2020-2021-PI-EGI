/*
* Desencripta ficheiro
* lufer
* 
*/

#include <stdio.h>

#define KEY 130

#pragma warning (disable:4996)

/// <summary>
/// 
/// </summary>
/// <returns></returns>
int Decrypt(char fname[])
{
    char ch;
    FILE* fps, * fpt;

    fps = fopen(fname, "w");
    if (fps == NULL)
        return 0;
    fpt = fopen("temp.txt", "r");
    if (fpt == NULL)
        return 0;
    ch = fgetc(fpt);
    while (ch != EOF)
    {
        ch = ch - KEY;
        fputc(ch, fps);
        ch = fgetc(fpt);
    }
    fclose(fps);
    fclose(fpt);

    return 1;
}

int Decrypt2(char fname[])
{
    char ch;
    FILE* fps, * fpt;

    fps = fopen(fname, "w");
    if (fps == NULL)
        return 0;
    fpt = fopen("temp.txt", "r");
    if (fpt == NULL)
        return 0;
    ch = fgetc(fpt);
    while (ch != EOF)
    {
        ch = ch - KEY;
        fputc(ch, fps);
        ch = fgetc(fpt);
    }
    fclose(fps);
    fclose(fpt);

    return 1;
}