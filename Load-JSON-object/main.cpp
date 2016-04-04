#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // load document from file to string
    QString file_path="/home/eveil/src/dev/qt-json/Load-JSON-object/test.json";
    QFile file_obj(file_path);
    if(!file_obj.open(QIODevice::ReadOnly)){
        qDebug()<<"Cannot open file: "<< file_path;
    }
    QTextStream file_text(&file_obj);
    qDebug()<<"File contents:"<<endl<<file_text.readAll()<<endl;

    // convert string to json object

    // get expected members of the object

    // print the vlaues

    return a.exec();
}
