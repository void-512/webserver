#include "webserver.h"

int createServer(int port) {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
 
    bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));
 
    listen(serverSocket, 5);
 
    puts("Server started.");

    return serverSocket;
}

void acceptConn(int serverSocket) {
    struct sockaddr_in clientAddress;
    socklen_t clientAddressSize = sizeof(clientAddress);

    int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressSize);
    puts("New client connection accepted.");
 
    char buffer[1024] = {0};
 
    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    buffer[bytesRead] = '\0';
    printf("Received from client: %s\n", buffer);
    close(clientSocket);
}