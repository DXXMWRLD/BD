//
// Created by dxxmwrld on 28.06.2021.
//

#ifndef PROJECTSERVER_SERVER_H
#define PROJECTSERVER_SERVER_H
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/bind.hpp>
#include "Connection.h"

class Server
{
private:
    boost::asio::ip::tcp::acceptor acceptor;
    boost::asio::io_service &ioService;
    void startAccept();
public:
//constructor for accepting connection from client
    Server(boost::asio::io_service& ioService_, std::string address, unsigned int port);
    void handleAccept(std::shared_ptr<Connection> con, const boost::system::error_code& err);
};


#endif //PROJECTSERVER_SERVER_H
