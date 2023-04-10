#include <QCoreApplication>
#include <QDebug>
#include <stack>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::stack<int> pila;
    pila.push(1);
    pila.push(2);
    pila.push(5);
    pila.push(10);
    return a.exec();
}
