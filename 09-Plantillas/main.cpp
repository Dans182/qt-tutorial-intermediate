#include <QCoreApplication>
#include <QDebug>

//esto es una plantilla de funcion. En forma de función
template<typename Tipo>
Tipo suma(const Tipo &a, const Tipo &b)
{
    return a + b;
}

template<typename Tipo2>
class Persona
{
public:
    Persona(){
        m_nombre = "";
        m_edad = 0;
        m_salario; //Si pongo la variable sin valor, se puede transformar sin problema en float, double, QString o int.
        //pero si la declaron 0 puede transformarse solo en int, double o float. No aceptaría QString
    };
    ~Persona(){

    };

    void imprime() const
    {
        qDebug() << m_nombre << m_edad << m_salario;
    }

    void setNombre(const QString &nombre){
        m_nombre = nombre;
    }
    void setEdad(int edad){
        m_edad = edad;
    }
    void setSalario(const Tipo2 &salario){
        m_salario = salario;
    }
    QString nombre() const{//getters
        return m_nombre;
    }
    int edad() const{ //getters
        return m_edad;
    }
    Tipo2 salario() const{//getters
        return m_salario;
    }

    //se pueden tambien tener metodos plantilla
    template<typename Tipo3>
    void agregaMasSalario(const Tipo3 &valor)
    {
        m_salario += valor;
    }

private:
    QString m_nombre;
    int m_edad;
    Tipo2 m_salario;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int resultadoEntero = suma<int>(1, 3);
    float resultadoFloat = suma<float>(3.5f, 6.4f);
    QString resultadoString = suma<QString>(QString("Hola,"), QString("mundo!!"));

    qDebug() << resultadoEntero;
    qDebug() << resultadoFloat;
    qDebug() << resultadoString << "\n";

    Persona<int> juan;
    Persona<double> ana;
    Persona<float> luis;
    Persona<QString> pedro;

    juan.setNombre("Juan");
    juan.setEdad(30);
    juan.setSalario(5000);
    juan.imprime();

    ana.setNombre("Ana");
    ana.setEdad(25);
    ana.setSalario(3556.36);
    ana.agregaMasSalario<int>(100);
    ana.agregaMasSalario<float>(10.33f);
    ana.agregaMasSalario<double>(1000.105);
    ana.imprime();

    luis.setNombre("Luis");
    luis.setEdad(40);
    luis.setSalario(1521.88f);
    luis.imprime();

    pedro.setNombre("Pedro");
    pedro.setEdad(35);
    pedro.setSalario("$7586.32");
    pedro.imprime();

    return a.exec();
}
