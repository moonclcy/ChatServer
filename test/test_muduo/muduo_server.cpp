/*
muduo网络库给用户提供两个主要的类
TcpServer ：用于编写服务器程序的
TcpClient ：用于编写客户端程序的

epoll + 线程池
好处： 能把网络的I/O的代码和业务代码区分开

                    用户的连接和断开      用户的可读写事件
*/ 


#include<muduo/net/TcpServer.h>
#include<muduo/net/EventLoop.h>
#include<iostream>
#include<functional>
#include<string>
using namespace std;
using namespace muduo;
using namespace muduo::net;
using namespace placeholders;


/*
服务器类，基于muduo库开发
1.组合TcpServer对象
2.创建EventLoop事件循环对象的指针
3.明确TcpServer构造函数需要什么参数，输出chatServer的构造函数
4.在当前服务器类的构造函数当中，注册处理连接的回调函数和处理读写事件的回调函数
5.设置合适的服务端线程数量， muduo库会自己分配I/O线程和worker线程
*/
class chatServer
{
public:
    // 初始化TcpServer
    chatServer(muduo::net::EventLoop *loop,    //事件循环
               const muduo::net::InetAddress &listenAddr,     //IP+Port
               const string &nameArg)       //服务器的名字
        : _server(loop, listenAddr, nameArg), _loop(loop)
    {
        // 通过绑定器设置回调函数
        //给服务器注册用户连接的创建和断开回调
        //#4
        _server.setConnectionCallback(bind(&chatServer::onConnection, this, _1));   //_1 :参数占位符

        //给服务器注册用户读写事件回调
        _server.setMessageCallback(bind(&chatServer::onMessage, this, _1, _2, _3));

        // 设置EventLoop（服务器端）的线程个数   1个I/O线程   9个worker线程
        //#5
        _server.setThreadNum(10);
    }

    //开启事件循环
    void start(){
        _server.start();
    }

private:
    //#3
    //专门处理用户的连接创建和断开  epoll  listenfd  accept
    void onConnection(const TcpConnectionPtr &conn){
        if (conn->connected())
        {
            cout << conn->peerAddress().toIpPort() << " - >"  << conn->localAddress().toIpPort() << " 连接上了 " << endl;
        }

        else{
            cout << conn->peerAddress().toIpPort() << " - >"  << conn->localAddress().toIpPort() << " 连接断开 " << endl;
            conn->shutdown();
            //_loop->quit();
        }
            
    }

    //专门处理用户的读写事件
    void onMessage(const muduo::net::TcpConnectionPtr &conn, // 连接
                   Buffer *buffer,                             // 缓冲区
                   Timestamp time)                          // 接受到数据的时间信息
    {
        string buf = buffer->retrieveAllAsString();
        cout << "recv data:" << buf << "time" << time.toString() << endl;
        conn->send(buf);
    }

    TcpServer _server;      //#1
    EventLoop *_loop;       //#2 epoll 
};


int main(){

    EventLoop loop;   //like epoll
    InetAddress addr("127.0.0.0.1", 6000);
    chatServer server(&loop, addr, "chatServer");

    server.start();     //listenfd epoll_ctl 连接到 epoll
    loop.loop();        //epoll_wait  以阻塞的方式等待新用户连接，或已连接用户的读写事件等

    return 0;
}
