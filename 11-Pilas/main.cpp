#include <QCoreApplication>
#include <QDebug>
#include <stack>
#include <algorithm>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //acá estamos agregando elementos, uno por delante del anterior.
    std::stack<int> pila;
    pila.push(1);
    pila.push(2);
    pila.push(5);
    pila.push(10);

    //quedando asi: 10, 5, 2 y 1.

    //Si ahora queremos ir eliminando uno detrás del otro, hacemos así

    while (!pila.empty()){ //si la pila NO está vacía
        qDebug() << pila.top(); //utilizamos el elemento que está posicionado hasta arriba
        pila.pop(); //aca eliminamos ese elemento que está posicionado en el top
    }
    return a.exec();
}

//las pilas o stack son para ir guardando valores o aquellos que pongamos en plantilla.
