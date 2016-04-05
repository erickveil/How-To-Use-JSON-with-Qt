#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // load document from file to string
    QString file_path="/home/eveil/src/dev/qt-json/Load-JSON-object/test.json";
    QFile file_obj(file_path);
    if(!file_obj.open(QIODevice::ReadOnly)){
        qDebug()<<"Cannot open file: "<< file_path;
        exit(1);
    }
    QTextStream file_text(&file_obj);

    // stream to string
    QString json_string;
    json_string=file_text.readAll();

    file_obj.close();

    qDebug()<<"json string: "<<endl<<json_string<<endl;

    // string to byte array
    QByteArray json_byte=json_string.toLocal8Bit();


    // convert string to json object
    auto json_doc =
            QJsonDocument::fromJson(json_byte);


    if(json_doc.isNull()){
        qDebug()<<"Failed to convert to json doc";
        exit(2);
    }

    if(!json_doc.isObject()){
        qDebug()<<"JSON is not an object.";
        exit(3);
    }

    QJsonObject json_obj=json_doc.object();

    if(json_obj.isEmpty()){
        qDebug()<<"JSON object is empty.";
        exit(4);
    }

    qDebug()<<"JSON object: "<<endl<<json_obj;



    // get expected members of the object
    QVariantMap json_map = json_obj.toVariantMap();

    // print the vlaues

    qDebug()<<json_map["name"].toString();
    qDebug()<<json_map["str"].toInt();
    qDebug()<<json_map["enemy"].toString();



    return a.exec();
}
