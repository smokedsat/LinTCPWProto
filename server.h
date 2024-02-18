#pragma once

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "protocoler.h"

#define PORT 8080

class Server
{
    Server()
    {
        _protocoler.insert("help me");
        
    }

    bool run();

private:
    Protocoler _protocoler;

};
