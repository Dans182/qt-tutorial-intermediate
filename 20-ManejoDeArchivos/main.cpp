#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream> //para guardar archivos de texto

void escribeArchivo(const QString &nombreDelArchivo, const QString &contenido){
    //para escribir el archivo

    QFile A(nombreDelArchivo);    //para escribir el archivo. Archivo A, pasamos por constructor el nombredelarchivo
    if (A.open(QIODevice::Text | QIODevice::WriteOnly)) //abrimos el archivo. Es de tipo texto. y que solo permite escritura.
    {
        QTextStream stream(&A); //recibe el archivo por constructor
        stream << contenido;
        A.flush();
        A.close();
        qDebug() << "Archivo grabado correctamente";
    }
    else {
        qDebug() << A.errorString();
    };

};

void leerArchivo(const QString &nombreDelArchivo){
    QFile A(nombreDelArchivo);
    if(A.open(QIODevice::Text | QIODevice::ReadOnly))
    {
        QTextStream stream(&A);
        QString contenido = stream.readAll();
        A.close();
        qDebug() << contenido;
    }
    else{
        qDebug() << A.errorString();
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString nombreArchivo = "miTexto.txt";
    QString contenido = "Hola Mundo!!!!!!!";

    escribeArchivo(nombreArchivo, contenido);
    leerArchivo(nombreArchivo);


    return a.exec();
}
