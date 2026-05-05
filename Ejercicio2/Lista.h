#pragma once
#include <memory>
#include <stdexcept>
#include "Nodo.h"

template <typename T>
class Lista {
private:
    std::shared_ptr<Nodo<T>> cabeza;
    int tamanio;

public:
    Lista() : cabeza(nullptr), tamanio(0) {}

    bool estaVacia() const {
        return cabeza == nullptr;
    }

    int getTamanio() const {return tamanio;}

    std::shared_ptr<Nodo<T>> getCabeza() const {return cabeza;}

    // Busca un elemento por valor. T tiene que sobrecargar ==
    bool contiene(const T& dato) const {
        std::shared_ptr<Nodo<T>> actual = cabeza;
        while (actual != nullptr) {
            if (actual->getdato() == dato) {
                return true;
            }
            actual = actual->getsiguiente();
        }

        return false;
    }

    void insertarAlPrincipio(const T& dato) {
        std::shared_ptr<Nodo<T>> nuevo = std::make_shared<Nodo<T>>(dato);
        nuevo->setSiguiente(cabeza);
        cabeza = nuevo;
        tamanio++;
    }

    void insertarAlFinal(const T& dato) {
        std::shared_ptr<Nodo<T>> nuevo = std::make_shared<Nodo<T>>(dato);
        if (estaVacia()) {
            cabeza = nuevo;
            return;
        }
        std::shared_ptr<Nodo<T>> actual = cabeza;
        while (actual->getSiguiente() != nullptr) {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nuevo);
        tamanio++;
    }

    bool eliminar(const T& dato) {
        if (estaVacia()) return false;

        // Dato en la cabeza
        if (cabeza->getdato() == dato) {
            cabeza = cabeza->getSiguiente();
            tamanio--;
            return true;
        }

        // Dato en resto de la fila
        std::shared_ptr<Nodo<T>> anterior = cabeza;
        std::shared_ptr<Nodo<T>> actual = cabeza->getSiguiente();
        while (actual != nullptr) {
            if (actual->getData() == dato) {
                anterior->setSiguiente(actual->getSiguiente());
                tamanio--;
                return true;
            }
            anterior = actual;
            actual = actual->getSiguiente();
        }

        return false;
    }
};