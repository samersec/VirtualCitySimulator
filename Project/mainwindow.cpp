#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), ville("MyCity", 100000, 1000, 0.9, 5000, 10000)
{
    ui->setupUi(this);

    // Load data from file when the app starts

    // Initialize table
    updateTable();
    loadDataFromFile();
    saveDataToFile();
}
MainWindow::~MainWindow() {
    delete ui;  // Clean up the UI components
}


void MainWindow::on_pushButton_clicked() {
    // Open dialog and pass Ville object
    Dialog dialog(this, &ville);
    if (dialog.exec() == QDialog::Accepted) {
        updateTable(); // Refresh table after adding a new Batiment

        // Save data to file after adding
        saveDataToFile();
    }
}



void MainWindow::updateTable() {
    const auto& buildings = ville.getBatiments();
    ui->tableWidget_Item_Data->setRowCount(buildings.size());
    ui->tableWidget_Item_Data->setColumnCount(6);
    ui->tableWidget_Item_Data->setHorizontalHeaderLabels(QStringList() << "ID" << "Nom" << "Type" << "Conso Eau" << "Conso Electricité" << "Effet Satisfaction");

    for (size_t i = 0; i < buildings.size(); ++i) {
        ui->tableWidget_Item_Data->setItem(i, 0, new QTableWidgetItem(QString::number(buildings[i].getId())));  // Use dot operator
        ui->tableWidget_Item_Data->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(buildings[i].getNom())));  // Use dot operator
        ui->tableWidget_Item_Data->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(buildings[i].getType())));  // Use dot operator
        ui->tableWidget_Item_Data->setItem(i, 3, new QTableWidgetItem(QString::number(buildings[i].getConsommationEau(), 'f', 2)));  // Use dot operator
        ui->tableWidget_Item_Data->setItem(i, 4, new QTableWidgetItem(QString::number(buildings[i].getConsommationElectricite(), 'f', 2)));  // Use dot operator
        ui->tableWidget_Item_Data->setItem(i, 5, new QTableWidgetItem(QString::number(buildings[i].getEffetSatisfaction(), 'f', 2)));  // Use dot operator
    }

    ui->tableWidget_Item_Data->resizeColumnsToContents();
}


void MainWindow::saveDataToFile() {
    QFile file("C:/Users/User/Documents/VirtualCitySimulator/Project/ville_data/batiments.json");
    if (file.open(QIODevice::WriteOnly)) {
        QJsonArray jsonArray;
        for (const auto& building : ville.getBatiments()) {
            jsonArray.append(building.toJson()); // Use the dot operator for non-pointer objects
        }

        QJsonDocument doc(jsonArray); // Create a JSON document from the array
        file.write(doc.toJson()); // Write the JSON data to the file
        file.close(); // Ensure the file is closed after writing
    } else {
        qDebug() << "Failed to open file for writing.";
    }

}


void MainWindow::loadDataFromFile() {
    QFile file("C:/Users/User/Documents/VirtualCitySimulator/Project/ville_data/batiments.json");
    if (file.exists() && file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);

        if (doc.isArray()) {
            QJsonArray jsonArray = doc.array();
            for (const QJsonValue& value : jsonArray) {
                if (value.isObject()) {
                    QJsonObject obj = value.toObject();

                    // Debug output to confirm the data is read correctly
                    qDebug() << "Loading Batiment from JSON:";
                    qDebug() << "ID:" << obj["id"].toInt();
                    qDebug() << "Nom:" << obj["nom"].toString();
                    qDebug() << "Type:" << obj["type"].toString();
                    qDebug() << "Consommation Eau:" << obj["consommationEau"].toDouble();
                    qDebug() << "Consommation Electricite:" << obj["consommationElectricite"].toDouble();
                    qDebug() << "Effet Satisfaction:" << obj["effetSatisfaction"].toDouble();

                    // Create Batiment object with these values
                    Batiment* building = new Batiment(
                        obj["id"].toInt(),
                        obj["nom"].toString().toStdString(),
                        obj["type"].toString().toStdString(),
                        obj["consommationEau"].toDouble(),
                        obj["consommationElectricite"].toDouble(),
                        obj["effetSatisfaction"].toDouble()
                        );

                    // Add Batiment to Ville
                    ville.ajouterBatiment(*building);
                }
            }
            updateTable(); // Update the UI after loading
        }
    } else {
        qDebug() << "Failed to open or locate the file.";
    }
}


