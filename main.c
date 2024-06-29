#include "webserver.h"

int main() {
    int serverSocket = createServer(DEFAULT_PORT);
 
    while (1) {
        int clientSocket = createConn(serverSocket);
        rewriteUpper(clientSocket);
    }

    close(serverSocket);
 
    return 0;
}