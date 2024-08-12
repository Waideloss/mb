#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

int main() {
    // Создание сокета
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        cerr << "Ошибка при создании сокета" << endl;
        return 1;
    }

    // Настройка адреса сервера
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET; // Используем IPv4
    serverAddress.sin_port = htons(8080); // Укажите порт, на который слушает сервер

    // Укажите IP-адрес сервера
    const char* server_ip = "127.0.0.1"; // Замените на IP-адрес вашего сервера
    if (inet_pton(AF_INET, server_ip, &serverAddress.sin_addr) <= 0) {
        cerr << "Неверный адрес" << endl;
        return 1;
    }

    // Подключение к серверу
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        cerr << "Ошибка при подключении к серверу" << endl;
        return 1;
    }

    cout << "Подключено к серверу" << endl;

    // Здесь можно добавить код для общения с сервером

    close(clientSocket); // Закрываем сокет клиента
    return 0;
}