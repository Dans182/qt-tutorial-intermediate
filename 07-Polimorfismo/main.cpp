#include <QCoreApplication>
#include <QDebug>

//Polimorfismo quiere decir varias formas
//queda muy claro cuando tenemos herencias

class Persona
{
public:
    Persona(const QString &nombre){
        m_nombre = nombre;
    };
    virtual void imprime() const = 0; //tipo virtual: significa que hay posibilidad de hacer polimorfismo
    //al ser igual a 0, significa que nos obliga a definir el método en las clases derivadas

protected: //se pone protected, ya que al ser clase "padre o base" para que las clases que heredan tengan acceso a las variables
    QString m_nombre;
};

class Empleado : public Persona
{
public:
    Empleado(const QString &nombre) : Persona(nombre)
    {
        //aquí no se pone nada
    }
    //constructor empleado, recibe como parámetros el nombre y le pasaremos a la clase base Persona el nombre
private:
};

class Jefe : public Persona
{
public:
    Jefe(const QString &nombre) : Persona(nombre){
        //aquí no se pone nada
    };
private:
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
