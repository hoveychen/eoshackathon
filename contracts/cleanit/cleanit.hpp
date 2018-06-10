/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#pragma once

#include <eosiolib/asset.hpp>
#include <eosiolib/eosio.hpp>

#include <algorithm>
#include <string>

namespace eosiosystem {
class system_contract;
}

using namespace eosio;
namespace cleanit {

using std::string;
static const account_name code_account = N(cleanit);

struct report {
  string description;
  string type;
  string address;
  string requirement;
  string photo_url;
};

struct plan {
  // roles
  uint16_t num_coordinator;
  uint16_t num_carrirer;
  uint16_t num_cleaner;
  uint16_t num_cameraman;

  // tools
  uint16_t num_pickaxe;
  uint16_t num_shovel;

  // int in percentage.
  uint16_t dist_coordinator;
  uint16_t dist_carrirer;
  uint16_t dist_cleaner;
  uint16_t dist_cameraman;

  vector<string> shcedule;
  string terms_n_conditions;
  string potential_risks;

  asset reward;
};

struct result {
  vector<account_name> present_coordinators;
  vector<account_name> present_carriers;
  vector<account_name> present_cleaners;
  vector<account_name> present_cameramans;
  uint16_t num_avail_pickaxe;
  uint16_t num_avail_shovel;

  vector<string> schedule;
};

//@abi table fundtable
struct fund {
  account_name donator;
  asset vault;
};
typedef eosio::multi_index<N(fundtable), fund> funds;

//@abi table profiletable
struct profile {
  profile(){};
  profile(account_name user_id) : user_id(user_id) {}
  account_name user_id;
  asset token;
  auto primary_key() const { return user_id; }
  EOSLIB_SERIALIZE(profile, (user_id)(token))
};
typedef eosio::multi_index<N(profiletable), profile> profiles;

//@abi table tasktable
struct task {
  task(){};
  uint64_t task_id;

  // States:
  // NEW_REPORT
  // AWAITING_PARTICIPANT
  // CONFIRMED
  // EXECUTED
  // RECYCLYING
  string state;

  account_name reporter;
  account_name planner;
  vector<account_name> coordinators;
  vector<account_name> carriers;
  vector<account_name> cleaners;
  vector<account_name> cameramans;
  report report;
  plan plan;
  result result;

  vector<string> activities;

  auto primary_key() const { return task_id; }

  EOSLIB_SERIALIZE(task,
                   (task_id)(state)(reporter)(planner)(coordinators)(carriers)(
                       cleaners)(cameramans)(report)(plan)(result)(activities))
};
typedef eosio::multi_index<N(tasktable), task> tasks;

//@abi action
struct Report {
  uint64_t task_id;
  account_name reporter;
  report report;
  EOSLIB_SERIALIZE(Report, (task_id)(reporter)(report))
};

//@abi action
struct Plan {
  uint64_t task_id;
  account_name planner;
  plan plan;
  EOSLIB_SERIALIZE(Plan, (task_id)(planner)(plan))
};

//@abi action
struct Join {
  uint64_t task_id;
  account_name participant;
  string apply_role;
  EOSLIB_SERIALIZE(Join, (task_id)(participant)(apply_role))
};

//@abi action
struct Record {
  uint64_t task_id;
  account_name recorder;
  string photo_url;
  EOSLIB_SERIALIZE(Record, (task_id)(recorder)(photo_url))
};

//@abi action
struct Execute {
  uint64_t task_id;
  account_name coordinator;
  result result;
  EOSLIB_SERIALIZE(Execute, (task_id)(coordinator)(result))
};

struct Donate {
  account_name donator;
  asset value;
  EOSLIB_SERIALIZE(Donate, (donator)(value))
};

} // namespace cleanit