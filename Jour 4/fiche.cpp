#include <iostream>
#include <string>

int main() {
    std::string nom;
    std::string prenom;
    std::string ville;
    int age;
    double moyenne;

    std::cout << "Nom : ";
    std::cin >> nom;

    std::cout << "Prenom : ";
    std::cin >> prenom;

    std::cout << "Age : ";
    std::cin >> age;

    std::cout << "Ville : ";
    std::cin >> ville;

    std::cout << "Moyenne : ";
    std::cin >> moyenne;

    std::cout << "\n--- Fiche interactive ---" << std::endl;
    std::cout << "Nom : " << nom << std::endl;
    std::cout << "Prenom : " << prenom << std::endl;
    std::cout << "Age : " << age << " ans" << std::endl;
    std::cout << "Ville : " << ville << std::endl;
    std::cout << "Moyenne : " << moyenne << "/20" << std::endl;

    return 0;
}
