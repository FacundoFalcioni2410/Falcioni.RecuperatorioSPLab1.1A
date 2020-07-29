#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED

#include "bicicletas.h"
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[21];
    char tipo[10];
    int tiempo;
}eBicicleta;

eBicicleta* bicicletaNew();
void bicicletaDelete(eBicicleta* x);

int bicicletaSetId(eBicicleta* x, int id);
int bicicletaSetNombre(eBicicleta* x, char* nombre);
int bicicletaSetTipo(eBicicleta* x, char* tipo);
int bicicletaSetTiempo(eBicicleta* x, int tiempo);

int bicicletaGetId(eBicicleta* x, int* id);
int bicicletaGetNombre(eBicicleta* x, char* nombre);
int bicicletaGetTipo(eBicicleta* x, char* tipo);
int bicicletaGetTiempo(eBicicleta* x, int* tiempo);

eBicicleta* bicicletaNewParametros(char* id, char* nombre, char* tipo, char* tiempo);

int mostrarBicicleta(eBicicleta* x);
int mostrarBicicletas(LinkedList* this);

int getRandom(int a,int b);
void* setTiempoAleatorio(void* bicicleta);

eBicicleta* bicicletaNewParametros(char* id, char* nombre, char* tipo, char* tiempo);
#endif // BICICLETAS_H_INCLUDED
