#include <QCoreApplication>
#include <QDebug>

//la sobrecarga de funciones consiste en dos funciones que se llaman igual (pero parámetros distintos)

int suma(int a, int b){
    return a + b;
};

double suma(double a, double b){
    return a + b;
};

float suma(float a, float b){
    return a + b;
};

QString suma(const QString &a, const QString &b){
    return a + b;
};

struct Punto2D{
    double x;
    double y;

    //haremos sobrecarga de funciones, en este caso de métodos. (porque está dentro de una estructura)
    //sobrecarga de métodos
    Punto2D suma(const Punto2D &p)const;//esta suma un punto
    Punto2D suma(double numero)const;//esta sumara un número
    void imprime() const;
};

Punto2D Punto2D::suma(const Punto2D &p)const{
    Punto2D r;//creamos la estructura llamada resultado
    r.x = this->x + p.x;//la x de la estructura resultado, será igual a su x + la x que viene en parámetro
    r.y = this->y + p.y;//la y de la estructura resultado, será igual a su y + la y que viene en parámetro
    return r;
};

Punto2D Punto2D::suma(double numero)const{
    Punto2D r;
    r.x = this->x + numero;
    r.y = this->y + numero;
    return r;
};

void Punto2D::imprime() const{
    qDebug() << x << y;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << suma(2, 2);
    qDebug() << suma(2.1, 2.1);
    qDebug() << suma(3.2f, 3.2f);
    qDebug() << suma("Hola", " Mundo");
    qDebug() << "\n";

    Punto2D p;
    p.x = 1.0;
    p.y = 3.0;

    Punto2D q;
    q.x = 2.0;
    q.y = 4.0;

    Punto2D r1 = p.suma(q);
    Punto2D r2 = p.suma(10.2);

    r1.imprime();
    r2.imprime();

    return a.exec();
}
