#pragma once

#include <string>

#define BLOCK_SIZE  4096

class Protocoler
{
public:
    Protocoler();
    bool insert(const char * data);

    ~Protocoler();

    const char * getBLock();

    bool checkFull(const char * data);
    
    void clear();

private:
    unsigned int _fullLength;
    unsigned int _dataLength;
    char * _data;

    std::string _tmp;
};

 
