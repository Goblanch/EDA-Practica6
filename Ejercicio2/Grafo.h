#pragma once
#include <iostream>
#include "Lista.h"
#include "VerticeGrafo.h"

template <typename T>
class Grafo {
private:
    Lista<VerticeGrafo<T>> vertices;

    // Busca el nodo de la lista de vértices que contiene el dato
    std::shared_ptr<Nodo<VerticeGrafo<T>>> buscarNodoVertice(const T& dato) const {
        std::shared_ptr<Nodo<VerticeGrafo<T>>> actual = vertices->getCabeza();
        while (actual != nullptr) {
            if (actual->getDato()->getDato() == dato) {
                return actual;
            }
            actual = actual->getSiguiente();
        }

        return nullptr;
    }

public:
    Grafo() {}

    bool agregarVertice(const T& dato) {
        if (buscarNodoVertice(dato) != nullptr) {
            return false;
        }
        vertices.insertarAlFinal(VerticeGrafo<T>(dato));
        return true;
    }

    // Elimina un vértice y sus aristas
    bool eliminarVertice(const T& dato) {
        // Eliminamos el dato de todas las listas de adyacencia
        std::shared_ptr<Nodo<VerticeGrafo<T>>> actual = vertices.getCabeza();
        while (actual != nullptr) {
            actual->getDato().eliminarAdyacente(dato);
            actual = actual->getSiguiente();
        }

        // Eliminamos el vértice de la lista principal
        return vertices->eliminar(VerticeGrafo<T>(dato));
    }

    bool agregarArista(const T& origen, const T& destino) {
        std::shared_ptr<Nodo<VerticeGrafo<T>>> nodoOrigen = buscarNodoVertice(origen);
        if (nodoOrigen == nullptr) return false;
        if (buscarNodoVertice(destino) == nullptr) return false;

        nodoOrigen->getDato().agregarAdyacente(destino);
        return true;
    }

    bool eliminarArista(const T& origen, const T& destino) {
        std::shared_ptr<Nodo<VerticeGrafo<T>>> nodoOrigen = buscarNodoVertice(origen);
        if (nodoOrigen == nullptr) return false;
        return nodoOrigen->getDato().eliminarAdyacente(destino);
    }

    // --- FUNCIONES DEL ENUNCIADO DE LA PRÁCTICA --------------------------------------------------------
    void mostrarRutas() const {
        std::shared_ptr<Nodo<VerticeGrafo<T>>> actual = vertices.getCabeza();
        while(actual != nullptr) {
            const VerticeGrafo<T>& vertice = actual->getDato();
            std::cout << vertice.getDato() << "\n";
            std::cout << "  Vuelos directos a:\n";

            std::shared_ptr<Nodo<T>> adyacente = vertice.getAdyacentes().getCabeza();
            if (adyacente == nullptr) {
                std::cout << "  (sin conexiones)\n";
            }else {
                while(adyacente != nullptr) {
                    std::cout << "  -> " << adyacente->getDato() << "\n";
                    adyacente = adyacente->getSiguiente();
                }
            }
            std::cout << "\n";
            actual = actual->getSiguiente();
        }
    }

    int contarDestinosDesde(const T& origen) const {
        std::shared_ptr<Nodo<VerticeGrafo<T>>> nodo = buscarNodoVertice(origen);
        if (nodo == nullptr) return -1;
        return nodo->getDato().getAdyacentes().getTamanio();
    }

    const Lista<VerticeGrafo<T>>& getVertices() const {return vertices;}
};