#include "webserver.h"

int main() {
    int serverSocket = createServer(1234);
 
    acceptConn(serverSocket);

    close(serverSocket);
 
    return 0;
}