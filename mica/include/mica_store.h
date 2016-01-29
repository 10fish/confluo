#ifndef MICA_STORE_H_
#define MICA_STORE_H_

#define MEHCACHED_NO_EVICTION

#include "table.h"
#include "alloc_pool.h"
#include "alloc_malloc.h"
#include "alloc_dynamic.h"

#include <string>
#include <set>

namespace mica {

class MicaStore {
 public:
  static const size_t kStoreSize = 1024 * 1024 * 1024;

  MicaStore(const uint32_t value_length, const uint32_t key_length = 8);

  int Append(const int64_t key, const std::string& value);
  void Get(std::string& value, const int64_t key);

  void Search(std::set<int64_t>& _return, const std::string& query) {
  }

  int64_t Dump(const std::string& path) {
    return 0;
  }

  int64_t Load(const std::string& path) {
    return 0;
  }

  size_t GetNumKeys() {
    return num_keys_;
  }

  size_t GetCurrentSize() {
    return current_size_;
  }

 private:
  struct mehcached_table *table_;
  size_t key_size_;
  size_t value_size_;

  size_t num_keys_;
  size_t current_size_;

  // Pre-allocated buffer
  uint8_t* value_buf_;
};

}

#endif /* MICA_STORE_H_ */