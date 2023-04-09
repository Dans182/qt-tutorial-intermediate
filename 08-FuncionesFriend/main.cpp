#include <QCoreApplication>
#include <QDebug>

//el modificador de acceso friend sirve para tener acceso libre a todos los atributos de una clase desde una función externa

class Persona
{
public:
    Persona(const QString &nombre, int edad){
        m_nombre = nombre;
        m_edad = edad;
    };

private:
    QString m_nombre;
    int m_edad;

    friend void imprimePersona(const Persona &p); //declaro acá la función y la declaro friend, para que pueda tener acceso a los datos private.
};

void imprimePersona(const Persona &p) //función externa
{ //función imprime persona, que recibe una persona cualquiera y la imprime.
    qDebug() << p.m_nombre << p.m_edad;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Persona ana("Ana", 25);
    Persona juan("Juan", 30);
    imprimePersona(ana);
    imprimePersona(juan);

    return a.exec();
}
