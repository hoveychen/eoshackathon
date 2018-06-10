#!/bin/bash

eval $(docker-machine env eosio)
cleos='docker exec eosio /opt/eosio/bin/cleos --wallet-url http://192.168.99.100:8888'

$cleos wallet unlock --password "PW5J4Ue6ykiDTuwrrAwNiVTLqRirNXJWJTELvGQGzonmKAj5Vo4Dg"
docker exec eosio mkdir -p /contracts/cleanit
docker cp cleanit.abi eosio:/contracts/cleanit/
docker cp cleanit.wasm eosio:/contracts/cleanit/
$cleos set contract cleanit contracts/cleanit
