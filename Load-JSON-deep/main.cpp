#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QString>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString file_path = "/home/eveil/src/dev/qt-json/Load-JSON-deep/test.json";
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

    qDebug() << json_doc;

    if(!json_doc.isObject()){
        qDebug() << "json doc is not object.";
        exit(3);
    }

    QJsonObject root_obj=json_doc.object();

    QVariantMap root_map=root_obj.toVariantMap();

    QVariantMap stats=root_map["stats"].toMap();
    QVariantList inv=root_map["inventory"].toList();


    if(stats.isEmpty()){
        qDebug() << "The stats object is empty.";
        exit(4);
    }
    if(inv.isEmpty()){
        qDebug() << "The inventory array is empty";
    }

    // iterate a json object's members:
    QStringList key_list = stats.keys();
    for(int i=0; i < key_list.count(); ++i){
        QString key=key_list.at(i);
        int stat_val = stats[key.toLocal8Bit()].toInt();
        qDebug() << key << ": " << stat_val;
    }

    qDebug() << "Inventory:";

    for(int i=0; i < inv.count(); ++i){
        qDebug() << inv.at(i).toString();
    }




    return a.exec();
}
