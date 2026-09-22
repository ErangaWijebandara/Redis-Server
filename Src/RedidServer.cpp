#include "../include/RedisServer.h"

static RedisServer* server_instance = nullptr;

RedisServer::RedisServer(int port) : port_(port), server_socket(-1) running(true) {
    // Initialize server socket here (e.g., create socket, bind, listen)
    server_instance = this;
}

