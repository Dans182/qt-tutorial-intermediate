#include <QCoreApplication>
#include <QDebug>

//Ahora cambiamos la palabra Struct por la palabra clase.
//al indicar "CLASE" automáticamente todo el contenido interno de la clase se vuelve privado
//al ser privado, no tenemos permiso para usarlo fuera de la clase
//para tener acceso, tenemos que hacerlo "publico". Palabra public
//todo lo que esté despues de los dos puntos será público, y tendremos permiso para utilizarlo
//en las clases se recomienda que los metodos sean público en su mayoria y que las variables sean privadas.
//la diferencia a fin de cuentas entre struct y clases, es que las clases indican que es lo privado y que es lo público.

class Persona{
    //implicitamente si te colocan acá las variables, se consideras privadas o se puede indicar la palabra "private"
    QString nombre;
    int edad;
    double salario;
public:
    Persona();
    Persona(const QString &nombre, int edad, double salario);
    Persona(const Persona &otra);
    ~Persona();
    void imprime() const;

    //métodos que nos permite modificar y trabajar con variables privadas
    void setNombre(const QString &nombre);
    void setEdad(const int &edad);
    void setSalario(const double &salario);
//private:
//    QString nombre;
//    int edad;
//    double salario;
};

void Persona::setNombre(const QString &nombre){//indicamos el nombre de la clase como resolución de ámbito
    this->nombre = nombre;
};
void Persona::setEdad(const int &edad){
    this->edad = edad;
};
void Persona::setSalario(const double&salario){
    this->salario = salario;
};

Persona::Persona(){
    nombre = "";
    edad = 0;
    salario = 0;
};
Persona::Persona(const QString &nombre, int edad, double salario){
    this->nombre = nombre;
    this->edad = edad;
    this->salario = salario;
};
Persona::Persona(const Persona &otra){
    nombre = otra.nombre;
    edad = otra.edad;
    salario = otra.salario;
};
Persona::~Persona(){
    qDebug() << "memoria liberada";
};
void Persona::imprime() const{
    qDebug() << nombre << edad << salario;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Persona *juan = new Persona;
    juan->setNombre("Juan"); //al ser variables privadas, acá no tengo permiso para usar las variables directamente, pero si los métodos. Si quiero usar las variables en un lugar donde no tengo permiso, debo hacerlo mediante métodos que nos sirve para modificar los valores privados. Este método es el método setNombre
    juan->setEdad(22);//acá hacemos uso de los métodos creados set, para precisamente modificar las variables, que se encuentran en private.
    juan ->setSalario(21000.00);
    juan->imprime();
    delete juan;

    Persona *ana = new Persona("Ana", 18, 9000.00);
    ana->imprime();
    delete ana;

    Persona *luis = new Persona(Persona("Luis", 30, 30000.00));
    luis->imprime();
    delete luis;

    return a.exec();
}
