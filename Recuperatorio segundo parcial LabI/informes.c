#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "bicicletas.h"

int menuTipos()
{
    int opcion;

    printf("1. BMX.\n");
    printf("2. PLAYERA.\n");
    printf("3. MTB.\n");
    printf("4. PASEO.\n");
    utn_getEntero(&opcion,3,"Ingrese una opcion: ","ERROR. Opcion invalida\n",1,4);

    return opcion;
}

int filtrarBmx(void* x)
{
    int returnAux = 0;
    eBicicleta* auxBicicleta;
    char tipo[12];

    if(x != NULL)
    {
        auxBicicleta = (eBicicleta*) x;
        bicicletaGetTipo(auxBicicleta,tipo);
        if(!strcmp(tipo,"BMX"))
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

int filtrarPlayera(void* x)
{
    int returnAux = 0;
    eBicicleta* auxBicicleta;
    char tipo[12];

    if(x != NULL)
    {
        auxBicicleta = (eBicicleta*) x;
        bicicletaGetTipo(auxBicicleta,tipo);
        if(!strcmp(tipo,"PLAYERA"))
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

int filtrarMtb(void* x)
{
    int returnAux = 0;
    eBicicleta* auxBicicleta;
    char tipo[12];

    if(x != NULL)
    {
        auxBicicleta = (eBicicleta*) x;
        bicicletaGetTipo(auxBicicleta,tipo);
        if(!strcmp(tipo,"MTB"))
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

int filtrarPaseo(void* x)
{
    int returnAux = 0;
    eBicicleta* auxBicicleta;
    char tipo[12];

    if(x != NULL)
    {
        auxBicicleta = (eBicicleta*) x;
        bicicletaGetTipo(auxBicicleta,tipo);
        if(!strcmp(tipo,"PASEO"))
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

LinkedList* filtrarPorTipo(LinkedList* this)
{
    system("cls");
    LinkedList* listaFiltrada;
    printf("Seleccione un tipo de bicicletas:\n");

    switch(menuTipos())
    {
    case 1:
        listaFiltrada = ll_filter(this,filtrarBmx);
        break;
    case 2:
        listaFiltrada = ll_filter(this,filtrarPlayera);
        break;
    case 3:
        listaFiltrada = ll_filter(this,filtrarMtb);
        break;
    case 4:
        listaFiltrada = ll_filter(this,filtrarPaseo);
        break;
    }

    return listaFiltrada;
}

int ordenarPorTipoYTiempo(void* a, void* b)
{
    int retorno;
    eBicicleta* bicicleta1;
    eBicicleta* bicicleta2;
    char tipoB1[12];
    char tipoB2[12];
    int tiempoB1;
    int tiempoB2;

    if(a != NULL && b != NULL)
    {
        bicicleta1 = (eBicicleta*) a;
        bicicleta2 = (eBicicleta*) b;

        if(!(bicicletaGetTipo(bicicleta1,tipoB1)
                || bicicletaGetTipo(bicicleta2,tipoB2)
                || bicicletaGetTiempo(bicicleta1,&tiempoB1)
                || bicicletaGetTiempo(bicicleta2,&tiempoB2)))
        {
            if(strcmp(tipoB1,tipoB2) > 0)
            {
                retorno = 0;
            }
            else if(strcmp(tipoB1,tipoB2) == 0 && tiempoB1 < tiempoB2)
            {
                retorno = 0;
            }
        }

    }

    return retorno;
}
