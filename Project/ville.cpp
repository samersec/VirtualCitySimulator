#include "Ville.h"
#include <iostream>

Ville::Ville(std::string nom, float budget, int population, float satisfaction, float eau, float electricite)
    : nom(nom), budget(budget), population(population), satisfaction(satisfaction), eau(eau), electricite(electricite) { }

void Ville::ajouterBatiment(const Batiment& b) {
    batiments.push_back(b);  // Add Batiment by value
}

void Ville::supprimerBatiment(int id) {
    for (auto it = batiments.begin(); it != batiments.end(); ++it) {
        if (it->getId() == id) {
            batiments.erase(it);  // Erase by iterator
            break;
        }
    }
}

float Ville::calculerConsommationTotale() const {
    float total = 0;
    for (const auto& batiment : batiments) {  // Access Batiment by const reference
        total += batiment.calculerImpactRessources();  // No error
    }
    return total;
}


float Ville::calculerSatisfaction() const {
    return satisfaction;
}

void Ville::afficherDetails() const {
    std::cout << "Ville: " << nom << ", Budget: " << budget << ", Population: " << population
              << ", Satisfaction: " << satisfaction << std::endl;
    std::cout << "Ressources: Eau = " << eau << ", Electricité = " << electricite << std::endl;
    std::cout << "Nombre de bâtiments: " << batiments.size() << std::endl;
    for (const auto& batiment : batiments) {  // Access Batiment by const reference
        batiment.afficherDetails();  // No error
    }
}

std::vector<Batiment> Ville::getBatiments() const {
    return batiments;  // Return by value
}
