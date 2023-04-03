#include <QCoreApplication>
#include <QDebug>

class Punto2D{
public:
    Punto2D(); //constructor sin parámetros
    Punto2D(double x, double y); //constructor con parámetros
    Punto2D(const Punto2D &otro); //constructor que recibe otro punto, el constructor de copia
    ~Punto2D();//destructor
    void setX(double x);//método set que recibe la x y la modifica
    void setY(double y);//método set que recibe la y y la modifica
    double x() const;//método x que devuelve valor de la x
    double y() const;//método y que devuelve valor de la y
    void imprime() const;
private:
    double m_x; //uso la "m" primero para indicar que es una variable miembro = variable privada
    double m_y;
};

//aca creamos el contenido de los métodos
Punto2D::Punto2D(){ //tenemos que poner el nombre de la clase a cada método para poder hacer la resolución de ámbito
    m_x = 0.0;
    m_y = 0.0;
};
Punto2D::Punto2D(double x, double y){
    this->m_x = x;
    this->m_y = y;
    // m_x = x;
    // m_y = y;
};
Punto2D::Punto2D(const Punto2D &otro){
    m_x = otro.m_x;
    m_y = otro.m_y;
};
Punto2D::~Punto2D(){
    qDebug() << "memoria liberada"; //aca no es necesario poner algo. Suele ir vacio
};
void Punto2D::setX(double x){
    this->m_x = x;
    //m_x = x;
};
void Punto2D::setY(double y){
    this->m_y = y;
    m_y = y;
};
double Punto2D::x() const{
    return m_x;
};
double Punto2D::y() const{
    return m_y;
};
void Punto2D::imprime() const{
    qDebug() << m_x << "," << m_y;
};
//cuando no existen operadores aritméticos para la clase que trabajamos, tenemos que definir eso nosotros
//creo un método
Punto2D operator+(const Punto2D &p, Punto2D &q){
    Punto2D resultadoDeLaSuma;
    resultadoDeLaSuma.setX(p.x() + q.x());
    resultadoDeLaSuma.setY(p.y() + q.y());
    return resultadoDeLaSuma;
};

Punto2D operator-(const Punto2D &p, Punto2D &q){ //devuelvo un punto como resultado, el operador es el de resta y recibo por parámetros 2 puntos (p y q)
    Punto2D resultadoDeLaResta;//declaramos un punto de resultado
    resultadoDeLaResta.setX(p.x() - q.x());//le ponemos de x, la x de p menos la x de q
    resultadoDeLaResta.setY(p.y() - q.y());//le ponemos de y, la y de p menos la y de q
    return resultadoDeLaResta; //devolvemos el resultado
};

Punto2D operator*(const Punto2D &p, Punto2D &q){
    Punto2D resultadoDeLaMultiplicacion;
    resultadoDeLaMultiplicacion.setX(p.x() * q.x());
    resultadoDeLaMultiplicacion.setY(p.y() * q.y());
    return resultadoDeLaMultiplicacion;
};

Punto2D operator/(const Punto2D &p, Punto2D &q){
    Punto2D resultadoDeLaDivision;
    resultadoDeLaDivision.setX(p.x() / q.x());
    resultadoDeLaDivision.setY(p.y() / q.y());
    return resultadoDeLaDivision;
}

bool operator==(const Punto2D &p, Punto2D &q){
    if(p.x() == q.x() && p.y() == q.y()){
        return true;
    }
    else{
        return false;
    }
}

bool operator!=(const Punto2D &p, Punto2D &q){
    return !(p==q);
}

//bool operator!=(const Punto2D &p, Punto2D &q){
//    if(p.x() != q.x() || p.y() != q.y()){
//        return true;
//    }
//    else{
//        return false;
//    }
//}

class Persona{
public:
    Persona(const QString &nombre, int edad);
    int edad() const;
    QString nombre() const;
private:
    QString m_nombre;
    int m_edad;
};

Persona::Persona(const QString &nombre, int edad){
    m_nombre = nombre;
    m_edad = edad;
};

int Persona::edad() const{
    return m_edad;
};

QString Persona::nombre() const{
    return m_nombre;
};

bool operator<(const Persona &A, const Persona &B){
    return A.edad() < B.edad();
};

bool operator>(const Persona &A, const Persona &B){
    return A.edad() > B.edad();
};

bool operator>=(const Persona &A, const Persona &B){
    return A.edad() >= B.edad();
};

bool operator<=(const Persona &A, const Persona &B){
    return A.edad() <= B.edad();
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Punto2D p(1.0, 3.0);
    Punto2D q(2.0, 5.0);

    Punto2D sumapq = p + q;
    Punto2D restapq = p - q;
    Punto2D multiplicacionpq = p * q;
    Punto2D divisionpq = p / q;

    sumapq.imprime();
    restapq.imprime();
    multiplicacionpq.imprime();
    divisionpq.imprime();

    Punto2D A(1.0, 1.0);
    Punto2D B(1.0, 4.0);
    if(A == B){
        qDebug() << "A == B";
    }
    else{
        qDebug() << "A != B";
    };

    Persona C("Carlos", 25);
    Persona D("Pedro", 25);

    if(C <= D){
    qDebug() << C.nombre() << "es menor o tiene igual edad que" << D.nombre();
    }

    //de toda la manera antes expuesta, es como se sobrecargan los operadores.

    return a.exec();
}
