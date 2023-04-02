#include <QCoreApplication>
#include <QDebug>

struct Persona{
    QString nombre;
    int edad;
    double salario;

    Persona(); //constructor que no recibe parametros
    Persona(const QString &nombre, int edad, double salario); //constructor que si recibe parámetros
    Persona(const Persona &otra); //constructor de copia
    ~Persona(); //destructor
    void imprime() const; //método imprime
};

//acá ponemos todo el cuerpo de los métodos.

Persona::Persona(){

};
Persona::Persona(const QString &nombre, int edad, double salario){};
Persona::Persona(const Persona &otra){};
Persona::~Persona(){};
void Persona::imprime() const{};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Persona *juan = new Persona;
    juan->nombre = "Juan";
    juan->edad = 22;
    juan ->salario = 21000.00;
    juan->imprime();
    delete juan; //en estas líneas estamos haciendo uso del constructor que no recibe parametros de línea 10.

    Persona *ana = new Persona("Ana", 18, 9000.00);
    ana->imprime();
    delete ana;

    Persona *luis = new Persona(Persona("Luis", 30, 30000.00));
    luis->imprime();
    delete luis;

    return a.exec();
}
