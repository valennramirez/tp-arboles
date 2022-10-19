#include "libArboles.h"
#include <stdio.h>
#include <stdlib.h>

///1
nodoArbol *inicArbol()
{
    return NULL;
}

nodoArbol *crearNodo (int legajo, int edad, char nombre[])
{
    nodoArbol *aux= (nodoArbol*)malloc(sizeof(nodoArbol));

    aux->dato.edad=edad;
    aux->dato.legajo=legajo;
    strcpy(aux->dato.nombre, nombre);

    aux->der=NULL;
    aux->izq=NULL;

    return aux;
}

nodoArbol *insertar (nodoArbol *arbol, nodoArbol *nn)
{
    if (arbol==NULL)
    {
        arbol=nn;
    }
    else
    {
        if (arbol->dato.legajo>nn->dato.legajo)
        {
            arbol->izq=insertar(arbol->izq, nn);
        }
        else
        {
            arbol->der=insertar(arbol->der, nn);
        }
    }

    return arbol;
}
///2
void mostrarNodo (nodoArbol *nodo)
{
    printf ("Legajo: %d", nodo->dato.legajo);
    printf ("Nombre: %s", nodo->dato.nombre);
    printf ("Edad: %d", nodo->dato.edad);
}

void mostrarPreorder (nodoArbol *arbol)
{
    if(arbol!=NULL)
    {
        mostrarNodo(arbol);
        mostrarPreorder(arbol->izq);
        mostrarPreorder(arbol->der);
    }
}

void mostrarInorder (nodoArbol *arbol)
{
    if(arbol!=NULL)
    {
        mostrarInorder(arbol->izq);
        mostrarNodo(arbol);
        mostrarInorder(arbol->der);
    }
}

void mostrarPostorden (nodoArbol *arbol)
{
    if(arbol!=NULL)
    {
        mostrarPostorden(arbol->izq);
        mostrarPostorden(arbol->der);
        mostrarNodo(arbol);
    }
}

///3

nodoArbol *pasarArbol_Lista (nodoArbol *arbol, nodoArbol *lista) ///der=sig
{
    if (arbol!=NULL)
    {
        if(lista==NULL)
        {
            arbol->izq=pasarArbol_Lista(arbol->izq, lista);
            lista=arbol->izq;
        }
        else
        {
            lista->der=pasarArbol_Lista(arbol->izq, lista);
        }
    }

    return lista;
}

///4

nodoArbol *buscarPorLegajo (int legajo, nodoArbol *arbol)
{
    nodoArbol *rta=NULL;

    if (arbol!=NULL)
    {
        if (arbol->dato.legajo==legajo)
        {
            rta=arbol;
        }
        else
        {
            if (arbol->dato.legajo>legajo)
            {
                rta=buscarPorLegajo(legajo, arbol->izq);
            }
            else
            {
                rta=buscarPorLegajo(legajo, arbol->der);
            }
        }
    }

    return rta;
}

///5
///6
///7

int cantidadDeNodos (nodoArbol *arbol)
{
    int cant;

    if (arbol!=NULL)
    {
        cant=cantidadDeNodos (arbol->izq);
        cant++;
        cant=cantidadDeNodos(arbol->der);
    }

    return cant;
}

///8

int cantidadDeHojas (nodoArbol *arbol)
{
    int cant;

    if (arbol!=NULL)
    {
        if(arbol->izq==NULL && arbol->der==NULL)
        {
            cant=cant+1;
        }
        else
        {
            arbol=cantidadDeHojas(arbol->izq);
            arbol=cantidadDeHojas(arbol->der);
        }
    }
}

///9
