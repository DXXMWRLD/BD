//
// Created by dxxmwrld on 28.06.2021.
//

#ifndef PROJECTSERVER_CONNECTION_H
#define PROJECTSERVER_CONNECTION_H
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>

class Connection : public std::enable_shared_from_this<Connection> {
private:
    boost::asio::ip::tcp::socket socket;
    enum {
        max_length = 1024
    };
    char data[max_length];
public:
    Connection(boost::asio::io_service &io_service);

    boost::asio::ip::tcp::socket &getSocket();

    void read();

    void write();

    void handleRead(const boost::system::error_code &err, size_t bytes_transferred);

    void handleWrite(const boost::system::error_code &err, size_t bytes_transferred);
};
#endif //PROJECTSERVER_CONNECTION_H
