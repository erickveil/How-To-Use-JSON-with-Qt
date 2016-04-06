#include <QCoreApplication>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString character_name="Thor";
    int strength_stat=35;
    QString enemy_name="Loki";

    QJsonObject json_obj;

    json_obj["name"]=character_name;
    json_obj["str"]=strength_stat;
    json_obj["enemy"]=enemy_name;

    qDebug() << json_obj;

    QString file_path = "/home/eveil/test_obj.json";
    QFile save_file(file_path);
    if(!save_file.open(QIODevice::WriteOnly)){
        qDebug() << "Failed to open save file";
        exit(1);
    }

    QJsonDocument json_doc(json_obj);

    qDebug() << json_doc;

    QString json_string = json_doc.toJson();

    qDebug() << json_string;

    save_file.write(json_string.toLocal8Bit());
    //save_file.write("Goodbye world");
    save_file.close();

    return a.exec();
}
