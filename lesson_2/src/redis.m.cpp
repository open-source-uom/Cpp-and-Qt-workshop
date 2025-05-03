#include <fmt/core.h>
#include <boost/asio/io_context.hpp>

#include <redis_server.h>
#include <iostream>

int main()
{
  try
  {
    boost::asio::io_context ctx;
    Redis::Server server(ctx);

    server.start_accept();

    ctx.run();
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}