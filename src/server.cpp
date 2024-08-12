#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
    // Создание сокета
    int listener = socket(AF_INET, SOCK_STREAM, 0);
    
    // Проверка на ошибки
    if (listener < 0) {
        std::cout << "Ошибка при создании сокета" << std::endl;
        return 1;
    }
    
    // Настройка адреса сервера
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET; // Используем IPv4
    serverAddress.sin_addr.s_addr = INADDR_ANY; // Принимаем соединения на любом интерфейсе
    serverAddress.sin_port = htons(8080); // Задаем порт

    // Привязка сокета к адресу
    if (bind(listener, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cout << "Ошибка при привязке сокета" << std::endl;
        close(listener); // Закрываем сокет
        return 1;
    }

    // Начинаем прослушивание
    if (listen(listener, 5) < 0) {
        std::cout << "Ошибка при прослушивании" << std::endl;
        close(listener); // Закрываем сокет
        return 1;
    }

    std::cout << "Сервер запущен и ожидает соединений на порту 8080" << std::endl;

    // Основной цикл для принятия соединений
    while (true) {
        struct sockaddr_in clientAddress;
        socklen_t clientAddressLength = sizeof(clientAddress);
        
        // Принятие соединения
        int clientSocket = accept(listener, (struct sockaddr*)&clientAddress, &clientAddressLength);
        if (clientSocket < 0) {
            std::cout << "Ошибка при принятии соединения" << std::endl;
            continue; // Продолжаем ожидание новых клиентов
        }

        std::cout << "Клиент подключен" << std::endl;

        // Здесь можно добавить код для общения с клиентом

        close(clientSocket); // Закрываем сокет клиента
    }

    close(listener); // Закрываем основной сокет
    return 0; // Завершение программы
}