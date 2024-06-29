#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

// sys_err(str): puts error message and exit
void sys_err(const char *str) {
    perror(str);
    exit(1);
}

// getAddress(argc, argv): returns struct of server address
struct sockaddr *getAddress(int argc, char **argv) {
    char address[BUFSIZ] = {0};
    int port = 0;
    if (argc != 3) {
        puts("./client [ip] [port]");
    } else {
        strcpy(address, argv[1]);
        port = atoi(argv[2]);
    }

    struct sockaddr_in *serverAddress = malloc(sizeof(struct sockaddr_in));
    serverAddress -> sin_family = AF_INET;
    serverAddress -> sin_port = htons(port);
    inet_pton(AF_INET, address, &serverAddress -> sin_addr.s_addr);

    return (struct sockaddr *)serverAddress;
}

// createConn(serverAddress): creates connection with serverAddress and returns file descriptor to the connection
int createConn(struct sockaddr *serverAddress) {
    int cfd = socket(AF_INET, SOCK_STREAM, 0);
    if (cfd == -1) {
        sys_err("Failed to create socket");
    }

    int connResult = connect(cfd, serverAddress, sizeof(*serverAddress));
    if (connResult != 0) {
        sys_err("Failed to connect to server");
    } else {
        puts("Connection success");
    }

    return cfd;
}

int main(int argc, char **argv) {

    struct sockaddr *address = getAddress(argc, argv);

    int cfd = createConn(address);

    char *line = NULL;
    size_t linelen = 0;

    char readbuffer[BUFSIZ];

    while(1) {
        getline(&line, &linelen, stdin);
        write(cfd, line, linelen);
        read(cfd, readbuffer, sizeof(readbuffer));
        puts(readbuffer);
    }

    free(address);

    return 0;
}