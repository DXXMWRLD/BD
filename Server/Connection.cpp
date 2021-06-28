//
// Created by dxxmwrld on 28.06.2021.
//

#include "Connection.h"

Connection::Connection(boost::asio::io_service& io_service)
    : socket(io_service) {
}
boost::asio::ip::tcp::socket& Connection::getSocket() {
    return socket;
}
void Connection::read() {
    socket.async_read_some(
            boost::asio::buffer(data, maxLength),
            boost::bind(&Connection::handleRead,
                        shared_from_this(),
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));
}
void Connection::write() {
    socket.async_write_some(
            boost::asio::buffer(data, maxLength),
            boost::bind(&Connection::handleWrite,
                        shared_from_this(),
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));
    std::memset(data, 0, maxLength);
}
void Connection::handleRead(const boost::system::error_code &err, size_t bytes_transferred) {
    if (!err) {
        std::cout << data << std::endl;
    } else {
        std::cerr << "error: " << err.message() << std::endl;
        socket.close();
    }
    write();
}
void Connection::handleWrite(const boost::system::error_code& err, size_t bytes_transferred) {
    if (err) {
        std::cerr << "error: " << err.message() << std::endl;
        socket.close();
    }
}