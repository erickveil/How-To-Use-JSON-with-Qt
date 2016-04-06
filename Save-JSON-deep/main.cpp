#include <QCoreApplication>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // using object initializer list
    QJsonObject stats_obj {
        {"name","Thor"},
        {"str",34},
        {"enemy","Loki"}
    };

    // using QList stream initialization
    QJsonArray inventory_list;
    inventory_list << "sword" << "shield" << "armor";

    // using insert method
    QJsonObject root_obj;
    root_obj.insert(stats_obj);
    root_obj.insert(inventory_list);

    QJsonDocument json_doc(root_obj);
    QString json_string = json_doc.toJson();

    QString file_path = "/home/eveil/test_deep.json";





    return a.exec();
}
