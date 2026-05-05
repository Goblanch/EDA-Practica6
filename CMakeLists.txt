cmake_minimum_required(VERSION 3.20)
project(Practica6)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ── Ejercicio 1 ──────────────────────────────────────────────────────────────
add_executable(EDA_P5GA1_E1
        # TODO: añadir aquí los archivos fuente del Ejercicio 1
        # Ejemplo: Ejercicio1/mainE1.cpp
        Ejercicio1/mainE1.cpp
        Ejercicio1/Nodo.h
        Ejercicio1/Producto.h
        Ejercicio1/Arbol.h
)

# ── Ejercicio 2 ──────────────────────────────────────────────────────────────
add_executable(EDA_P5GA1_E2_26
        Ejercicio2/mainE2.cpp
        Ejercicio2/Nodo.h
        Ejercicio2/Lista.h
        Ejercicio2/VerticeGrafo.h
        Ejercicio2/Aeropuerto.h
        Ejercicio2/Grafo.h
)