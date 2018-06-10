#include <cleanit.hpp>

namespace cleanit {
struct impl {
  void apply(uint64_t receiver, uint64_t code, uint64_t action) {
    if (code == code_account) {
      if (action == N(report)) {
        impl::on(eosio::unpack_action_data<cleanit::Report>());
      } else if (action == N(plan)) {
        impl::on(eosio::unpack_action_data<cleanit::Plan>());
      } else if (action == N(join)) {
        impl::on(eosio::unpack_action_data<cleanit::Join>());
      } else if (action == N(record)) {
        impl::on(eosio::unpack_action_data<cleanit::Record>());
      } else if (action == N(execute)) {
        impl::on(eosio::unpack_action_data<cleanit::Execute>());
      } else if (action == N(donate)) {
        impl::on(eosio::unpack_action_data<cleanit::Donate>());
      }
    }
  }

  void on(const Report &req) {
    require_auth(req.reporter);
    tasks all_tasks(code_account, N(tasks));
    auto itr = all_tasks.find(req.task_id);
    eosio_assert(itr == all_tasks.end(), "task exists");
    all_tasks.emplace(code_account, [&](auto &r) {
      r.task_id = req.task_id;
      r.report = req.report;
      r.reporter = req.reporter;
      r.state = "NEW_REPORT";
    });
  }

  void on(const Plan &req) {
    require_auth(req.planner);
    tasks all_tasks(code_account, N(tasks));
    auto itr = all_tasks.find(req.task_id);
    eosio_assert(itr != all_tasks.end(), "task not exists");
    all_tasks.modify(itr, code_account, [&](auto &r) {
      r.plan = req.plan;
      r.planner = req.planner;
      r.state = "AWAITING_PARTICIANT";
    });
  }

  void on(const Join &req) {
    require_auth(req.participant);
    tasks all_tasks(code_account, N(tasks));
    auto itr = all_tasks.find(req.task_id);
    eosio_assert(itr != all_tasks.end(), "task not exists");

    // TODO: fill in the participant by role.

    all_tasks.modify(itr, code_account,
                     [&](auto &r) { r.state = "CONFIRMED"; });
  }

  void on(const Record &req) {
    require_auth(req.recorder);
    tasks all_tasks(code_account, N(tasks));
    auto itr = all_tasks.find(req.task_id);
    eosio_assert(itr != all_tasks.end(), "task not exists");
    // TODO: append photos to task.
    all_tasks.modify(itr, code_account,
                     [&](auto &r) { r.activities.push_back(req.photo_url); });
  }

  void on(const Execute &req) {
    require_auth(req.coordinator);
    tasks all_tasks(code_account, N(tasks));
    auto itr = all_tasks.find(req.task_id);
    eosio_assert(itr != all_tasks.end(), "task not exists");
    checkout(*itr);
    all_tasks.modify(itr, code_account, [&](auto &r) {
      r.state = "EXECUTED";
      r.result = req.result;
    });
  }

  inline void checkout(task task) {
    // TODO: distribute tokens to differnt accounts by
    // portion distribution pre-defined in task.
  }

  void on(const Donate &req) {
    require_auth(req.donator);
    // TODO: adds the tokens to global token fund.
  }
};

} // namespace cleanit

extern "C" {

using namespace cleanit;
/// The apply method implements the dispatch of events to this contract
void apply(uint64_t receiver, uint64_t code, uint64_t action) {
  impl().apply(receiver, code, action);
}

void init() {
  // TODO: initialize the tokens in global fund.
}

} // extern "C"