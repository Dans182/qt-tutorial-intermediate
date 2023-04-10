#include <QCoreApplication>
#include <QDebug>
#include <set>
#include <vector>

//set es conjunto
//la caracteristica del conjunto es que no se pueden repetir valores
//lo util de los conjuntos es que se pueden utilizar para eliminar elementos repetidos

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::set<int> conjunto;

    conjunto.insert(1);
    conjunto.insert(2);
    conjunto.insert(3);
    conjunto.insert(4);
    conjunto.insert(1); //este simplemente no lo agregará

    std::set<int>::iterator i = conjunto.begin();
    std::set<int>::iterator end = conjunto.end();
    for(; i != end; i++){
        qDebug() << *i;
    }

    qDebug() << "\n";

    //en este creo un vector, con datos repetidos y hago un loop para pasarlo de vector a conjunto
    //y despues otro loop para que me muestre todos los valores internos de ese conjunto2.
    std::vector<int> vector = {1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 2};
    std::set<int> conjunto2;

    for(unsigned j = 0; j < vector.size(); j++){
        conjunto2.insert(vector[j]);
    }

    std::set<int>::iterator k = conjunto2.begin();
    std::set<int>::iterator end2 = conjunto2.end();
    for(; k != end2; k++){
        qDebug() << *k;
    }
    return a.exec();
}
