//
// Created by frank on 17-12-31.
//

#ifndef JRPC_UTIL_H
#define JRPC_UTIL_H

#include <string>
#include <string_view>

#include <tinyev/EventLoop.h>
#include <tinyev/TcpConnection.h>
#include <tinyev/TcpServer.h>
#include <tinyev/InetAddress.h>
#include <tinyev/Buffer.h>
#include <tinyev/Logger.h>

namespace jrpc
{

using namespace std::literals::string_view_literals;

using tinyev::EventLoop;
using tinyev::TcpConnection;
using tinyev::TcpServer;
using tinyev::InetAddress;
using tinyev::TcpConnectionPtr;
using tinyev::noncopyable;
using tinyev::Buffer;

using std::placeholders::_1;
using std::placeholders::_2;
using std::placeholders::_3;
using std::placeholders::_4;

}

#endif //JRPC_UTIL_H
