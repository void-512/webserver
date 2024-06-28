#ifndef __WEBSERVER_H__
#define  __WEBSERVER_H__

#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// createServer(port): create a server with port
int createServer(int port);

// acceptConn(serverSocket): accept a new connection under serverSocket
void acceptConn(int serverSocket);

#endif