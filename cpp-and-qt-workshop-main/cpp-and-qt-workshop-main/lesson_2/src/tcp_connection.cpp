#include <tcp_connection.h>
#include <boost/bind.hpp>
#include <fmt/format.h>

namespace {
std::string make_test_string() {
    return "abcd";
}
}

using namespace Redis;

tcp_connection::tcp_connection(boost::asio::io_context& ctx)
 : m_socket(ctx)
{
}

// static constructor
tcp_connection::ptr 
tcp_connection::create(boost::asio::io_context& ctx)
{
    return tcp_connection::ptr(new tcp_connection(ctx));
}

boost::asio::ip::tcp::socket&
tcp_connection::socket() {
    return m_socket;
}

void
tcp_connection::start() {
    m_message = make_test_string();
    auto bind_call = boost::bind(&tcp_connection::handle_write, shared_from_this());
    boost::asio::async_write(m_socket, boost::asio::buffer(m_message), bind_call);
}

void
tcp_connection::handle_write() {
    fmt::print("Writting data\n");
}
