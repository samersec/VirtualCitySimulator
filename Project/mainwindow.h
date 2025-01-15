#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QMainWindow>
#include "Ville.h" // Include Ville class
#include "Batiment.h" // Include Batiment class
#include "Dialog.h" // Include Dialog class

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void updateTable(); // Add this to update the table
    void on_pushButton_clicked(); // Slot for the button click event
    void saveDataToFile();
    void     loadDataFromFile();


private:
    Ui::MainWindow *ui;
    Ville ville; // Declare ville as a member of MainWindow
    std::vector<Batiment*> batiments; // Store Batiment objects in vector
};

#endif // MAINWINDOW_H
