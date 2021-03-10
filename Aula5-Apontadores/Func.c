/*
* Funções que manipulam apontadores
*/
#include <stdio.h>

#pragma region UM

/// <summary>
/// 
/// </summary>
/// <param name="v"></param>
/// <param name="n"></param>
void showArray(int v[], int n) {
	int* ptr = v;
	for (int i = 0; i < n; i++)
		printf("\nv[%d]=%d", i + 1, *(ptr++));
}

/// <summary>
/// 
/// </summary>
/// <param name="v"></param>
/// <param name="n"></param>
void showArrayII(int* v, int n) {
	int* ptr = v;
	for (int i = 0; i < n; i++)
		printf("\nv[%d]=%d", i + 1, *(ptr++));
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
int f() {
	//static int tot = 0;
	//tot++;
	int a[10] = { 2,-3,5,6,18 };
	int* ptr;
	ptr = a;
	ptr[0] = 5;
	*ptr = ptr[0] * 2;
	showArrayII(a, 10);
	return 0;
}

//Analisar erro!!!
int get(int* ptr) {

	int a = 10;
	ptr = &a;
	return 0;
}

/// <summary>
/// Aloca memória
/// </summary>
/// <param name="size"></param>
/// <returns></returns>
int* getArray(int size) {
	int* val = (int*)malloc(sizeof(int) * size);
	return val;
}

#pragma endregion

#pragma region II

void changeValue(int x)
{
	x++;
}

int changeValueII(int x)
{
	return (++x);
}

/// <summary>
/// Parametros por referência
/// </summary>
/// <param name="p"></param>
void changeValueIII(int* p) {
	(*p)++;
}

/// <summary>
/// "const" impede que o valor referência se altere
/// Apenas pode ser usado..não alterado
/// </summary>
/// <param name="p"></param>
/// <returns></returns>
int changeValueIV( const int* p) {
	//*p = *p + 1;		//não é permitido
	return *p;
}

void mostraArray(int v[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d\n", v[i]);
	}
}

void mostraArrayII(int* v, int size) {
	int* p;
	p = v;			//p = &v[0]
	for (int i = 0; i < size; i++) {
		printf("%d\n", *p++);
	}
}

#pragma endregion