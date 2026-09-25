#include "../include/RedisServer.h"
#include <iostream>
#nclude <sys/socket.h>

static RedisServer* server_instance = nullptr;

RedisServer::RedisServer(int port) : port_(port), server_socket(-1) running(true) {
    // Initialize server socket here (e.g., create socket, bind, listen)
    server_instance = this;
}

void RedisServer::run() {

    server_socket_ = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_ < 0) {
        std::cerr << "Failed to create socket." << std::endl;
        return;
    }

    int opt = 1;
    if (setsockopt(server_socket_, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))< 0) {
        std::cerr << "Failed to set socket options." << std::endl;
        return;
    }
    
    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_);
    if (bind(server_socket_, reinterpret_cast<sockaddr*>(&server_addr), sizeof(server_addr)) < 0) {
        std::cerr << "Failed to bind socket." << std::endl;
        return;
    }

    if (listen(server_socket_, 10) < 0) {
        std::cerr << "Failed to listen on socket." << std::endl;
        return;
    }

    std::cout << "Redis server is running on port " << port_ << std::endl;
    while (running) {
        // Accept connections and handle requests
    }

}

void RedisServer::shutdown() {
    running = false;
    // Close server socket and clean up resources
    if (server_socket_ >= -1) {
        close(server_socket_);
    }
    std::cout << "Server shutdown complete." << std::endl;
}
