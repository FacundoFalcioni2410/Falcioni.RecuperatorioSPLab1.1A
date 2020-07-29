#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "bicicletas.h"

eBicicleta* bicicletaNew()
{
    return (eBicicleta*) malloc(sizeof(eBicicleta));
}

void bicicletaDelete(eBicicleta* x)
{
    free(x);
    x = NULL;
}

/*////////////////////////////////////////////////////////
                           SETTERS
////////////////////////////////////////////////////////*/

int bicicletaSetId(eBicicleta* x, int id)
{
    int todoOk = 1;

    if(x != NULL && id > 0)
    {
        x->id = id;
        todoOk = 0;
    }

    return todoOk;
}

int bicicletaSetNombre(eBicicleta* x, char* nombre)
{
    int todoOk = 1;

    if(x != NULL && nombre != NULL)
    {
        strcpy(x->nombre,nombre);
        todoOk = 0;
    }

    return todoOk;
}

int bicicletaSetTipo(eBicicleta* x, char* tipo)
{
    int todoOk = 1;

    if(x != NULL && tipo != NULL)
    {
        strcpy(x->tipo,tipo);
        todoOk = 0;
    }

    return todoOk;
}

int bicicletaSetTiempo(eBicicleta* x, int tiempo)
{
    int todoOk = 1;

    if(x != NULL && tiempo >= 0)
    {
        x->tiempo = tiempo;
        todoOk = 0;
    }

    return todoOk;
}


/*////////////////////////////////////////////////////////
                           GETTERS
////////////////////////////////////////////////////////*/


int bicicletaGetId(eBicicleta* x, int* id)
{
    int todoOk = 1;

    if(x != NULL && id != NULL)
    {
        *id = x->id;
        todoOk = 0;
    }

    return todoOk;
}


int bicicletaGetNombre(eBicicleta* x, char* nombre)
{
    int todoOk = 1;

    if(x != NULL && nombre != NULL)
    {
        strcpy(nombre,x->nombre);
        todoOk = 0;
    }

    return todoOk;
}


int bicicletaGetTipo(eBicicleta* x, char* tipo)
{
    int todoOk = 1;

    if(x != NULL && tipo != NULL)
    {
        strcpy(tipo,x->tipo);
        todoOk = 0;
    }

    return todoOk;
}

int bicicletaGetTiempo(eBicicleta* x, int* tiempo)
{
    int todoOk = 1;

    if(x != NULL && tiempo != NULL)
    {
        *tiempo = x->tiempo;
        todoOk = 0;
    }

    return todoOk;
}

eBicicleta* bicicletaNewParametros(char* id, char* nombre, char* tipo, char* tiempo)
{
    eBicicleta* newBicicleta = NULL;

    newBicicleta = bicicletaNew();

    if(bicicletaSetId(newBicicleta,atoi(id))
            ||  bicicletaSetNombre(newBicicleta,nombre)
            ||  bicicletaSetTipo(newBicicleta,tipo)
            ||  bicicletaSetTiempo(newBicicleta,atoi(tiempo)))
    {
        bicicletaDelete(newBicicleta);
    }

    return newBicicleta;
}

int mostrarBicicleta(eBicicleta* x)
{
    int todoOk = 1;

    int id;
    char nombre[21];
    char tipo[21];
    int tiempo;

    if(x != NULL)
    {
        if(!(bicicletaGetId(x,&id)
                || bicicletaGetNombre(x,nombre)
                || bicicletaGetTipo(x,tipo)
                || bicicletaGetTiempo(x,&tiempo)))
        {
            printf("%2d  %15s %8s  %6d\n",id,nombre,tipo,tiempo);
            todoOk = 0;
        }
    }

    return todoOk;
}

int mostrarBicicletas(LinkedList* this)
{
    int todoOk = 1;
    int len;
    eBicicleta* auxBicicleta;

    system("cls");

    if(this != NULL)
    {
        len = ll_len(this);

        for(int i = 0; i < len; i++)
        {
            auxBicicleta = (eBicicleta*) ll_get(this,i);

            if(auxBicicleta != NULL)
            {
                mostrarBicicleta(auxBicicleta);
                todoOk = 0;
            }
        }

        if(todoOk)
        {
            printf("\nNo hay bicicletas para mostrar\n");
        }
    }
    return todoOk;
}

int getRandom(int a,int b)
{
    int aleatorio;

    aleatorio = rand()%(a)+b;

    return aleatorio;
}

void* setTiempoAleatorio(void* bicicleta)
{
    eBicicleta* auxBicicleta;
    void* pElement;
    int aleatorioTiempo;

    if(bicicleta != NULL)
    {
        auxBicicleta = (eBicicleta*) bicicleta;
        aleatorioTiempo = getRandom(71,50);

        if(bicicletaSetTiempo(auxBicicleta,aleatorioTiempo))
        {
            pElement = NULL;
        }
        else
        {
            pElement = (void*) auxBicicleta;
        }
    }

    return pElement;
}
