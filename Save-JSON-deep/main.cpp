#include <QCoreApplication>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QJsonObject stats_obj;
    stats_obj["name"]="Thor";
    stats_obj["str"]=34;
    stats_obj["enemy"]="Loki";

    // using QList stream initialization
    QJsonArray inventory_list;
    inventory_list << "sword" << "shield" << "armor";

    // using insert method
    QJsonObject root_obj;
    root_obj.insert("stats",stats_obj);
    root_obj.insert("inventory",inventory_list);

    QJsonDocument json_doc(root_obj);
    QString json_string = json_doc.toJson();

    QString file_path = "/home/eveil/test_deep.json";
    QFile save_file(file_path);
    if(!save_file.open(QIODevice::WriteOnly)){
        qDebug() << "Faild to open save file";
    }

    save_file.write(json_string.toLocal8Bit());
    save_file.close();


    return a.exec();
}
