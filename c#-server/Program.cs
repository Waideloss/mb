using System;
using System.net;
using System.net.Sockets;
using System.Net.Sockets;
using System.Net;
using System.text;
using System.Threading.Tasks;

class Programm
{
    private const int PORT = 3500;

    static async Task Main(string[] args)
    {
        TcpListener server = new TcpListener(IPAddress.Any, PORT);
        server.Start();
        Console.WriteLine($"Сервер заущен на порту {PORT}");

        while (true)
        {
            var client = await server.AcceptTcpClientAsinc();
            _ = HandleClientAsync(client);
        }
    }
}