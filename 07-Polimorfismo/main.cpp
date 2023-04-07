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

    virtual ~Persona(){

    };

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

    //como el metodo imprime es igual a 0, debo definirlo yo en cada clase derivada.
    void imprime() const override{ //el prototipo al ser const y ser void, debo respetar eso e indicarlo. Si es igual a 0 y es virtual
        //debo indicar "override" para indicar que hago una sobrecarga de un método que viene de una clase base
        qDebug() << "Hola soy" << m_nombre << "y soy un empleado";
    }
    virtual ~Empleado(){
        qDebug() << "Memoria liberada para empleado";
    };
private:
};


class Jefe : public Persona
{
public:
    Jefe(const QString &nombre) : Persona(nombre){ //la clase Persona asigna el nombre por nosotros
        //aquí no se pone nada
    };

    void imprime() const override
    {
        qDebug() << "Hola soy" << m_nombre << "y soy un jefe";
    };
    virtual ~Jefe(){
        qDebug() << "Memoria liberada para jefe";
    };
private:
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Persona *personas[4];
    personas[0] = new Jefe("Juan");
    personas[1] = new Empleado("Luis");
    personas[2] = new Jefe("Pedro");
    personas[3] = new Empleado("Ana");

    //imprimir/mostrar todas las personas del arreglo
    //llamamos a cada persona y llamamos su imprime
    for(int i = 0; i < 4; i++){
        personas[i]->imprime();
    }

    //Ahora hay que borrar toda la memoría dinámica de cada elemento del arreglo.
    //Se recomienda tener destructores viruales.
    for(int i = 0; i < 4; i++){
        delete personas[i];
    }


    //los destructores siempre se recomiendan que sean "virtuales".
    return a.exec();
}
