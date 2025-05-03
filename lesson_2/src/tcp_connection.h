#pragma once

#include <memory>
#include <boost/asio.hpp>

namespace Redis {

class tcp_connection : public std::enable_shared_from_this<tcp_connection> {
public:
    using ptr = std::shared_ptr<tcp_connection>;
    using io_ctx = boost::asio::io_context;

    [[nodiscard]] static ptr create(io_ctx& ctx);
    [[nodiscard]] boost::asio::ip::tcp::socket& socket();
    void start();

private:
    tcp_connection(io_ctx& ctx);
    void handle_write();

    boost::asio::ip::tcp::socket m_socket;
    std::string m_message;

};

}