#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int menuTipos();
int filtrarBmx(void* x);
int filtrarPlayera(void* x);
int filtrarMtb(void* x);
int filtrarPaseo(void* x);
LinkedList* filtrarPorTipo(LinkedList* this);
int ordenarPorTipoYTiempo(void* a, void* b);

#endif // INFORMES_H_INCLUDED
