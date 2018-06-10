#!/bin/bash

eval $(docker-machine env eosio)
cleos='docker exec eosio /opt/eosio/bin/cleos --wallet-url http://192.168.99.100:8888'

$cleos wallet unlock --password "PW5J4Ue6ykiDTuwrrAwNiVTLqRirNXJWJTELvGQGzonmKAj5Vo4Dg"
docker stop eosio
docker run --rm --name eosio -d -p 0.0.0.0:8888:8888 -p 0.0.0.0:9876:9876 -v /tmp/work:/work -v /tmp/eosio/data:/mnt/dev/data -v /tmp/eosio/config:/mnt/dev/config eosio/eos-dev  /bin/bash -c "nodeos --delete-all-blocks -e -p eosio --plugin eosio::wallet_api_plugin --plugin eosio::wallet_plugin --plugin eosio::producer_plugin --plugin eosio::history_plugin --plugin eosio::chain_api_plugin --plugin eosio::history_api_plugin --plugin eosio::http_plugin -d /mnt/dev/data --config-dir /mnt/dev/config --http-server-address=0.0.0.0:8888 --access-control-allow-origin=* --contracts-console"
source create_users.sh
source deploy.sh
