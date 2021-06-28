#include <iostream>
#include <boost/asio.hpp>

int main(int argc, char* argv[])
{

    if(argc != 4)
    {
        std::cout<<"Wrong parameter\n"<<"Example usage ./client 127.0.0.1 1234 hello"<<std::endl;
        return -1;
    }
    auto const address = boost::asio::ip::make_address(argv[1]);
    auto const port = std::atoi(argv[2]);
    std::string msg = argv[3] + '\n';
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::socket socket(io_service);
    boost::system::error_code errorCode;
    socket.connect( boost::asio::ip::tcp::endpoint( address, port ),errorCode);
    if(errorCode){std::cout<<errorCode.message()<<std::endl; return 1;}
    boost::system::error_code error;
    boost::asio::write( socket, boost::asio::buffer(msg), error );
    boost::asio::streambuf receive_buffer;
    boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
    if( error && error != boost::asio::error::eof ) {
        std::cout << "receive failed: " << error.message() << std::endl;
    }
    else {
        const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
        std::cout << data << std::endl;
    }
    return 0;
}