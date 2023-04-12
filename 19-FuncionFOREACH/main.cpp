#include <QCoreApplication>
#include <QDebug>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <algorithm>

void imprime1(int n){
    qDebug() << n;
};

void imprime2(float n){
    qDebug() << n;
};

void imprime3(const std::pair<int, int> &par){
    qDebug() << par.first << "," << par.second;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::vector<int> vector {1, 2, 3, 4, 5};
    std::list<int> lista {3, 3, 3, 3, 3};
    std::set<float> conjunto {1.2f, 3.3f, 5.6f};
    std::map<int, int> diccionario;

    diccionario[0] = 10;
    diccionario[1] = 20;
    diccionario[2] = 30;
    diccionario[3] = 40;

    std::for_each(vector.begin(), vector.end(), imprime1); qDebug() << "\n";
    std::for_each(lista.begin(), lista.end(), imprime1);  qDebug() << "\n";
    std::for_each(conjunto.begin(), conjunto.end(), imprime2);  qDebug() << "\n";
    std::for_each(diccionario.begin(), diccionario.end(), imprime3);  qDebug() << "\n";

    return a.exec();
}
