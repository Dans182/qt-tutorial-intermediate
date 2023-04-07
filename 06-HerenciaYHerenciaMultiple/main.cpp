#include <QCoreApplication>
#include <QDebug>

//aquí no hay herencia
//esto es una clase base o clase padre
class Persona
{
public:
    Persona(){
        m_nombre = ""; //método inline
    };
protected:
    QString m_nombre;
};

//Aquí hay herencia simple
//esto es una clase derivada
class Empleado : public Persona //la clase empleado hereda de persona. Porque un empleado es una persona. Y a su vez, tiene sus variables propias
{
public:
    Empleado(){
        m_identificador = 0;
    };
protected:
    int m_identificador;
};

//aquí no hay herencia
class Privilegio{
public:
    Privilegio(){
        m_cantidadDePrivilegios = 0;
    };
protected:
    int m_cantidadDePrivilegios;
};

class Administrador : public Empleado, public Privilegio //la clase administrador hereda de empleado y privilegio
{
    //un administrador hereda de empleado, porque es empleado y a su vez persona, pero tambien tiene privilegios.
    //en este caso hay "herencias múltiples, porque hereda de empleado y de privilegio.
public:
    Administrador(){
        m_identificador = 1521;
        m_cantidadDePrivilegios = 3;
        m_nombre = "Juan";
    }

    void imprime() const{
        qDebug() << m_identificador << m_cantidadDePrivilegios << m_nombre;
    }
protected:
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Administrador A;
    A.imprime();

    //de buenas a primeras, teniendo las variables como "PRIVATE" me da error, porque son variables privadas que vienen de otras
    // clases y no se pueden acceder. Las clases originales, privatizan su contenido, sin embargo, si las variables en vez de
    //private son PROTECTED, las variables siguen siendo privadas pero tienen permitida su utilización en las clases que hacen
    //herencia.

    return a.exec();
}
