#ifndef MSGLISTENER_H
#define MSGLISTENER_H

#include <QObject>
#include <QThread>
#include <QVariant>

namespace MailSlot {

class MsgListener : public QThread
{
    Q_OBJECT
    void run() Q_DECL_OVERRIDE;

public:
    explicit MsgListener(int fd, QObject *parent = 0);

signals:
    void messageRecieved(QVariant to, QVariant value);

public slots:

private:
    int m_fd;
};

} // namespace MailSlot

#endif // MSGLISTENER_H
