#ifndef BATIMENT_H
#define BATIMENT_H
#include <QJsonObject>

#include <string>
#include <iostream>

class Batiment {
protected:
    int id;
    std::string nom;
    std::string type;
    double consommationEau;
    double consommationElectricite;
    double effetSatisfaction;

public:
    // Constructors
    Batiment();
    Batiment(int id, const std::string& nom, const std::string& type,
             double consommationEau, double consommationElectricite, double effetSatisfaction);

    // Virtual functions
    virtual void afficherDetails() const;  // Mark as const
    virtual double calculerImpactRessources() const;  // Mark as const
    QJsonObject toJson() const;

    // Getter methods
    int getId() const { return id; }
    std::string getNom() const { return nom; }
    std::string getType() const { return type; }
    double getConsommationEau() const { return consommationEau; }
    double getConsommationElectricite() const { return consommationElectricite; }
    double getEffetSatisfaction() const { return effetSatisfaction; }

};

#endif // BATIMENT_H
