#include <iostream>
#include <fstream>
#include <string>

//clasa pentru reprezentarea unei persoane
class Persoana {
private:
    std::string nume;
    int varsta;

public:
    Persoana(const std::string& nume, int varsta) : nume(nume), varsta(varsta) {}

    void afiseazaDetalii() const {
        std::cout << "Nume: " << nume << ", Varsta: " << varsta << " ani\n";
    }
};

//clasa pentru reprezentarea unui vehicul
class Vehicul {
private:
    std::string marca;
    std::string model;

public:
    Vehicul(const std::string& marca, const std::string& model) : marca(marca), model(model) {}

    void afiseazaDetalii() const {
        std::cout << "Marca: " << marca << ", Model: " << model << "\n";
    }
};

// Clasa pentru reprezentarea unei firme de mașini
class FirmaMasini {
private:
    Persoana proprietar;
    Vehicul vehicul;

public:
    FirmaMasini(const std::string& numeProprietar, int varstaProprietar, const std::string& marcaVehicul, const std::string& modelVehicul)
            : proprietar(numeProprietar, varstaProprietar), vehicul(marcaVehicul, modelVehicul) {}

    void afiseazaInformatiiFirma() const {
        std::cout << "Informatii firma:\n";
        proprietar.afiseazaDetalii();
        vehicul.afiseazaDetalii();
    }

    void efectueazaVanzare() {
        std::cout << "Vanzare realizata.\n";
    }
};

int main() {
    // citire din fisierul tastatura.txt
    std::ifstream inputFile("tastatura.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Eroare la deschiderea fisierului tastatura.txt\n";
        return 1;
    }

    std::string numeProprietar, marcaVehicul, modelVehicul;
    int varstaProprietar;

    inputFile >> numeProprietar >> varstaProprietar >> marcaVehicul >> modelVehicul;
    inputFile.close();

    FirmaMasini firma(numeProprietar, varstaProprietar, marcaVehicul, modelVehicul);

    firma.afiseazaInformatiiFirma();

    firma.efectueazaVanzare();

    return 0;
}
