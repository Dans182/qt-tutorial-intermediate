#include <QCoreApplication>
#include <QDebug>

struct Punto2D{
    double x;
    double y;

    //dentro de la estructura creamos tanto el constructor como el destructor.
    //el constructor tiene el mismo nombre de la estructura

    //los 3 abajo indicados, son métodos (funciones) de esta estructura.
    Punto2D(); // constructor = mismo nombre de struct - puede haber muchos constructores. Se recomiendan 3 constructores.
    Punto2D(double x, double y); //sobrecarga de constructor, poniendo otro constructor, que reciba valores, por ejm x y y.
    Punto2D(const Punto2D &otro); //recibe por parámetro otro Punto2D. para hacer uso de el, e inicializar variables internas
    ~Punto2D();//destructor - solo puede haber un destructor.
    void imprime() const; // método imprime para mostrar el contenido del struct Punto2D
};

//ahora defino/instancio los médotos/funciones. Declarados arriba.
Punto2D::Punto2D(){
    x = 0.0; //defino el valor inicial de las variables, antes declaradas.
    y = 0.0; //valor inicial de x y y, de la estructura
};

Punto2D::Punto2D(double x, double y){
    //aca como recibimos parámetros, tenemos que usar el puntero this
    this->x = x; //el "x" de esta estructura" será igual a la "x" del argumento
    this->y = y;
};

Punto2D::Punto2D(const Punto2D &otro){
    //acá tenemos un constructor que recibe otro punto
    x = otro.x; //la x del punto va a ser igual a la x del otro punto
    y = otro.y;
};

Punto2D::~Punto2D(){
    qDebug() << "punto destruido"; // memoria liberada
};

void Punto2D::imprime() const{
    qDebug() << x << ", " << y;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Punto2D *punto = new Punto2D;//Esto hace que se ejecute el primer constructor (el sin parámetros)
    punto->imprime();
    //libera memoria
    delete punto; //el destructor me sirve para liberar la memoria con el operador delete. Porque al hacer uso de new, hay uso de memoria dinámica.

    Punto2D *punto2 = new Punto2D(2.3, 3.6);//Esto hace que se ejecute el segundo constructor
    punto2->imprime();
    delete punto2;

    Punto2D *punto3 = new Punto2D(Punto2D(1.1, 1.5));//constructor que recibe otro punto como parámetro con las siguientes parámetros. Acá es una variable anónima, es un constructor sin nombre.
    punto3->imprime();
    delete punto3;

    return a.exec();
}
