#include <catch2/catch_test_macros.hpp>
#include <VExercise2.h>
#include <VExercise2.h>

TEST_CASE("Exercise 2") {
  VExercise2 model;

  for (int test = 0; test < 1000; ++test)
  {
    initial = rand() % 65536;
    for (int i = 0; i < 1000; ++i)
    {
      model.clk = 0;
      model.eval();
      model.clk = 1;
      model.eval();

      REQUIRE(model.out == lsfr(initial))
      initial = lsfr(initial);
    }
  }
}
