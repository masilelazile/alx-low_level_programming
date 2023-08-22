#!/bin/bash
gcc -fPIC -C *.c
gcc -shared *.o -o liball.so
