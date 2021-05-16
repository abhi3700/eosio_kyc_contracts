# `kyceosiobot`

## Actions
* `addmodkyc`
* `delkyc`

## Tables
* `kyc`

## Compile
```console
$ eosio-cpp kycteosiobot.cpp -o kycteosiobot.wasm
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
$ cleost set contract kycteosiobot ./
Reading WASM from /mnt/f/Coding/github_repos/eosio_kyc_contracts/kycteosiobot/kycteosiobot.wasm...
Publishing contract...
executed transaction: 08a2c3e7b85614b012185491aa8bb3446e90b9119c4b0055474cdd2549bc9ae3  8192 bytes  963 us
#         eosio <= eosio::setcode               {"account":"kycteosiobot","vmtype":0,"vmversion":0,"code":"0061736d0100000001cb011e60000060047f7f7f7...
#         eosio <= eosio::setabi                {"account":"kycteosiobot","abi":"0e656f73696f3a3a6162692f312e310003096164646d6f646b796300060c706c617...
warning: transaction executed locally, but may not be confirmed by the network yet         ]
```
* Adding eosio.code to permissions (for inline actions)
```console
$ cleost set account permission kycteosiobot active --add-code
executed transaction: 6464c5ea84dd600325340ba3b18506edf8b5b9c12a7c30eebbb46032a109e5d9  184 bytes  123 us
#         eosio <= eosio::updateauth            {"account":"kycteosiobot","permission":"active","parent":"owner","auth":{"threshold":1,"keys":[{"key...
warning: transaction executed locally, but may not be confirmed by the network yet         ]
```

## Testing
### Upload KYC data
* Here, the contract's ACTION used: `addmodkyc`
* The permission used in this is `active` of `kycweosiobot` Contract.

#### Demo:
* `kycusr111111` adds KYC data
```console
$ cleost push action kycteosiobot addmodkyc '["2143454254", "Ramesh Sisodia", "490, first floor, \nSector 98, Mohali, \nPunjab-160098", "cc2370f40df7faab22d433e93178e5a13f475c0556cc03dd1d431cfcdb220ae3", "a36fa66069053120eaf3ee4639a4663f31e6f50528d9c4b0f7b3c4b18a6dd79b", "b52d373fdbd5b321399401c2d9d6ca83c2267bb42d403a057a858e1ed67228d7"]' -p kycteosiobot@active
executed transaction: b5e207a1dc2cd07acafc859c4213b4a06d6a13ac3e9bd619badd54d2f5221d47  368 bytes  190 us
#  kycteosiobot <= kycteosiobot::addmodkyc      {"plat_user_id":2143454254,"fullname":"Ramesh Sisodia","address":"490, first floor, \nSector 98, Moh...
warning: transaction executed locally, but may not be confirmed by the network yet         ]
```
* read table
```console
$ cleost get table kycteosiobot kycteosiobot kyc --show-payer --lower 2143454254 --upper 2143454254
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
      "payer": "kycteosiobot"
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
$ cleost push action kycteosiobot addmodkyc '["2143454254", "", "", "cc2370f40df7faab22d433e93178e5a13f475c0556cc03dd1d431cfcdb220ae3", "7bad2d80e005b955f19f2221b3ad1ca86fdb4f788a45a02504a6929dcf870155", "b52d373fdbd5b321399401c2d9d6ca83c2267bb42d403a057a858e1ed67228d7"]' -p kycteosiobot@active
executed transaction: 374fac05b0ff82f645cb69632fd37e357679a3c0c91925a2d6ac85e43a2a5ad9  304 bytes  131 us
#  kycteosiobot <= kycteosiobot::addmodkyc      {"plat_user_id":2143454254,"fullname":"","address":"","document_id_front_hash":"cc2370f40df7faab22d4...
warning: transaction executed locally, but may not be confirmed by the network yet         ]
```
* read table
```console
$ cleost get table kycteosiobot kycteosiobot kyc --show-payer --lower 2143454254 --upper 2143454254
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
      "payer": "kycteosiobot"
    }
  ],
  "more": false,
  "next_key": "",
  "next_key_bytes": ""
}
``` 


### Read KYC data from Blockchain
```console
$ cleost get table kycteosiobot kycteosiobot kyc --show-payer --lower 2143454254 --upper 2143454254
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
      "payer": "kycteosiobot"
    }
  ],
  "more": false,
  "next_key": "",
  "next_key_bytes": ""
}
```

### Delete KYC data