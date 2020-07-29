#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"

int cargarTexto(LinkedList* lista, char* path);
int guardarArchivo(LinkedList* this, char* path);
#endif // PARSER_H_INCLUDED
