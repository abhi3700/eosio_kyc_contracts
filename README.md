# eosio_kyc_contracts
KYC contracts on EOSIO Blockchain

## About
* It is a Bot where user can upload KYC docs & they are added by validation via EOSIO Blockchain & then stored on Cloud database.
* During add, modify, delete KYC, user is verified by fetching the platform's user id like telegram_id, whatsapp_id.
> NOTE: As of now, the person (who could be someone else) using Telegram is assumed to be the owner of the Telegram account.
* Also, during KYC upload, there is no user permission asked bcoz all the contract's ACTION(s) are restricted by `get_self()` i.e. contract's permission.

## Action
### `addkyc`
### `modkyc`
### `delkyc`

## [DApp](https://github.com/abhi3700/kyc_bot)
* Here, the DApp is a Telegram Bot using which users can add, edit, delete KYC.