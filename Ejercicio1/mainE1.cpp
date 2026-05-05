#include <iostream>
#include <vector>
#include "Arbol.h"
#include "Producto.h"

int main()
{
    std::vector<Producto> productos = {
        {"50"}, {"60"}, {"70"}, {"51"}, {"52"}, {"53"}
    };

    Arbol<Producto> arbol1;

    arbol1.crearInventarioABB(productos);

    Producto existente{"50"};
    Producto hoja{"53"};
    Producto noExiste{"999"};

    std::cout << "\nNivel de 50: "<< arbol1.calcularProfundidad(existente) << std::endl;
    std::cout << "Nivel de 53: "<< arbol1.calcularProfundidad(hoja) << std::endl;
    std::cout << "Nivel de 999: "<< arbol1.calcularProfundidad(noExiste) << std::endl;

    Arbol<Producto> arbolEspejo = arbol1.espejo();

    std::cout << "\nÁrbol espejo (InOrden inverso):" << std::endl;
    arbolEspejo.inOrder(arbolEspejo.getRaiz());

    return 0;
}