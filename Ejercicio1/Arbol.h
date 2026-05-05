#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "Nodo.h"

template <typename T>
class Arbol
{
private:
    std::shared_ptr<Nodo<T>> raiz;
public:
    Arbol(): raiz(nullptr){}
    std::shared_ptr<Nodo<T>> getRaiz()
    {
        return raiz;
    }
    void setRaiz(std::shared_ptr<Nodo<T>> nuevaRaiz)
    {
        raiz = nuevaRaiz;
    }

    void inOrder(std::shared_ptr<Nodo<T>> nodo)
    {
    if (nodo != nullptr) // Si existe el nodo
    {
        inOrder(nodo->getIzquierda());
        std::cout<<nodo->getDato().codigo<<std::endl;
        inOrder(nodo->getDerecha());
    }
    }

    std::shared_ptr<Nodo<T>> espejoRecorrer(std::shared_ptr<Nodo<T>> nodo)
    {
    if (nodo == nullptr)
    {
        return nullptr;
    }
        // Necesitamos poner nodo->getDato() porque si copiamos un nodo nos da error, ya que arbol es de tipo T, no de tipo nodo. Por tanto, como dato es de tipo T (que realmente es el nodo) pues es válido
        std::shared_ptr<Nodo<T>> nuevo = std::make_shared<Nodo<T>>(nodo->getDato());
        // Ahora como vamos a hacer un espejo la izquierda estaría a la derecha y viceversa
        nuevo->setIzquierda(espejoRecorrer(nodo->getDerecha()));
        nuevo->setDerecha(espejoRecorrer(nodo->getIzquierda()));
        return nuevo;
    }

    Arbol<T> espejo() {
        Arbol<T> nuevo;
        nuevo.setRaiz(espejoRecorrer(this->raiz));
        return nuevo;
    }

    void insertarNodo(T dato)
    {
        auto nuevo = std::make_shared<Nodo<T>>(dato);
        if (raiz == nullptr)
        {
            raiz = nuevo;
            return;
        }
        auto actual = raiz;
        std::shared_ptr<Nodo<T>> padre = nullptr;
        while (actual != nullptr)
        {
            padre = actual;
            if (dato.codigo < actual->getDato().codigo)
            {
                actual = actual->getIzquierda();
            } else
            {
                actual = actual->getDerecha();
            }
        }
        if (dato.codigo < padre->getDato().codigo)
        {
           padre->setIzquierda(nuevo);
        } else
        {
            padre->setDerecha(nuevo);
        }
    }

    int calcularProfundidad(T dato)
    {
        auto actual = raiz;
        int contador = 0;
        while (actual != nullptr)
        {
            if (dato.codigo == actual->getDato().codigo)
            {
                return contador;
            }
            else if (dato.codigo < actual->getDato().codigo)
            {
                contador++;
                actual = actual->getIzquierda();
            }
            else if (dato.codigo > actual->getDato().codigo)
            {
                contador++;
                actual = actual->getDerecha();
            }

        }
        return -1;
    }
    void crearInventarioABB(const std::vector<T> &productos)
    {
        for (const auto &p : productos)
        {
            insertarNodo(p);
        }

        if (raiz == nullptr)
        {
            std::cout << "Error: el árbol está vacío" << std::endl;
        }
        else
        {
            std::cout << "Inventario en InOrden:" << std::endl;
            inOrder(raiz);
        }
    }

};