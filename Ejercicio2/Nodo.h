#pragma once
#include <memory>

template <typename T>
class Nodo {
private:
    T dato;
    std::shared_ptr<Nodo<T>> siguiente;

public:
    explicit Nodo(const T& dato) : dato(dato), siguiente(nullptr) {}

    T& getDato() {return dato;}
    const T& getDato() const {return dato;}
    std::shared_ptr<Nodo<T>> getSiguiente() const {return siguiente;}

    void setDato(const T& d) {dato = d;}
    void setSiguiente(const std::shared_ptr<Nodo<T>>& s) {siguiente = s;}
};