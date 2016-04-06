#include <QCoreApplication>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QJsonArray json_list;
    json_list.append("Thor");
    json_list.append("Odin");
    json_list.append("Freya");

    QJsonDocument json_doc(json_list);
    QString json_string = json_doc.toJson();

    QString file_path = "/home/eveil/test_list.json";
    QFile save_file(file_path);
    if(!save_file.open(QIODevice::WriteOnly)){
        qDebug()<<"Failed to open save file.";
        exit(1);
    }
    save_file.write(json_string.toLocal8Bit());
    save_file.close();

    return a.exec();
}
