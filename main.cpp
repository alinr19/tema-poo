#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

/// definim o clasa pentru masinile care sunt la vanzare
class Masina
{
private:
    std::string nume;
    std::string marca;
    int an;
public:
    Masina(const std::string& nume, const std::string& marca, int an)
        : nume(nume), marca(marca), an(an) {}
    const std::string& GetNume() const { return nume; }
    const std::string& GetMarca() const { return marca; }
    int GetAn() const { return an; }
};

/// definim clasa pentru viitori cumparatori
class Client {
private:
    std::string nume;
    std::string prenume;
public:
    Client(const std::string& nume, const std::string& prenume)
        : nume(nume), prenume(prenume) {}
    const std::string& GetNume() const { return nume; }
    const std::string& GetPrenume() const { return prenume; }
};

/// definim clasa pentru vanzari, care va avea o compunere intre masina si cllient
class Vanzare {
private:
    Masina masina;
    Client client;
    double pret;
public:
    Vanzare(const Masina& masina, const Client& client, double pret)
        : masina(masina), client(client), pret(pret) {}
    const Masina& GetMasina() const { return masina; }
    const Client& GetClient() const { return client; }
    double GetPret() const { return pret; }
};

void CitesteDateDinFisier(std::vector<Masina>& masini, std::vector<Client>& clienti, std::vector<Vanzare>& vanzari) {
    std::ifstream fisier("tastatura.txt");

    if (!fisier.is_open()) {
        std::cerr << "Nu am putut deschide fisierul " << std::endl;
        return;
    }

    std::string linie;
    while (std::getline(fisier, linie)) {
        std::string tip, val1, val2, val3;
        std::istringstream linieStream(linie);
        std::getline(linieStream, tip, ':');
        std::getline(linieStream, val1, ':');
        std::getline(linieStream, val2, ':');
        std::getline(linieStream, val3, ':');

        if (tip == "Masina") {
            masini.push_back(Masina(val1, val2, std::stoi(val3)));
        } else if (tip == "Client") {
            clienti.push_back(Client(val1, val2));
        } else if (tip == "Vanzare") {
            Masina masina;
            Client client;
            double pret;
            for (const Masina& m : masini) {
                if (m.GetNume() == val2) {
                    masina = m;
                    break;
                }
            }
            for (const Client& c : clienti) {
                if (c.GetNume() == val3) {
                    client = c;
                    break;
                }
            }
            pret = std::stod(val1);
            vanzari.push_back(Vanzare(masina, client, pret));
        }
    }

    fisier.close();
}

int main() {
    std::vector<Masina> masini;
    std::vector<Client> clienti;
    std::vector<Vanzare> vanzari;

    CitesteDateDinFisier("tastatura.txt", masini, clienti, vanzari);

    // Exemplu de utilizare
    for (const Vanzare& vanzare : vanzari) {
        std::cout << "Detalii vanzare:" << std::endl;
        std::cout << "Masina: " << vanzare.GetMasina().GetMarca() << " " << vanzare.GetMasina().GetNume() << " " << vanzare.GetMasina().GetAn() << std::endl;
        std::cout << "Client: " << vanzare.GetClient().GetNume() << " " << vanzare.GetClient().GetPrenume() << std::endl;
        std::cout << "Pret: " << vanzare.GetPret() << " RON" << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
