#include <catch2/catch_test_macros.hpp>
#include <VExercise2.h>
#include <cstdint>

typedef uint8_t u8;
typedef uint16_t u16;

u16 lsfr(u16 state)
{
  return (state >> 1) | (((state >> 0) ^ (state >> 2) ^ (state >> 3) ^ (state >> 5)) & 1) << 15;
}

TEST_CASE("Exercise 2") {
  VExercise2 model;
  int initial = 0;

  for (int test = 0; test < 1000; ++test)
  {
    initial = rand() % 65536;
    for (int i = 0; i < 1000; ++i)
    {
      model.clk = 0;
      model.eval();
      model.clk = 1;
      model.eval();

      REQUIRE(model.out == lsfr(initial));
      initial = lsfr(initial);
    }
  }
}
