#! /bin/bash

kill `ps | grep "server" | awk '{print $1}'`
cmake .
make 
./server& 
sleep 3000
./client 

