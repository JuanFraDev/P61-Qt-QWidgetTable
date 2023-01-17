#include "personadialog.h"
#include "ui_personadialog.h"

PersonaDialog::PersonaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonaDialog)
{
    ui->setupUi(this);
}

PersonaDialog::~PersonaDialog()
{
    delete ui;
}

void PersonaDialog::on_buttonBox_accepted()
{
    bool valid = false, validNom = true, validApe = true;
    QString nombre = ui->inNombre->text();
    QString apellido = ui->inApellido->text();
    QString telefono = ui->inTelefono->text();
    QString email = ui->inEmail->text();
    if(nombre.length() == 0 || apellido.length() == 0 || telefono.length() == 0 || email.length() == 0){
        QMessageBox::warning(this, "Advertencia", "Es necesario completar todos los campos para guardar..!");
        return;
    }
    for(int i = 0; i < nombre.length(); i++){
        if(nombre[i].isDigit()){
            validNom = false;
        }
    }
    if(validNom == false){
        QMessageBox::warning(this, "Advertencia", "El campo de nombre, solo admite letras");
        return;
    }
    for(int i = 0; i < apellido.length(); i++){
        if(apellido[i].isDigit()){
            validApe = false;
        }
    }
    if(validApe == false){
        QMessageBox::warning(this, "Advertencia", "El campo de apellido, solo admite letras");
        return;
    }

    for(int i = 0; i < email.length(); i++){
        if(email[i] == '@'){
            for(int j = i; j < email.length(); j++){
                if(email[j] == '.'){
                    valid = true;
                }
            }
        }
    }
    if(valid == false){
        QMessageBox::warning(this, "Advertencia", "Ingrese un formato de correo valido..!");
        return;
    }
    this->m_persona = new Persona(nombre, apellido, telefono, email);
    accept();
}

void PersonaDialog::on_inNombre_editingFinished()
{
    QString nombre = ui->inNombre->text();
    bool validNom = true;
    if(nombre.length() == 0){
        QMessageBox::warning(this, "Advertencia", "Es necesario completar todos los campos para guardar..!");
        return;
    }
    for(int i = 0; i < nombre.length(); i++){
        if(nombre[i].isDigit()){
            validNom = false;
        }
    }
    if(!validNom){
        ui->inNombre->setStyleSheet("background-color: rgb(255, 105, 180)");
    }
    else{
        ui->inNombre->setStyleSheet("background-color: rgb(153, 193, 241)");
    }
}

void PersonaDialog::on_inApellido_editingFinished()
{
    QString apellido = ui->inApellido->text();
    bool validApe = true;
    if(apellido.length() == 0){
        QMessageBox::warning(this, "Advertencia", "Es necesario completar todos los campos para guardar..!");
        return;
    }
    for(int i = 0; i < apellido.length(); i++){
        if(apellido[i].isDigit()){
            validApe = false;
        }
    }
    if(!validApe){
        ui->inApellido->setStyleSheet("background-color: rgb(255, 105, 180)");
    }
    else{
        ui->inApellido->setStyleSheet("background-color: rgb(153, 193, 241)");
    }
}

void PersonaDialog::on_inTelefono_editingFinished()
{
    QString telefono = ui->inTelefono->text();
    if(telefono.length() == 0){
        QMessageBox::warning(this, "Advertencia", "Es necesario completar todos los campos para guardar..!");
        return;
    }
}

void PersonaDialog::on_inEmail_editingFinished()
{
    QString email = ui->inEmail->text();
    bool valid = false;
    if(email.length() == 0){
        QMessageBox::warning(this, "Advertencia", "Es necesario completar todos los campos para guardar..!");
        return;
    }

    for(int i = 0; i < email.length(); i++){
        if(email[i] == '@'){
            for(int j = i; j < email.length(); j++){
                if(email[j] == '.'){
                    valid = true;
                }
            }
        }
    }
    if(valid == false){
        QMessageBox::warning(this, "Advertencia", "Ingrese un formato de correo valido..!");
        return;
    }
}

void PersonaDialog::set_datos(QString nom, QString ape, QString tel, QString email)
{
    ui->inNombre->setText(nom);
    ui->inApellido->setText(ape);
    ui->inTelefono->setValue(tel.toInt());
    ui->inEmail->setText(email);
}

void PersonaDialog::on_buttonBox_rejected()
{
    reject();
}

Persona *PersonaDialog::persona() const
{
    return m_persona;
}

