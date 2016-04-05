#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QString>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonArray>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString file_path = "/home/eveil/src/dev/qt-json/Load-JSON-array/test.json";
    QFile file_obj(file_path);
    if(!file_obj.open(QIODevice::ReadOnly)){
        qDebug()<< "Failed to open file: " << file_path;
        exit(1);
    }

    QTextStream file_text(&file_obj);
    QString json_string;
    json_string = file_text.readAll();
    file_obj.close();
    QByteArray json_bytes = json_string.toLocal8Bit();

    auto json_doc = QJsonDocument::fromJson(json_bytes);

    if(json_doc.isNull()){
        qDebug()<< "Failed to creat json doc from: "
                <<endl<<json_bytes;
        exit(2);
    }
    if(!json_doc.isArray()){
        qDebug() << "Json Doc is not an array: "
                    <<endl<<json_bytes;
        exit(3);
    }

    QJsonArray json_array = json_doc.array();

    qDebug() << json_array;

    if(json_array.isEmpty()){
        qDebug() << "the array is empty.";
        exit(4);
    }


    for(int i=0; i< json_array.count(); ++i){
        qDebug() << json_array.at(i).toString();
    }





    return a.exec();
}
