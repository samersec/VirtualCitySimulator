#ifndef MAISON_H
#define MAISON_H
#include "Batiment.h"
class Maison : public Batiment{
    int capaciteHabitants;
    int habitantsActuels;
public:
    Maison(int,string,string,double,double,double,int,int);
    void ajouterHabitants(int);
    void retirerHabitants(int);
    void afficherDetails() override;
};

Maison::Maison(int id,string nom,string type,double consommationEau,double consommationElectricite,double effetSatisfaction,int capaciteHabitants,int habitantsActuels):Batiment(id, nom, type, consommationEau, consommationElectricite, effetSatisfaction){
    this->capaciteHabitants=capaciteHabitants;
    this->habitantsActuels=habitantsActuels;
}

void Maison:: ajouterHabitants(int nb) {
    if (habitantsActuels + nb <= capaciteHabitants) {
        habitantsActuels += nb;
    } else {
        cout << "Capacité maximale atteinte !" << endl;
    }
}

void Maison::retirerHabitants(int nb) {
    if (habitantsActuels - nb >= 0) {
        habitantsActuels -= nb;
    } else {
        cout << "Impossible de retirer plus d'habitants que présents !" << endl;
    }
}
    void Maison::afficherDetails(){
        cout << "Capacité: " << capaciteHabitants << ", Habitants Actuels: " << habitantsActuels << endl;
    }




#endif // MAISON_H
