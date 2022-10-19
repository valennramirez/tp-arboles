#ifndef LIBARBOLES_H_INCLUDED
#define LIBARBOLES_H_INCLUDED


typedef struct
{
     int legajo;
     char nombre[20];
     int edad;

} persona;
typedef struct
{
     persona dato;
     struct nodoArbol * izq;
     struct nodoArbol * der;

} nodoArbol;






#endif // LIBARBOLES_H_INCLUDED
