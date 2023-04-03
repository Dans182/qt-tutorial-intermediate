#include <QCoreApplication>
#include <QDebug>

struct Persona{
    QString nombre;
    int edad;
    double salario;

    Persona(); //constructor que no recibe parametros
    Persona(const QString &nombre, int edad, double salario); //constructor que si recibe parámetros
    Persona(const Persona &otra); //constructor de copia. Que recibe por parámetro otra Persona/estructura
    ~Persona(); //destructor
    void imprime() const; //método imprime
};

//acá ponemos todo el cuerpo de los métodos.

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
        qDebug() << "memoria destruido";
};
void Persona::imprime() const{
    qDebug() << nombre << edad << salario;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Persona *juan = new Persona; //uso del constructor por defecto, sin parámetros
    juan->nombre = "Juan";
    juan->edad = 22;
    juan ->salario = 21000.00;
    juan->imprime();
    delete juan; //en estas líneas estamos haciendo uso del constructor que no recibe parametros de línea 10.

    Persona *ana = new Persona("Ana", 18, 9000.00); //acá recibe los valores por parámetros en el constructor
    ana->imprime();
    delete ana;

    Persona *luis = new Persona(Persona("Luis", 30, 30000.00));
    luis->imprime();
    delete luis;


    //Ahora cambiamos la palabra Struct por la palabra clase.
    //al indicar "CLASE" automáticamente todo el contenido interno de la clase se vuelve privado
    //al ser privado, no tenemos permiso para usarlo fuera de la clase
    //para tener acceso, tenemos que hacerlo "publico". Palabra public
//todo lo que esté despues de los dos puntos será público, y tendremos permiso para utilizarlo

    return a.exec();
}
