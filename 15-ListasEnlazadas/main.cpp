#include <QCoreApplication>
#include <QDebug>
#include <list>
#include <algorithm>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::list<int> L = {1, 2, 3, 4, 5};
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    L.push_front(-10);
    L.push_front(-20);
    L.push_front(-30);

    //me va a borrar los valores que están desde el 2 hasta el 5 inclusive
    L.erase(std::find(L.begin(), L.end(),2),
            ++std::find(L.begin(), L.end(),5));

    std::list<int>::iterator i = L.begin();
    std::list<int>::iterator end = L.end();

    for(; i != end; i++){
        qDebug() << *i;
    }

    return a.exec();
}
