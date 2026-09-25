#ifndef REDIS_SERVER_H
#define REDIS_SERVER_H

#include <atomic>
#include <string>

class RedisServer {
public:
    RedisServer(int port);
    void run();
    void shutdown();
    
private:
    int port_;
    int server_socket_;
    std::atomic<bool> running;
};

#endif // REDIS_SERVER_H