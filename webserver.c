#include "webserver.h"

int createServer(int port) {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        sys_err("Failed to create serverSocket");
    }
    
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(port);
 
    bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));
    listen(serverSocket, 5);
    puts("Server started.");

    return serverSocket;
}

int createConn(int serverSocket) {
    struct sockaddr_in clientAddress;
    socklen_t clientAddressSize = sizeof(clientAddress);

    int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressSize);
    if (clientSocket == -1) {
        sys_err("Failed to create clientSocket");
    }
    puts("New client connection accepted.");

    return clientSocket;
}

void rewriteUpper(int clientSocket) {
    char buffer[BUFSIZ] = {0};

    while (1) {
        ssize_t msg_len = read(clientSocket, buffer, sizeof(buffer));
        buffer[msg_len] = '\0';
        if (!msg_len) {
            puts("Client closed the connection");
            close(clientSocket);
            break;
        }
        for (int i = 0; i < msg_len; i++) {
            buffer[i] = toupper(buffer[i]);
        }
        write(clientSocket, buffer, msg_len);
    }
}

void sys_err(const char *str) {
    perror(str);
    exit(1);
}