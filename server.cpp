#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in address = { 0, AF_INET, htons(8080), inet_addr("127.0.0.1") };
    socklen_t addrlen = sizeof address;
    bind(server, reinterpret_cast<sockaddr *>(&address), addrlen);
    listen(server, 128);
    int client = accept(server, reinterpret_cast<sockaddr *>(&address), &addrlen);
    char buffer[64];
    recv(client, buffer, 64, 0);
    send(client, buffer, 64, 0);
    close(client);
    close(server);
}
