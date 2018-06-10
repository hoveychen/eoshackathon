#!/bin/bash

keys=(
EOS6K3bgKqSQK4AYKrxQuCpQWQ2FpAsZRuwY6bVVsGQWzRoGKYQLd
EOS5BiyiCdoEE9BsLY1UKWAv4bF2cA7rdjgRYvSb23vsqnVTVidqM
EOS87F7j85onKhqQ9xRGJtNne6bX8o1b2d2xBDcJPZ4gT2358qWRd
EOS5Gdr9LgF4gTu55DNqW66cSM2esWr2kv8uFYcJNgK5Jbgp3Qb43
EOS8fTwASL4nttXe5CTqRWdvEZ9GqWEM5EcJ7662F4jPUGAR9JJLb
EOS6GcGfetJPGkX3GPjT3UGtidSLdvC7X6Tx2iE4Udn9U3MdvCvLA
EOS6ZKDUHEyoZWtgvEfhJ9vpz9vpVJmnscDRgw6CWKaX9QiKUYDpk
EOS6PGnRrrebrtGskhGPd5tmwxXzrPkVU2dkoK7EUZDyAnrihiPDf
EOS7a5w2gg794MrPawLV1rPQFgfXBb6o34PB1jBtMxZhgMJv3y8P7
EOS8MSsLvs3Sa7XzJc9rFQZbsLfUTap13Txev53xmiByMVbFJ9Lai
)

eval $(docker-machine env eosio)
cleos='docker exec eosio /opt/eosio/bin/cleos --wallet-url http://192.168.99.100:8888'
$cleos wallet unlock --password "PW5J4Ue6ykiDTuwrrAwNiVTLqRirNXJWJTELvGQGzonmKAj5Vo4Dg"

for i in ${!keys[@]}; do
    $cleos create account eosio user$(($i / 5 + 1))$(($i % 5 + 1)) ${keys[$i]} ${keys[$i]}
done

$cleos create account eosio cleanit EOS7GANQrkRcbpEyFKZEuwM2FdSDDS7SS2bPNdM8VVLCvtRH4UMbN EOS7GANQrkRcbpEyFKZEuwM2FdSDDS7SS2bPNdM8VVLCvtRH4UMbN
