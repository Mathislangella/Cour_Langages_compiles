#include <iostream>
#include <string>

class Etudiant {
private:
    std::string nom;
    int age;
    double moyenne;
    int nbNotes;

public:
    Etudiant() : nom(""), age(0), moyenne(0.0), nbNotes(1) {}

    Etudiant(std::string n, int a, double m)
        : nom(n), age(a), moyenne(m), nbNotes(1) {}

    void ajouterNote(double note) {
        moyenne = (moyenne * nbNotes + note) / (nbNotes + 1);
        nbNotes++;
    }

    bool estMajeur() const {
        return age >= 18;
    }

    void afficher() const {
        std::cout << "Nom : " << nom << std::endl;
        std::cout << "Age : " << age << " ans" << std::endl;
        std::cout << "Moyenne : " << moyenne << "/20" << std::endl;
        std::cout << "Statut : " << (estMajeur() ? "majeur" : "mineur") << std::endl;
    }

    std::string getNom() const {
        return nom;
    }

    double getMoyenne() const {
        return moyenne;
    }
};

int main() {
    const int TAILLE = 5;
    Etudiant etudiants[TAILLE];

    for (int i = 0; i < TAILLE; i++) {
        std::string nom;
        int age;
        double moyenne;

        std::cout << "\nEtudiant " << i + 1 << std::endl;
        std::cout << "Nom : ";
        std::cin >> nom;
        std::cout << "Age : ";
        std::cin >> age;
        std::cout << "Moyenne : ";
        std::cin >> moyenne;

        etudiants[i] = Etudiant(nom, age, moyenne);
    }

    std::cout << "\n--- Liste des etudiants ---" << std::endl;
    for (int i = 0; i < TAILLE; i++) {
        std::cout << "\nEtudiant " << i + 1 << " :" << std::endl;
        etudiants[i].afficher();
    }

    double somme = 0.0;
    int indiceMeilleur = 0;
    for (int i = 0; i < TAILLE; i++) {
        somme += etudiants[i].getMoyenne();
        if (etudiants[i].getMoyenne() > etudiants[indiceMeilleur].getMoyenne()) {
            indiceMeilleur = i;
        }
    }

    std::cout << "\nMoyenne de la promotion : " << somme / TAILLE << "/20" << std::endl;
    std::cout << "Meilleur etudiant : " << etudiants[indiceMeilleur].getNom()
              << " avec " << etudiants[indiceMeilleur].getMoyenne() << "/20" << std::endl;

    return 0;
}
