#ifndef __WEBSERVER_H__
#define  __WEBSERVER_H__

#define DEFAULT_PORT 17104

#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

// createServer(port): create a server with port
int createServer(int port);

// createConn(serverClient): returns a client socket under serverSocket
int createConn(int serverClient);

// rewriteUpper(clientSocket): rewrite the string back to the client with upper characters
void rewriteUpper(int clientSocket);

// sys_err(str): output error with str and return 1
void sys_err(const char *str);

#endif