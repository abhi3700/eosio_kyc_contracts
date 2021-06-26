#include "kycteosiobot.hpp"

// --------------------------------------------------------------------------------------------------------------------
void kycteosiobot::addmodkyc( uint64_t plat_user_id,
								const string& fullname, 
								const checksum256& address_hash, 
								const checksum256& document_id_front_hash,
								const checksum256& document_id_back_hash,
								const checksum256& selfie_hash )
{
	require_auth(get_self());

/*	kyc_index kyc_table(get_self(), get_self().value);
	auto kyc_usr_it = kyc_table.find(plat_user_id);

	if( kyc_usr_it == kyc_table.end() ) {			// emplace
		kyc_table.emplace(get_self(), [&](auto &row){
			row.plat_user_id = plat_user_id;
			row.fullname = fullname;
			row.address_hash = address_hash;
			row.document_id_front_hash = document_id_front_hash;
			row.document_id_back_hash = document_id_back_hash;
			row.selfie_hash = selfie_hash;
		});
	}
	else {			// modify
		kyc_table.modify(kyc_usr_it, get_self(), [&](auto &row){
			if (!fullname.empty()) row.fullname = fullname;
			if (!address_hash.empty()) row.address_hash = address_hash;
			if (!document_id_front_hash.empty()) row.document_id_front_hash = document_id_front_hash;
			if (!document_id_back_hash.empty()) row.document_id_back_hash = document_id_back_hash;
			if (selfie_hash != "") row.selfie_hash = selfie_hash;
		});
	}
*/}

// --------------------------------------------------------------------------------------------------------------------
void kycteosiobot::delkyc( uint64_t plat_user_id ) {
	require_auth(get_self());

/*	kyc_index kyc_table(get_self(), get_self().value);
	auto kyc_usr_it = kyc_table.find(plat_user_id);

	check(kyc_usr_it != kyc_table.end(), "No KYC exists for this user with platform id: '" + std::to_string(plat_user_id) + "\'");

	kyc_table.erase(kyc_usr_it);
*/}

// --------------------------------------------------------------------------------------------------------------------
void kycteosiobot::setkycviews( uint64_t plat_user_id, bool view_status ) {
	require_auth(get_self());

/*	check( (view_status == true || view_status == false), "View status must be set to either true or false." );

	kyc_index kyc_table(get_self(), get_self().value);
	auto kyc_usr_it = kyc_table.find(plat_user_id);

	check(kyc_usr_it != kyc_table.end(), "No KYC exists for this user with platform id: '" + std::to_string(plat_user_id) + "\'");

	kyc_table.modify(kyc_usr_it, get_self(), [&](auto &row){
		row.view_status = view_status;
	});
*/}
