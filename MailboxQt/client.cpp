#include "client.h"

#include "ei_connect.h"

#include <QDebug>

namespace Mailbox {

short creation = 0;

Client::Client(QObject *parent) : QObject(parent)
{
    m_ec = new ei_cnode();
    Q_ASSERT(m_ec != nullptr);
}

Client::~Client()
{
    delete m_ec;
}

void Client::sendAtom(QByteArray procName, QByteArray atom)
{

}

bool Client::connect(QByteArray name, QByteArray otherNode, QByteArray cookie)
{

    if (name == otherNode)
    {
        qWarning() << "Node and otherNode names are the same";
        return false;
    }

    if(ei_connect_init(m_ec, name.data(), cookie.data(), creation++) < 0)
    {
        qWarning() << "Error initialising Erlang CNode";
        return false;
    }

    QByteArray fullName = otherNode + "@localHost";

    int fd = ei_connect(m_ec, fullName.data());
    if (fd < 0)
    {
        qWarning() << "Error connecting to Erlang Node";
        switch (erl_errno) {
        case EHOSTUNREACH:
            qWarning() << "Host is unreachable";
            break;
        case ENOMEM:
            qWarning() << "Out of Memory";
            break;
        case EIO:
            qWarning() << "IO Error";
            break;
        default:
            qWarning() << "erl_errno code" << fd;
            break;
        }
        return false;
    }

    m_fd = fd;
    return true;
}

}