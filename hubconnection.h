#ifndef HUBCONNECTION_H
#define HUBCONNECTION_H

#include <QTcpSocket>
#include <QUdpSocket>
#include <QMutex>
#include <QList>
#include "tablemodel.h"
#include "searchitem.h"
#include "fileinfo.h"
#include "hubtcpsocket.h"
#include "hubudpsocket.h"
#include "clientconnection.h"
#include "nicklistthreadcontrol.h"

class HubNickList;
class TableModel;
struct UdpDatagram;

class HubConnection: public QObject
{
    Q_OBJECT
public:
    HubConnection(QString, quint16);
    ~HubConnection();

    bool init();
    void connectToHub();

    QString userName;
    QString password;
    QString Host;
    QString localHost;

    quint16 Port;
    quint16 slotsNumber;
    QString email;
    QString encoding;
    QString hubTopic;
    QString hubName;
    bool isConnected();
    QByteArray changeKeysStC(QByteArray);
    QByteArray changeKeysCtS(QByteArray);
    QString decode(QByteArray);
    QByteArray encode(QString);
    bool isExtended();
    void SendSearch(QString);
    quint64 sharesize;
public slots:
    void slot_search_result(FileInfo, SearchItem);
    void slot_command_received(QByteArray);
    void slot_set_sharesize(quint64);
    void slot_send_message(QString);
private:
    HubTcpSocket* hubtcpsocket;
    HubUdpSocket* hubudpsocket;
    QList<ClientConnection*> client_list;

    QByteArray buffer;

    bool isListParsing;
    bool isSending;
    bool isSendingUdp;

    bool isHello;

    QByteArray generateKey(const QByteArray&);
    bool m_isExtended;
    void searchMessage(QString);
    void newClient(QString, QString, bool);
private slots:
    void slot_client_destroyed(QObject*);
signals:
    void signal_tcp_write(QByteArray);
    void signal_udp_write(QByteArray, QString, quint16);

    void signalConnected();
    void signalDisconnected();
    void signalRedirect(QString strHost, quint16 nPort);
    void signal_hub_message(QString);

    // Сигналы для списка пользователей
    void signalNickList(QByteArray);
    void signalHello(QByteArray);
    void signalQuit(QString);
    void signalMyINFO(QString data);

    void signal_search_request(SearchItem);
};
struct UdpDatagram
{
    QByteArray data;
    QString host;
    int port;
};
#endif // HUBCONNECTION_H
