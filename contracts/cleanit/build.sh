#!/bin/bash

eval $(docker-machine env eosio)
docker cp cleanit.cpp eosio:/tmp/
docker cp cleanit.hpp eosio:/tmp/
docker exec eosio eosiocpp -o cleanit /tmp/cleanit.cpp
docker exec eosio eosiocpp -g cleanit.abi  /tmp/cleanit.cpp 
docker cp eosio:/cleanit.abi .
docker cp eosio:/cleanit.wasm .