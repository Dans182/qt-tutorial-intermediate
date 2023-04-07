#include <QCoreApplication>
#include <QDebug>

class Persona{
public:
    Persona();
    //metodo inline significa que pones las llaves dentro de la clase. Defines el cuerpo del método dentro de la clase
    //tambien a en un método inline, se le puede poner "inline     Persona(const QString &nombre, int edad){
    //    m_nombre = nombre;
    //    m_edad = edad;
    //};
    //pero no es necesario, porque si está definido dentro de la clase, ya se sabe que es "inline".
    //los métodos inline se recomiendan siempre que NO superen las 3 líneas de código. En caso que supere, se recomienda que dentro
    //de la clase se declare, y fuera de la clase, pero antes del main se defina.

    Persona(const QString &nombre, int edad){
        m_nombre = nombre;
        m_edad = edad;
    };
    void imprime(){
        qDebug () << m_nombre << m_edad;
    }
    void imprime5veces() const;
private:
    QString m_nombre;
    int m_edad;
};

void Persona::imprime5veces() const{
    for(int i = 0; i < 5; i++){
        qDebug() << m_nombre;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Persona juan("Juan", 22);
    juan.imprime();
    juan.imprime5veces();

    return a.exec();
}
