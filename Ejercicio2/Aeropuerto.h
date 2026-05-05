#pragma once

#include <string>

class Aeropuerto {
private:
    std::string codigo;
    std::string nombre;
    std::string ciudad;
    std::string pais;

public:
    Aeropuerto() : codigo(""), nombre(""), ciudad(""), pais("") {}

    Aeropuerto(const std::string& codigo, const std::string& nombre,
               const std::string& ciudad, const std::string& pais)
        : codigo(codigo), nombre(nombre), ciudad(ciudad), pais(pais) {}

    std::string getCodigo() const {return codigo;}
    std::string getNombre() const {return nombre;}
    std::string getCiudad() const {return ciudad;}
    std::string getPais() const {return pais;}

    void setCodigo(const std::string& c) {codigo = c;}
    void setNombre(const std::string& n) {nombre = n;}
    void setCiudad(const std::string& c) {ciudad = c;}
    void setPais(const std::string& p) {pais = p;}

    bool operator==(const Aeropuerto& otro) const {
        return codigo == otro.codigo;
    }

    friend std::ostream& operator<<(std::ostream& os, const Aeropuerto& a) {
        os << "[" << a.codigo << "] " << a.nombre << " (" << a.ciudad << ", " << a.pais << ")";
        return os;
    }
};