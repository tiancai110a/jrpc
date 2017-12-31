//
// Created by frank on 17-12-29.
//

#ifndef JRPC_CONNECTION_MANAGER_H
#define JRPC_CONNECTION_MANAGER_H

#include <jackson/Value.h>

#include <jrpc/common/RpcError.h>
#include <jrpc/common/util.h>

namespace jrpc
{

class RequestException;

template <typename ProtocolServer>
class ConnectionManager: noncopyable
{
public:
    void setNumThread(size_t n) { server_.setNumThread(n); }

    void start() { server_.start(); }

protected:
    // CRTP pattern base class
    ConnectionManager(EventLoop* loop, const InetAddress& listen);
    // avoid this:
    //  ConnectionManager* cm = &ProtocalServer;
    //  delete cm;
    ~ConnectionManager() = default;

private:
    void onConnection(const TcpConnectionPtr& conn);
    void onMessage(const TcpConnectionPtr& conn, Buffer& buffer);
    void onHighWatermark(const TcpConnectionPtr& conn, size_t mark);
    void onWriteComplete(const TcpConnectionPtr& conn);

    void handleMessage(const TcpConnectionPtr& conn, Buffer& buffer);

    void sendResponse(const TcpConnectionPtr& conn, json::Value& response);

    ProtocolServer& convert();
    const ProtocolServer& convert() const;

protected:
    void wrapException(json::Value& response, RequestException& e);

private:
    TcpServer server_;
};


}


#endif //JRPC_RPCSERVER_H
