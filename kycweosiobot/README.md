# `kyceosiobot`

## Actions
* `addmodkyc`

## Tables
* `kyc`

## Compile
```console
$ eosio-cpp kycweosiobot.cpp -o kycweosiobot.wasm
Warning, empty ricardian clause file
Warning, empty ricardian clause file
Warning, action <addmodkyc> does not have a ricardian contract
Warning, action <delkyc> does not have a ricardian contract
Warning, action <addmodkyc> does not have a ricardian contract
Warning, action <delkyc> does not have a ricardian contract
```

## Deploy
* deploy contract
```console
$ cleost set contract kycweosiobot ./
Reading WASM from /mnt/f/Coding/github_repos/eosio_kyc_contracts/kycweosiobot/kycweosiobot.wasm...
Publishing contract...
executed transaction: 4dd5ebe73b6670c3c9580a014c6acd9f1468554ee5255dea28474ecc81d2cd19  8192 bytes  1008 us
#         eosio <= eosio::setcode               {"account":"kycweosiobot","vmtype":0,"vmversion":0,"code":"0061736d0100000001cb011e60000060047f7f7f7...
#         eosio <= eosio::setabi                {"account":"kycweosiobot","abi":"0e656f73696f3a3a6162692f312e310003096164646d6f646b796300060c706c617...
warning: transaction executed locally, but may not be confirmed by the network yet         ]
```
* Adding eosio.code to permissions (for inline actions)
```console
$ cleost set account permission kycweosiobot active --add-code
executed transaction: 0a16c342756a923b87b5f5cd8213c68cb3fbd86535cca6da5c90d3d1121b6de1  184 bytes  157 us
#         eosio <= eosio::updateauth            {"account":"kycweosiobot","permission":"active","parent":"owner","auth":{"threshold":1,"keys":[{"key...
warning: transaction executed locally, but may not be confirmed by the network yet         ]
```

## Testing
### Upload KYC data
* Here, the contract's ACTION used: `addmodkyc`
* The permission used in this is `active` of `kycweosiobot` Contract.

#### Demo:
* `kycusr111111` adds KYC data
```console
$ cleost push action kycweosiobot addmodkyc '["2143454254", "Ramesh Sisodia", "490, first floor, \nSector 98, Mohali, \nPunjab-160098", "cc2370f40df7faab22d433e93178e5a13f475c0556cc03dd1d431cfcdb220ae3", "a36fa66069053120eaf3ee4639a4663f31e6f50528d9c4b0f7b3c4b18a6dd79b", "b52d373fdbd5b321399401c2d9d6ca83c2267bb42d403a057a858e1ed67228d7"]' -p kycweosiobot@active
executed transaction: 53ea742654ce7b9218821fc13fb28252f329c493d3bfb8e83d5d26fa1fc9c0ee  368 bytes  230 us
#  kycweosiobot <= kycweosiobot::addmodkyc      {"plat_user_id":2143454254,"fullname":"Ramesh Sisodia","address":"490, first floor, \nSector 98, Moh...
warning: transaction executed locally, but may not be confirmed by the network yet         ]
```
* read table
```console
$ cleost get table kycweosiobot kycweosiobot kyc --show-payer --lower 2143454254 --upper 2143454254
{
  "rows": [{
      "data": {
        "plat_user_id": 2143454254,
        "fullname": "Ramesh Sisodia",
        "address": "490, first floor, \nSector 98, Mohali, \nPunjab-160098",
        "document_id_front_hash": "cc2370f40df7faab22d433e93178e5a13f475c0556cc03dd1d431cfcdb220ae3",
        "document_id_back_hash": "a36fa66069053120eaf3ee4639a4663f31e6f50528d9c4b0f7b3c4b18a6dd79b",
        "selfie_hash": "b52d373fdbd5b321399401c2d9d6ca83c2267bb42d403a057a858e1ed67228d7"
      },
      "payer": "kycweosiobot"
    }
  ],
  "more": false,
  "next_key": "",
  "next_key_bytes": ""
}
```

### Modify KYC data
#### Just update the document_id, but only back side
* `kycusr111111` modify KYC
```console
$ cleost push action kycweosiobot addmodkyc '["2143454254", "", "", "cc2370f40df7faab22d433e93178e5a13f475c0556cc03dd1d431cfcdb220ae3", "7bad2d80e005b955f19f2221b3ad1ca86fdb4f788a45a02504a6929dcf870155", "b52d373fdbd5b321399401c2d9d6ca83c2267bb42d403a057a858e1ed67228d7"]' -p kycweosiobot@active
executed transaction: 53ea742654ce7b9218821fc13fb28252f329c493d3bfb8e83d5d26fa1fc9c0ee  368 bytes  230 us
#  kycweosiobot <= kycweosiobot::addmodkyc      {"plat_user_id":2143454254,"fullname":"Ramesh Sisodia","address":"490, first floor, \nSector 98, Moh...
warning: transaction executed locally, but may not be confirmed by the network yet         ]
```
* read table
```console
$ cleost get table kycweosiobot kycweosiobot kyc --show-payer --lower 2143454254 --upper 2143454254
{
  "rows": [{
      "data": {
        "plat_user_id": 2143454254,
        "fullname": "",
        "address": "490, first floor, \nSector 98, Mohali, \nPunjab-160098",
        "document_id_front_hash": "cc2370f40df7faab22d433e93178e5a13f475c0556cc03dd1d431cfcdb220ae3",
        "document_id_back_hash": "7bad2d80e005b955f19f2221b3ad1ca86fdb4f788a45a02504a6929dcf870155",
        "selfie_hash": "b52d373fdbd5b321399401c2d9d6ca83c2267bb42d403a057a858e1ed67228d7"
      },
      "payer": "kycweosiobot"
    }
  ],
  "more": false,
  "next_key": "",
  "next_key_bytes": ""
}
``` 


### Read KYC data from Blockchain
```console
$ cleost get table kycweosiobot kycweosiobot kyc --show-payer --lower 2143454254 --upper 2143454254
{
  "rows": [{
      "data": {
        "plat_user_id": 2143454254,
        "fullname": "Ramesh Sisodia",
        "address": "490, first floor, \nSector 98, Mohali, \nPunjab-160098",
        "document_id_front_hash": "cc2370f40df7faab22d433e93178e5a13f475c0556cc03dd1d431cfcdb220ae3",
        "document_id_back_hash": "a36fa66069053120eaf3ee4639a4663f31e6f50528d9c4b0f7b3c4b18a6dd79b",
        "selfie_hash": "b52d373fdbd5b321399401c2d9d6ca83c2267bb42d403a057a858e1ed67228d7"
      },
      "payer": "kycweosiobot"
    }
  ],
  "more": false,
  "next_key": "",
  "next_key_bytes": ""
}
```

### Delete KYC data