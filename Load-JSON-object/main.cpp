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
    //qDebug()<<"File contents:"<<endl<<file_text.readAll()<<endl;


    // stream to string
    QString json_string;
    json_string=file_text.readAll();
    int stream_size=json_string.size();
    qDebug()<<"json string: "<<endl<<json_string<<endl;

    // string to byte array
    QByteArray json_byte=json_string.toLocal8Bit();

    // convert string to json object
    auto json_doc =
            QJsonDocument::fromJson(json_byte);
    qDebug() << "Json Doc: " << json_doc.rawData(&stream_size);


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

    // print the vlaues


    file_obj.close();

    return a.exec();
}
