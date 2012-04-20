/**
 *
 */

#include <boost/test/unit_test.hpp>

struct KoansConfig {
  KoansConfig() {
    boost::unit_test::unit_test_log.set_threshold_level( boost::unit_test::log_messages );
  }
  ~KoansConfig() {}
};

#define FILL_THE_NUMBER_IN 1
