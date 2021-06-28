//
// Created by dxxmwrld on 28.06.2021.
//

#include "Server.h"

void Server::startAccept()
{
    std::shared_ptr<Connection> newConnection = std::make_shared<Connection>(ioService);

    acceptor.async_accept(newConnection->getSocket(),
                          boost::bind(&Server::handleAccept, this, newConnection,
                                      boost::asio::placeholders::error));
}
Server::Server(boost::asio::io_service& ioService_, std::string address, unsigned int port):
        acceptor(ioService_, boost::asio::ip::tcp::endpoint(boost::asio::ip::make_address(address), port)), ioService(ioService_)
{
    startAccept();
}
void Server::handleAccept(std::shared_ptr<Connection> con, const boost::system::error_code& err)
{
    if (!err) {
        con->read();
    }
    startAccept();
}