#include <QCoreApplication>
#include <QDebug>
#include <map>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::map<QString, QString> diccionario;
    diccionario["apple"] = "manzana";
    diccionario["orange"] = "naranja";
    diccionario["water"] = "agua";
    diccionario["key"] = "clave";
    diccionario["earth"] = "tierra";

    std::map<QString, QString>::iterator i = diccionario.begin();
    const std::map<QString, QString>::const_iterator end = diccionario.end();

    for(; i != end; i++){
        qDebug() << i->first << "," << i->second;
    }

    //nos los ordena en forma alfabética

    return a.exec();
}
