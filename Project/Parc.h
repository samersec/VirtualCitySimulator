#ifndef PARC_H
#define PARC_H
#include "Batiment.h"
class Parc : public Batiment{

    double surface ;
    double effetBienEtre;
public:
    Parc(int,string,string,double,double,double,double,double);
    void ameliorerBienEtre();
    void Parc::afficherDetails() override {

};
Parc::Parc(int id,string nom,string type,double consommationEau,double consommationElectricite,double effetSatisfaction,double surface,double effetBienEtre):Batiment(id, nom, type, consommationEau, consommationElectricite, effetSatisfaction){
    this->surface=surface;
    this->effetBienEtre=effetBienEtre;
}


void Parc:: ameliorerBienEtre() {
    cout << "Effet bien-être amélioré de: " << effetBienEtre << endl;
}

void Parc::afficherDetails() {
    Batiment::afficherDetails();
    cout << "Surface: " << surface << ", Effet Bien-être: " << effetBienEtre << endl;
}



#endif // PARC_H
