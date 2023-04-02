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
    y = 0.0;
};
Punto2D::Punto2D(double x, double y){
    //aca como recibimos parámetros, tenemos que usar el puntero this
    this->x = x; //el "x" de esta estructura" será igual a la "x" del argumento
    this->y = y;
};
Punto2D::Punto2D(const Punto2D &otro){
    //acá tenemos un constructor que recibe otro punto
    x = otro.x;
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

    Punto2D *punto = new Punto2D;

    delete punto;

    return a.exec();
}
