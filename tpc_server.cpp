#include <iostream>
#include <thread>
#include <functional>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <netinet/tcp.h>
#include <nlohmann/json.hpp
#include <fstream>

using namespace std;

struct ServerConfig {
    std::string ip;
    int port;
};

ServerConfig readServerConfig(const std::string& configFile) {
    std::ifstream file(configFile);
    nlohmann::json jsonConfig;
    file >> jsonConfig;

    ServerConfig config;
    config.ip = jsonConfig["ip"];
    config.port = jsonConfig["port"];

    return config;
}


struct sockaddr_in serverAddress;
serverAddress.sin_family = AF_INET; // юзаем в4 айпи
serverAddress.sin_addr.s_addr = inet_addr(config.server_ip.c_str()); // ловим соединение на любом интерфейсе
serverAddress.sin_port = htons(config.server_port);   // задаем порт

int main(){ 
    ServerConfig config = readServerConfig("server_config.json")
 int listener = socket(AF_INET, SOCK_STREAM, 0);
 std::cout << "Server work" << std::endl; 
 return 0;

     // тут мы ошибки обрабатываем
    if (listener < 0) {
        std::cout << "serveru pizda socket err" << std::endl;
        return 1;
    }

    close(clientSoket); // фикс утечки ресурсов
}