#pragma once

#include <boost/asio.hpp>
#include <tcp_connection.h>

namespace Redis {

class Server {
    public:
    explicit Server(boost::asio::io_context& io_ctx);

    void start_accept();
    void handle_accept(tcp_connection::ptr conn, const boost::system::error_code& err);

    private:
    boost::asio::io_context& m_ctx;
    boost::asio::ip::tcp::acceptor m_acceptor;
};

}