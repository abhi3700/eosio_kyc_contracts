#pragma once
#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>
#include <eosio/system.hpp>
// #include <eosio/crypto.hpp>
#include <string>


using eosio::contract;
using eosio::print;
using eosio::name;
using eosio::multi_index;
using eosio::const_mem_fun;
using eosio::indexed_by;
using eosio::asset;
using eosio::check;
using eosio::permission_level;
using eosio::datastream;
// using eosio::current_time_point;
using eosio::action;
using eosio::same_payer;
using eosio::symbol;
using eosio::extended_symbol;
// using eosio::require_recipient;
// using eosio::checksum256;
// using eosio::action_wrapper;

using std::string;

CONTRACT kycweosiobot : public contract
{
private:

public:
	using contract::contract;

	kycweosiobot(name receiver, name code, datastream<const char*> ds) : 
				contract(receiver, code, ds)
				{}


	/**
	 * @brief - Add KYC (any or all fields)
	 * @details - Add KYC field only if the parsed is not empty. 
	 * 				This saves in creating individual ACTION like `modfullname`, `modaddress`, `moddocid`, `modselfie` 
	 * 
	 * @param plat_user_id - user id, fetched from the platform itself like Telegram, Whatsapp
	 * @param fullname - user's full name
	 * @param address - user's address
	 * @param document_id_front_hash - url's hash calculated before & then parsed
	 * @param document_id_back_hash - url's hash calculated before & then parsed
	 * @param selfie_hash - selfie url's hash calculated before & then parsed
	 */
	ACTION addmodkyc( uint64_t plat_user_id,
						const string& fullname, 
						const string& address, 
						const string& document_id_front_hash,
						const string& document_id_back_hash,
						const string& selfie_hash );

	/**
	 * @brief - Modify KYC (any or all fields)
	 * @details - Update KYC field only if the parsed is not empty. 
	 * 				This saves in creating individual ACTION like `modfullname`, `modaddress`, `moddocid`, `modselfie` 
	 * 
	 * @param plat_user_id - user id, fetched from the platform itself like Telegram, Whatsapp
	 * @param fullname - user's full name
	 * @param address - user's address
	 * @param document_id_front_hash - url's hash calculated before & then parsed
	 * @param document_id_back_hash - url's hash calculated before & then parsed
	 * @param selfie_hash - selfie url's hash calculated before & then parsed
	 */
/*	ACTION modkyc( uint64_t plat_user_id, 
					const string& fullname, 
					const string& address, 
					const string& document_id_front_hash,
					const string& document_id_back_hash,
					const string& selfie_hash );
*/

	/**
	 * @brief - Delete KYC by plat_user_id (automatically fetched from Telegram, Whatsapp)
	 * @details - Delete KYC by plat_user_id (automatically fetched from Telegram, Whatsapp)
	 * 
	 * @param plat_user_id - user id, fetched from the platform itself like Telegram, Whatsapp
	 */
	ACTION delkyc( uint64_t plat_user_id );

	// -----------------------------------------------------------------------------------------------------------------------
	TABLE kyc
	{
		uint64_t plat_user_id;		// row id.
		string fullname;			// full name
		string address;				// address
		string document_id_front_hash;		// document id front hash
		string document_id_back_hash;		// document id back hash
		string selfie_hash;					// selfie hash

		auto primary_key() const { return plat_user_id; }
	};

	using kyc_index = multi_index<"kyc"_n, kyc>;

};