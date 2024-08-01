using System;
using System.Net.Sockets;
using System.Text;

class Client
{
    static void Main(string[] args)
    {
        const string server = "127.0.0.1";
        const int port = 8080;

        using (TcpClient client = new TcpClient(server, port))
        {
            NetworkStream stream = client.GetStream();
            string message = "Привет, сервер!";
            byte[] data = Encoding.UTF8.GetBytes(message);

            // Отправка сообщения серверу
            stream.Write(data, 0, data.Length);
            Console.WriteLine($"Отправлено: {message}");

            // Чтение ответа от сервера
            byte[] buffer = new byte[1024];
            int bytesRead = stream.Read(buffer, 0, buffer.Length);
            string response = Encoding.UTF8.GetString(buffer, 0, bytesRead);
            Console.WriteLine($"Получено: {response}");
        }
    }
}