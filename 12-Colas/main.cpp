#include <QCoreApplication>
#include <QDebug>
#include <queue>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::queue<int> cola;
    cola.push(1);
    cola.push(2);
    cola.push(5);
    cola.push(10);


    while (!cola.empty()){ //si la cola NO está vacía
        qDebug() << cola.front();//utilizamos el elemento que está posicionado arriba
        cola.pop(); //aca eliminamos ese elemento que está posicionado de primero
        //en las colas cuando usamos pop, se va quitando el de arriba, osea, el primero que se puso, el mas antiguo (el 1 en este caso)
        //y el segundo ahora es el primero, etc, etc, etc
    }

    return a.exec();
}

//las colas o queue es a la inversa que las pilas o stack. Aca el primer elemento agregado, mantiene su primer posición. "Orden de llegada"
//1, 2, 5, 10
