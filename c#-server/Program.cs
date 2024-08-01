using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

class Program
{
    private const int PORT = 8080;

    static async Task Main(string[] args)
    {
        TcpListener server = new TcpListener(IPAddress.Any, PORT);
        server.Start();
        Console.WriteLine($"Сервер запущен на порту {PORT}");

        while (true)
        {
            var client = await server.AcceptTcpClientAsync();
            _ = HandleClientAsync(client);
        }
    }

    private static async Task HandleClientAsync(TcpClient client)
    {
        Console.WriteLine("Клиент подключен.");
        var buffer = new byte[1024];
        var stream = client.GetStream();

        // Чтение данных от клиента
        int bytesRead = await stream.ReadAsync(buffer, 0, buffer.Length);
        string message = Encoding.UTF8.GetString(buffer, 0, bytesRead);
        Console.WriteLine($"Получено сообщение: {message}");

        // Отправка ответа клиенту
        string response = "Привет от сервера!";
        byte[] responseBytes = Encoding.UTF8.GetBytes(response);
        await stream.WriteAsync(responseBytes, 0, responseBytes.Length);

        // Закрытие соединения
        client.Close();
        Console.WriteLine("Соединение с клиентом закрыто.");
    }
}