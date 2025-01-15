#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent, Ville* ville)
    : QDialog(parent), ui(new Ui::Dialog), ville(ville)
{
    ui->setupUi(this);
}

Dialog::~Dialog() {
    delete ui;
}

void Dialog::on_pushButton_clicked() {
    // Get data from input fields
    int id = ui->Id_batiment->text().toInt();
    QString nom = ui->nom_batiment->text();
    QString type = ui->type_batiment->text();
    double consommationEau = ui->conso_eau->text().toDouble();
    double consommationElectricite = ui->conso_elec->text().toDouble();
    double effetSatisfaction = ui->eff_sat->text().toDouble();

    // Create a new Batiment and add it to Ville
    if (ville) {
        Batiment newBatiment(id, nom.toStdString(), type.toStdString(), consommationEau, consommationElectricite, effetSatisfaction);
        ville->ajouterBatiment(newBatiment); // Pass the object directly
    }

    // Close the dialog
    accept();

    // Debug output
    qDebug() << "ID:" << id
             << "Nom:" << nom
             << "Type:" << type
             << "Consommation Eau:" << consommationEau
             << "Consommation Electricite:" << consommationElectricite
             << "Effet Satisfaction:" << effetSatisfaction;
}

