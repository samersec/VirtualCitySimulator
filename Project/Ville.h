#ifndef VILLE_H
#define VILLE_H

#include <iostream>
#include <vector>
#include "Batiment.h"

class Ville {
private:
    std::string nom;
    float budget;
    int population;
    float satisfaction;
    std::vector<Batiment> batiments;  // Store Batiment objects directly
    float eau;
    float electricite;

public:
    // Constructor
    Ville(std::string nom, float budget, int population, float satisfaction, float eau, float electricite);

    // Add a building to the city
    void ajouterBatiment(const Batiment& b);  // Take by value

    // Remove a building from the city by its ID
    void supprimerBatiment(int id);

    // Calculate the total resource consumption (water + electricity)
    float calculerConsommationTotale() const;

    // Calculate the city's overall satisfaction
    float calculerSatisfaction() const;

    // Display the details of the city
    void afficherDetails() const;

    // Getter for the list of buildings
    std::vector<Batiment> getBatiments() const;  // Return by value (not pointer)
};

#endif // VILLE_H
