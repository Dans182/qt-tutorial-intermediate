#include <QCoreApplication>
#include <QDebug>
#include <algorithm>
#include <vector>

//Pairs son plantillas de dos tipos de datos

void imprime(const std::pair<int, QString> &parameter){
    qDebug() << parameter.first << parameter.second;
}

void imprime2(const std::pair<QString, QString> &parameter){
    qDebug() << parameter.first << parameter.second;
}

//creo la funcion que recibe un vector, de pares, de dos valores QString, llamado english Spanish
void agregaPalabra(std::vector<std::pair<QString, QString>> &diccionario, const QString &english, const QString &spanish){

    std::pair<QString, QString> traduccion;
    traduccion.first = english;
    traduccion.second = spanish;
    diccionario.push_back(traduccion);
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::pair<int, QString> significado1;
    std::pair<int, QString> significado2;

    significado1.first = 1;
    significado1.second = "One";
    significado2.first = 2;
    significado2.second = "Two";

    imprime(significado1);
    imprime(significado2);

    //creo el vector, de pares, de dos valores QString, llamado english Spanish
    //crearemos un vector de pair, un diccionario English-Spanish
    std::vector<std::pair<QString, QString>> diccionarioEnglishSpanish;

    agregaPalabra(diccionarioEnglishSpanish, "car", "carro");
    agregaPalabra(diccionarioEnglishSpanish, "dog", "perro");
    agregaPalabra(diccionarioEnglishSpanish, "cat", "gato");

    std::vector<std::pair<QString, QString>>::const_iterator i = diccionarioEnglishSpanish.cbegin();
    const std::vector<std::pair<QString, QString>>::const_iterator end = diccionarioEnglishSpanish.cend();
    for (; i != end; ++i)
    {
        imprime2(*i);
    }

    return a.exec();
}
