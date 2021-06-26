# `kyceosiobot`

## Actions
* `addmodkyc`
* `delkyc`
* `setkycviews`

## Tables
* `kyc`

## Compile
```console
$ eosio-cpp kycteosiobot.cpp -o kycteosiobot.wasm
Warning, action <addmodkyc> does not have a ricardian contract
Warning, action <delkyc> does not have a ricardian contract
Warning, action <setkycviews> does not have a ricardian contract
/mnt/f/Coding/github_repos/eosio_kyc_contracts/kycteosiobot/kycteosiobot.cpp:4:20: warning: abigen warning (Action <addmodkyc> does not have a ricardian contract)
void kycteosiobot::addmodkyc( uint64_t plat_user_id,
                   ^
Warning, action <addmodkyc> does not have a ricardian contract
/mnt/f/Coding/github_repos/eosio_kyc_contracts/kycteosiobot/kycteosiobot.cpp:38:20: warning: abigen warning (Action <delkyc> does not have a ricardian contract)
void kycteosiobot::delkyc( uint64_t plat_user_id ) {
                   ^
Warning, action <delkyc> does not have a ricardian contract
/mnt/f/Coding/github_repos/eosio_kyc_contracts/kycteosiobot/kycteosiobot.cpp:50:20: warning: abigen warning (Action <setkycviews> does not have a ricardian contract)
void kycteosiobot::setkycviews( uint64_t plat_user_id, bool view_status ) {
                   ^
Warning, action <setkycviews> does not have a ricardian contract
3 warnings generated.
```

## Deploy
* deploy contract
```console
$ cleost set contract kycteosiobot ./
Reading WASM from /mnt/f/Coding/github_repos/eosio_kyc_contracts/kycteosiobot/kycteosiobot.wasm...
Publishing contract...
executed transaction: 7b670a6d0035ae6dad6f098447e54b99a9d2be88186bb042237a33cfc3243dac  15344 bytes  835 us
#         eosio <= eosio::setcode               {"account":"kycteosiobot","vmtype":0,"vmversion":0,"code":"0061736d0100000001d4012260000060037f7f7f0...
#         eosio <= eosio::setabi                {"account":"kycteosiobot","abi":"0e656f73696f3a3a6162692f312e320003096164646d6f646b796300060c706c617...
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
$ cleost push action kycteosiobot addmodkyc '["2143454254", "Ramesh Sisodia", "dc64a6ea0998adc2378869e11782b4332c5d0d2a2676cb73164ec1df0fa186f8", "cc2370f40df7faab22d433e93178e5a13f475c0556cc03dd1d431cfcdb220ae3", "a36fa66069053120eaf3ee4639a4663f31e6f50528d9c4b0f7b3c4b18a6dd79b", "b52d373fdbd5b321399401c2d9d6ca83c2267bb42d403a057a858e1ed67228d7"]' -p kycteosiobot@active
executed transaction: e44fb1439e5c49df2cb1babe13939b50c66976034aae5b902bc793ad00a90a8d  368 bytes  232 us
#  kycteosiobot <= kycteosiobot::addmodkyc      {"plat_user_id":2143454254,"fullname":"Ramesh Sisodia","address_hash":"490, first floor, \nSector 98...
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
        "address_hash": "dc64a6ea0998adc2378869e11782b4332c5d0d2a2676cb73164ec1df0fa186f8",
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
executed transaction: ffb67da1da2976df5f151fbdf01d123b860b622bcff2511a357d3b6a396a2157  304 bytes  200 us
#  kycteosiobot <= kycteosiobot::addmodkyc      {"plat_user_id":2143454254,"fullname":"","address_hash":"","document_id_front_hash":"cc2370f40df7faa...
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
        "address_hash": "dc64a6ea0998adc2378869e11782b4332c5d0d2a2676cb73164ec1df0fa186f8",
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
        "fullname": "Ramesh Sisodia",
        "address_hash": "dc64a6ea0998adc2378869e11782b4332c5d0d2a2676cb73164ec1df0fa186f8",
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
```console
$ cleost push action kycteosiobot delkyc '["2143454254"]' -p kycteosiobot@active
executed transaction: 0469c48842e848e9728e0705a41e948c369ac9e2dd97bc10e7f03755e2233e87  104 bytes  154 us
#  kycteosiobot <= kycteosiobot::delkyc         {"plat_user_id":2143454254}
warning: transaction executed locally, but may not be confirmed by the network yet         ]
```

- Read the table
```console
$ cleost get table kycteosiobot kycteosiobot kyc --show-payer --lower 2143454254 --upper 2143454254
{
  "rows": [],
  "more": false,
  "next_key": "",
  "next_key_bytes": ""
}
``` 

### Set KYC View Status
