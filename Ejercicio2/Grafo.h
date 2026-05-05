#pragma once

#include <iostream>
#include "Lista.h"
#include "VerticeGrafo.h"

template <typename T>
class Grafo {
private:
    Lista<VerticeGrafo<T>> vertices;

    // Busca y devuelve el nodo de la lista de vértices que contiene el dato
    // Devuelve nullptr si no existe
    std::shared_ptr<Nodo<VerticeGrafo<T>>> buscarNodoVertice(const T& dato) const {
        std::shared_ptr<Nodo<VerticeGrafo<T>>> actual = vertices.getCabeza();
        while (actual != nullptr) {
            if (actual->getDato().getDato() == dato)
                return actual;
            actual = actual->getSiguiente();
        }
        return nullptr;
    }

public:
    // Constructor
    Grafo() {}

    // ── Vértices ─────────────────────────────────────────────────────────────

    // Añade un vértice al grafo (si no existe ya)
    bool agregarVertice(const T& dato) {
        if (buscarNodoVertice(dato) != nullptr)
            return false; // ya existe
        vertices.insertarAlFinal(VerticeGrafo<T>(dato));
        return true;
    }

    // Elimina un vértice y todas las aristas que apuntan a él
    bool eliminarVertice(const T& dato) {
        // Primero eliminamos el dato de todas las listas de adyacencia
        std::shared_ptr<Nodo<VerticeGrafo<T>>> actual = vertices.getCabeza();
        while (actual != nullptr) {
            actual->getDato().eliminarAdyacente(dato);
            actual = actual->getSiguiente();
        }
        // Luego eliminamos el vértice de la lista principal
        return vertices.eliminar(VerticeGrafo<T>(dato));
    }

    // ── Aristas ──────────────────────────────────────────────────────────────

    // Añade una arista dirigida: origen → destino
    bool agregarArista(const T& origen, const T& destino) {
        std::shared_ptr<Nodo<VerticeGrafo<T>>> nodoOrigen = buscarNodoVertice(origen);
        if (nodoOrigen == nullptr)
            return false; // el vértice origen no existe
        if (buscarNodoVertice(destino) == nullptr)
            return false; // el vértice destino no existe
        nodoOrigen->getDato().agregarAdyacente(destino);
        return true;
    }

    // Elimina una arista dirigida: origen → destino
    bool eliminarArista(const T& origen, const T& destino) {
        std::shared_ptr<Nodo<VerticeGrafo<T>>> nodoOrigen = buscarNodoVertice(origen);
        if (nodoOrigen == nullptr)
            return false;
        return nodoOrigen->getDato().eliminarAdyacente(destino);
    }

    // ── Operaciones del enunciado ─────────────────────────────────────────────

    // 1. Muestra cada aeropuerto y su lista de adyacentes
    void mostrarRutas() const {
        std::shared_ptr<Nodo<VerticeGrafo<T>>> actual = vertices.getCabeza();
        while (actual != nullptr) {
            const VerticeGrafo<T>& vertice = actual->getDato();
            const T& dato = vertice.getDato();
            const Lista<T>& adyacentes = vertice.getAdyacentes();

            std::cout << dato << "\n";
            std::cout << "  Vuelos directos a:\n";

            std::shared_ptr<Nodo<T>> adyacente = adyacentes.getCabeza();
            if (adyacente == nullptr) {
                std::cout << "  (sin conexiones)\n";
            } else {
                while (adyacente != nullptr) {
                    std::cout << "    -> " << adyacente->getDato() << "\n";
                    adyacente = adyacente->getSiguiente();
                }
            }
            std::cout << "\n";
            actual = actual->getSiguiente();
        }
    }

    // 2. Devuelve el grado de salida de un vértice (número de vuelos directos)
    int contarDestinosDesde(const T& origen) const {
        std::shared_ptr<Nodo<VerticeGrafo<T>>> nodo = buscarNodoVertice(origen);
        if (nodo == nullptr)
            return -1; // vértice no encontrado
        const VerticeGrafo<T>& vertice = nodo->getDato();
        const Lista<T>& adyacentes = vertice.getAdyacentes();
        return adyacentes.getTamanio();
    }

    // Getter de la lista de vértices (necesario para mostrarEstadisticasAeropuertos)
    const Lista<VerticeGrafo<T>>& getVertices() const {
        return vertices;
    }
};
