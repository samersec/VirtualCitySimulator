#include "Batiment.h"
#include <iostream>
#include <QJsonObject>

// Default constructor
Batiment::Batiment()
    : id(0), nom(""), type(""), consommationEau(0.0), consommationElectricite(0.0), effetSatisfaction(0.0) {}

// Parameterized constructor
Batiment::Batiment(int id, const std::string& nom, const std::string& type,
                   double consommationEau, double consommationElectricite, double effetSatisfaction)
    : id(id),
    nom(nom),
    type(type),
    consommationEau(consommationEau),
    consommationElectricite(consommationElectricite),
    effetSatisfaction(effetSatisfaction) {    qDebug() << "Batiment Created: ID:" << id
             << "Nom:" << QString::fromStdString(nom)
             << "Type:" << QString::fromStdString(type)
             << "Consommation Eau:" << consommationEau
             << "Consommation Electricite:" << consommationElectricite
             << "Effet Satisfaction:" << effetSatisfaction;
 }

// Display building details
void Batiment::afficherDetails() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Nom: " << nom << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Consommation d'eau: " << consommationEau << std::endl;
    std::cout << "Consommation d'électricité: " << consommationElectricite << std::endl;
    std::cout << "Effet sur la satisfaction: " << effetSatisfaction << std::endl;
}

// Calculate resource impact
double Batiment::calculerImpactRessources() const {
    return consommationEau + consommationElectricite;
}
QJsonObject Batiment::toJson() const {
    qDebug() << "Debugging Batiment::toJson:";
    qDebug() << "ID:" << id;
    qDebug() << "Nom:" << QString::fromStdString(nom);
    qDebug() << "Type:" << QString::fromStdString(type);
    qDebug() << "Consommation Eau:" << consommationEau;
    qDebug() << "Consommation Electricite:" << consommationElectricite;
    qDebug() << "Effet Satisfaction:" << effetSatisfaction;

    QJsonObject jsonObject;
    jsonObject["id"] = id;
    jsonObject["nom"] = QString::fromStdString(nom);
    jsonObject["type"] = QString::fromStdString(type);
    jsonObject["consommationEau"] = consommationEau;
    jsonObject["consommationElectricite"] = consommationElectricite;
    jsonObject["effetSatisfaction"] = effetSatisfaction;
    return jsonObject;
}

