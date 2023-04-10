#include <QCoreApplication>
#include <vector>
#include <algorithm>
#include <QDebug>

//los iteradores son para tener acceso a los elementos de una coleccion
//por ejemplo, de un vector

void imprime(const std::vector<float> &vector){
    for(unsigned i = 0; i < vector.size(); i++){
        qDebug() << vector[i];
    }
};

//ahora haremos uso de los iteradores para imprimir el contenido del vector
void imprime2(std::vector<float> &vector2){
    for(std::vector<float>::iterator j = vector2.begin(); j != vector2.end(); j++){
        qDebug() << *j;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    //creacion de mi vector original
    std::vector<float> vector = {5.33f, 6.45f, 7.8f, 9.9f, 102.45f};
    imprime(vector);

    //acá mi iterador apunta al primer valor del vector. 5.33f
    std::vector<float>::iterator a = vector.begin();
    *a = 0.0f;

    //acá mi iterador apunta especificamente al 7.8f
    std::vector<float>::iterator b = std::find(vector.begin(), vector.end(), 7.8f);
    *b = 1001.1f;

    qDebug() << "\n";
    imprime(vector);

    qDebug() << "\n";
    imprime2(vector);

    return app.exec();
}
