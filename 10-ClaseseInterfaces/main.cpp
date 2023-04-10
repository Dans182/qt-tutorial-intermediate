#include <QCoreApplication>
#include <QDebug>
#include <QDate>

//una clase que sea interfaz, solamente tiene métodos que no tienen ninguna implementacion y que son virtuales.
//Lo ideal es que esten protegidos y sean virtuales sin implementacion alguna.
//si a la interfaz le agregas metodos que si están implementados o tienen implementaciones, ya no es una interfaz pura
//o si los valores dejan de ser 0.

class IPersona {
public:
    virtual ~IPersona(){
        qDebug() << "persona liberada";
    }
protected:
    virtual void imprime() const = 0;
    virtual int edad(int fechaNacimiento) const = 0;
    virtual double peso() const = 0;
    virtual QString nombre() const = 0;
};

class Juan : public IPersona{
public:
    Juan(){
        m_nombre = "Juan";
        m_peso = 70;
    };
    virtual ~Juan(){

    };
    void imprime() const override{
        qDebug() << m_nombre << m_peso << edad(1990);
    };
    int edad(int fechaNacimiento) const override{
        return QDate::currentDate().year() - fechaNacimiento;
    };
    double peso() const override{
        return m_peso;
    };
    QString nombre() const override{
        return m_nombre;
    };
private:
    QString m_nombre;
    double m_peso;
};

class Ana : public IPersona{
public:
    Ana(){

    };
    virtual ~Ana(){

    };
    void imprime() const override{
        qDebug() << nombre() << peso() << edad(1998);
    };
    int edad(int fechaNacimiento) const override{
        return QDate::currentDate().year() - fechaNacimiento;
    };
    double peso() const override{
        return 90;
    };
    QString nombre() const override{
        return "Ana";
    };
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Juan J;
    Ana A;
    J.imprime();
    A.imprime();

    return a.exec();
}
