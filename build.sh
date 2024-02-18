#!/bin/bash

g++ -c protocoler.o protocoler.cpp
g++ -o program main.cpp protocoler.o