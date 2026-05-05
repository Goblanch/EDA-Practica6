#pragma once
#include <memory>

template <typename T>
class Nodo
{
private:
    T dato;
    std::shared_ptr<Nodo<T>> izquierda;
    std::shared_ptr<Nodo<T>> derecha;
public:
    Nodo(T dat): dato(dat), izquierda(nullptr), derecha(nullptr) {}
    std::shared_ptr<Nodo<T>> getIzquierda() { return izquierda; }
    std::shared_ptr<Nodo<T>> getDerecha() { return derecha; }
    T getDato() { return dato; }
    void setIzquierda(std::shared_ptr<Nodo<T>> n) { izquierda = n; }
    void setDerecha(std::shared_ptr<Nodo<T>> n) { derecha = n; }
};