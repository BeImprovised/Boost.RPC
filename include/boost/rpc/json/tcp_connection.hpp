#ifndef _BOOST_RPC_TCP_CONNECTION_HPP_
#define _BOOST_RPC_TCP_CONNECTION_HPP_
#include <boost/rpc/json/connection.hpp>
#include <boost/cmt/asio/tcp/socket.hpp>
#include <boost/asio.hpp>

namespace boost { namespace rpc { namespace json {

class tcp_connection : public boost::rpc::json::connection {
  public:
      typedef boost::shared_ptr<tcp_connection> ptr;
      typedef boost::weak_ptr<tcp_connection>   wptr;

      /**
       *  @param t - the thread in which messages will be sent and callbacks invoked
       */
      tcp_connection( const cmt::asio::tcp::socket::ptr& sock,
                      cmt::thread* t = &cmt::thread::current() );

      virtual ~tcp_connection();

  protected:
      friend class tcp_connection_private;
      virtual void send( const rpc::json::value& msg );

      class tcp_connection_private* my;
};

} } } // namespace boost::rpc::json

#endif //_BOOST_RPC_TCP_CONNECTION_HPP_