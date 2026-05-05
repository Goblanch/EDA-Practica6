#pragma once
#include "Lista.h"

template <typename T>
class VerticeGrafo {
private:
    T dato;
    Lista<T> adyacentes;

public:
    explicit VerticeGrafo(const T& dato) : dato(dato) {}

    T& getDato() {return dato;}
    const T& getDato() const {return dato;}
    Lista<T>& getAdyacentes() {return adyacentes;}
    const Lista<T>& getAdyacentes() const {return adyacentes;}

    void agregarAdyacente(const T& destino) {
        adyacentes.insertarAlFinal(destino);
    }

    bool eliminarAdyacente(const T& destino) {
        return adyacentes.eliminar(destino);
    }

    // Sobrecarga de ==, dato debe sobrecargar == también
    bool operator==(const VerticeGrafo<T>& otro) const {
        return dato == otro.dato;
    }
};