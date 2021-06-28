#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>

enum { max_length = 1024 };

int main(int argc, char* argv[]) {
    try {
        if (argc != 4) {
            std::cerr << "Usage: ./Client <address> <port> <message>\n";
            return 1;
        }
        boost::asio::io_service io_service;
        boost::asio::ip::tcp::resolver resolver(io_service);
        boost::asio::ip::tcp::resolver::query query(boost::asio::ip::tcp::v4(), argv[1], argv[2]);
        boost::asio::ip::tcp::resolver::iterator iterator = resolver.resolve(query);
        boost::asio::ip::tcp::socket s(io_service);
        boost::asio::connect(s, iterator);
        char message[max_length];
        std::strcpy(message, argv[3]);
        size_t request_length = std::strlen(message);
        boost::asio::write(s, boost::asio::buffer(message, request_length));
        boost::asio::read(s, boost::asio::buffer(message, request_length));
        std::cout << message << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}