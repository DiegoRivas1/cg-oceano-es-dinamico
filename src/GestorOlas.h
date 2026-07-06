#pragma once


#include <memory>
#include <string>
#include <vector>
#include "Ola.h"

class FuenteOlas {
public:
    virtual ~FuenteOlas() = default;
    virtual std::vector<Ola> obtenerOlas() const = 0;
};

// Olas definidas a mano en codigo.
class OlasManual : public FuenteOlas {
public:
    explicit OlasManual(std::vector<Ola> olas) : olas_(std::move(olas)) {}
    std::vector<Ola> obtenerOlas() const override { return olas_; }

private:
    std::vector<Ola> olas_;
};


class OlasDesdeArchivo : public FuenteOlas {
public:
    explicit OlasDesdeArchivo(std::string rutaArchivo, unsigned semilla = 42u);
    std::vector<Ola> obtenerOlas() const override;

private:
    std::string rutaArchivo_;
    unsigned semilla_;
};
