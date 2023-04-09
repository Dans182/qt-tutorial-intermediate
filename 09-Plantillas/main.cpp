#include <QCoreApplication>
#include <QDebug>

//esto es una función plantilla
template<typename Tipo>
Tipo suma(const Tipo &a, const Tipo &b)
{
    return a + b;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int resultadoEntero = suma(1, 3);
    float resultadoFloat = suma(3.5f, 6.4f);
    QString resultadoString = suma(QString("Hola,"), QString("mundo!!"));

    qDebug() << resultadoEntero;
    qDebug() << resultadoFloat;
    qDebug() << resultadoString;

    return a.exec();
}
