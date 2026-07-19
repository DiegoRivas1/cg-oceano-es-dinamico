#pragma once

class Ola {
public:
    Ola(float amplitud, float direccionRad, float frecuencia, float fase);

    // Altura de esta ola sola, en el punto (x,z) en el instante t.
    float altura(float x, float z, float tiempo) const;

    void gradiente(float x, float z, float tiempo, float& dHdx, float& dHdz) const;

    float amplitud() const   { return amplitud_; }
    float direccion() const  { return direccion_; }
    float frecuencia() const { return frecuencia_; }
    float fase() const       { return fase_; }
    float numeroOnda() const { return numeroOnda_; }

private:
    float amplitud_;
    float direccion_;  
    float frecuencia_;
    float fase_;
    float numeroOnda_;  

    static constexpr float GRAVEDAD = 9.81f;
    static float calcularNumeroOnda(float frecuencia);
};
