#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "LinkedList.h"
#include "bicicletas.h"
#include "parser.h"

void menu(int* option);

int main()
{
    srand(time(NULL));
    char path[32];
    LinkedList* bicicletas = ll_newLinkedList();
    LinkedList* bicicletasActualizado = NULL;
    LinkedList* listaFiltradaPorTipo = NULL;
    int ordenado = 0;
    int opcion;
    char confirm = 'n';

    do
    {
        do
        {
            menu(&opcion);
            switch(opcion)
            {
            case 1:
                if(ll_isEmpty(bicicletas))
                {
                    printf("Ingrese el nombre del archivo: ");
                    fflush(stdin);
                    gets(path);
                    cargarTexto(bicicletas,path);
                }
                else
                {
                    printf("\nYa se cargaron los datos\n");
                }
                break;
            case 2:
                if(!ll_isEmpty(bicicletas) && bicicletasActualizado == NULL)
                {
                    mostrarBicicletas(bicicletas);
                }
                else if(!ll_isEmpty(bicicletasActualizado))
                {
                    mostrarBicicletas(bicicletasActualizado);
                }
                else
                {
                    printf("\nPrimero debe cargar los datos (opcion 1).\n");
                }
                break;
            case 3:
                if(!ll_isEmpty(bicicletas))
                {
                    bicicletasActualizado = ll_map(bicicletas,setTiempoAleatorio);
                    printf("\nTiempos asignados con exito\n");
                }
                else
                {
                    printf("\nPrimero debe cargar los datos (opcion 1).\n");
                }
                break;
            case 4:
                if(bicicletasActualizado != NULL)
                {
                    listaFiltradaPorTipo = filtrarPorTipo(bicicletasActualizado);
                    mostrarBicicletas(listaFiltradaPorTipo);
                    printf("\nIngrese el nombre del archivo a guardar (debe incluir la extension del archivo): ");
                    fflush(stdin);
                    gets(path);
                    if(!guardarArchivo(listaFiltradaPorTipo,path))
                    {
                        printf("\nArchivo guardado con exito.\n");
                    }
                }
                else
                {
                    printf("\nPrimero debe asignar el tiempo (opcion 2).\n");
                }
                break;
            case 5:
                if(bicicletasActualizado != NULL)
                {
                    ll_sort(bicicletasActualizado,ordenarPorTipoYTiempo,1);
                    mostrarBicicletas(bicicletasActualizado);
                    ordenado = 1;
                    printf("\nLista ordenada con exito.\n");
                }
                else
                {
                    printf("\nPrimero debe asignar el tiempo (opcion 2).\n");
                }
                break;
            case 6:
                if(ordenado)
                {
                    printf("\nIngrese el nombre del archivo a guardar (debe incluir la extension del archivo): ");
                    fflush(stdin);
                    gets(path);
                    if(!guardarArchivo(bicicletasActualizado,path))
                    {
                        printf("\nArchivo guardado con exito.\n");
                    }
                }
                else
                {
                    printf("\nPrimero debe ordenar la lista (opcion 5).\n");
                }
                break;
            case 7:
                printf("Confirma salida del programa?: ");
                fflush(stdin);
                scanf("%c",&confirm);
                break;
            }
            printf("\n");
            system("pause");
            system("cls");
        }
        while(confirm != 's');
    }
    while(opcion != 7);



    return 0;
}

void menu(int* opcion)
{
    printf("\n");
    printf("1. Cargar archivo.\n");
    printf("2. Imprimir lista.\n");
    printf("3. Asignar tiempos.\n");
    printf("4. Filtrar por tipo.\n");
    printf("5. Mostrar posiciones.\n");
    printf("6. Guardar posiciones.\n");
    printf("7. Salir.\n");
    fflush(stdin);
    utn_getEntero(opcion,3,"Ingrese una opcion: ","ERROR. Opcion invalida\n",1,7);
}
