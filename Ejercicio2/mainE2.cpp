#include <iostream>
#include "Aeropuerto.h"
#include "Grafo.h"

// ── Función externa: Reporte General de Conectividad (apartado 3) ─────────────
void mostrarEstadisticasAeropuertos(const Grafo<Aeropuerto>& grafo) {
    std::cout << "====== REPORTE GENERAL DE CONECTIVIDAD ======\n";
    std::shared_ptr<Nodo<VerticeGrafo<Aeropuerto>>> actual = grafo.getVertices().getCabeza();
    while (actual != nullptr) {
        const Aeropuerto& aeropuerto = actual->getDato().getDato();
        int destinos = grafo.contarDestinosDesde(aeropuerto);
        std::cout << "[" << aeropuerto.getCodigo() << "] "
                  << aeropuerto.getNombre()
                  << " -> " << destinos << " destino(s)\n";
        actual = actual->getSiguiente();
    }
    std::cout << "=============================================\n\n";
}

// ── Inicialización de la red aérea ───────────────────────────────────────────
void inicializarRedAerea(Grafo<Aeropuerto>& grafo) {
    // Vértices: aeropuertos
    Aeropuerto mad("MAD", "Adolfo Suárez Madrid-Barajas",  "Madrid",    "España");
    Aeropuerto bcn("BCN", "Josep Tarradellas Barcelona-El Prat", "Barcelona", "España");
    Aeropuerto lhr("LHR", "Heathrow",                      "Londres",   "Reino Unido");
    Aeropuerto cdg("CDG", "Charles de Gaulle",             "París",     "Francia");
    Aeropuerto jfk("JFK", "John F. Kennedy",               "Nueva York","Estados Unidos");
    Aeropuerto gru("GRU", "Guarulhos",                     "São Paulo", "Brasil");
    Aeropuerto nrt("NRT", "Narita",                        "Tokio",     "Japón");

    grafo.agregarVertice(mad);
    grafo.agregarVertice(bcn);
    grafo.agregarVertice(lhr);
    grafo.agregarVertice(cdg);
    grafo.agregarVertice(jfk);
    grafo.agregarVertice(gru);
    grafo.agregarVertice(nrt);

    // Aristas: vuelos directos (grafo dirigido)
    grafo.agregarArista(mad, bcn);
    grafo.agregarArista(mad, lhr);
    grafo.agregarArista(mad, cdg);
    grafo.agregarArista(mad, jfk);
    grafo.agregarArista(mad, gru);

    grafo.agregarArista(bcn, mad);
    grafo.agregarArista(bcn, lhr);
    grafo.agregarArista(bcn, cdg);

    grafo.agregarArista(lhr, jfk);
    grafo.agregarArista(lhr, cdg);
    grafo.agregarArista(lhr, nrt);

    grafo.agregarArista(cdg, lhr);
    grafo.agregarArista(cdg, jfk);
    grafo.agregarArista(cdg, nrt);

    grafo.agregarArista(jfk, lhr);
    grafo.agregarArista(jfk, gru);
    grafo.agregarArista(jfk, nrt);

    grafo.agregarArista(gru, mad);
    grafo.agregarArista(gru, jfk);

    grafo.agregarArista(nrt, jfk);
    grafo.agregarArista(nrt, lhr);
}

// ── Main ─────────────────────────────────────────────────────────────────────
int main() {
    Grafo<Aeropuerto> redAerea;
    inicializarRedAerea(redAerea);

    // 1. Visualizar la red
    std::cout << "====== RED AÉREA: RUTAS DISPONIBLES ======\n\n";
    redAerea.mostrarRutas();

    // 2. Contar destinos desde un aeropuerto concreto
    Aeropuerto mad("MAD", "", "", "");
    std::cout << "====== DESTINOS DESDE MAD ======\n";
    int destinos = redAerea.contarDestinosDesde(mad);
    std::cout << "Vuelos directos desde MAD: " << destinos << "\n\n";

    // 3. Reporte general de conectividad
    mostrarEstadisticasAeropuertos(redAerea);

    return 0;
}