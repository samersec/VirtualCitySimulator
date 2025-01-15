#ifndef USINE_H
#define USINE_H
#include <iostream>
#include "Batiment.h"
class Usine : public Batiment{
    double productionRessources;
    double pollution;
public:
    Usine(int,string,string,double,double,double,double,double);
    void produireRessources();
    double calculerPollution();
    void afficherDetails() override{

};
Usine::Usine(int id,string nom,string type,double consommationEau,double consommationElectricite,double effetSatisfaction,double productionRessources,double pollution):Batiment(id, nom, type, consommationEau, consommationElectricite, effetSatisfaction){
    this->productionRessources=productionRessources;
    this->pollution=pollution;
}

void Usine::produireRessources(){
    cout << "Production de ressources: " << productionRessources << endl;
}
double Usine::calculerPollution(){

    return pollution;
}
void Usine::afficherDetails(){
    cout << "Production Ressources: " << productionRessources << ", Pollution: " << pollution << endl;
}


#endif // USINE_H
