#include <QCoreApplication>
#include <QDebug>
#include <vector>
#include <algorithm>
//los vectores son como los arrays.

void imprime(const std::vector<int> &vector){
    for(int i = 0; i < vector.size(); i++){
        qDebug() << vector[i];
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //array normal
    int A[] = {1, 5, 10, 15, 20};
    int tam = sizeof(A)/sizeof(int);
    for(int i = 0; i < tam; i++){
        qDebug() << A[i];
    }

    qDebug() << "\n";

    //con vector
    //a los vectores se le pueden agregar o quitar elementos.
    //en cambio con los arreglos suelen ser de un tamaño
    std::vector<int> B = {2, 10, 20, 30, 40};
    int tam2 = B.size(); //método size de la clase vector
    for(int i = 0; i < tam2; i++){
        qDebug() << B[i];
    }
    qDebug() << "\n\n";
    B.push_back(100);
    B.push_back(200);
    B.push_back(300);
    B.push_back(400);
    B.push_back(500);

    imprime(B);

    //acá para eliminar el 300, hacemos uso de la librería algorithm para usar el método find y buscar ese dato, y de esta manera, poder hacer
    //uso del método erase de la librería vector.
    B.erase(std::find(B.begin(), B.end(), 300));
    qDebug() << "\n\n";
    imprime(B);

    return a.exec();
}
