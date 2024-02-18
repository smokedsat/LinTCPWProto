#include "protocoler.h"

#include <string.h>
#include <cstring>
#include <iostream>
#include <sstream>

Protocoler::Protocoler()
{
    _fullLength = 0;
    _dataLength = 0;
    _data = new char[BLOCK_SIZE];
}

bool Protocoler::insert(const char * data)
{
    _dataLength = strlen((const char*)data);

    if(_dataLength >= BLOCK_SIZE)
    {
        return false;
    }

    const char * lengthStr = std::to_string(_dataLength).c_str();

    unsigned int sizeLength = strlen(lengthStr);


    _fullLength = _dataLength + sizeLength;

    if(_fullLength > BLOCK_SIZE)
    {
        std::cout << "Full length of message > than BLOCK_SIZE. Curr fulllength: "<< _fullLength << std::endl;
        return false;
    }

    _tmp = lengthStr;
    _tmp += "\n";
    _tmp += data;

    strcpy(_data, _tmp.c_str());

    return true;
}

Protocoler::~Protocoler()
{
    if(_data)
    {
        delete _data;
    }
}

const char *Protocoler::getBLock()
{
    return _data;
}

bool Protocoler::checkFull(const char *data)
{
    std::stringstream strstream(data);
    std::string sizeStr;
    unsigned int presize;
    unsigned int fullsize = strlen(data);
    unsigned int datasize;

    if(strstream >> sizeStr)
    {
        presize = sizeStr.size() + 1;
        datasize = atoi(sizeStr.c_str());

        if(fullsize - presize != datasize)
        {
            return false;
        }
        return true;
    }
    return false;
}

void Protocoler::clear()
{
    if(_data)
    {
        delete _data;
    }

    _data = new char[BLOCK_SIZE];
}