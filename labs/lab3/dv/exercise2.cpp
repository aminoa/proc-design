#include <VExercise2.h>
#include <cstdint>
#include <catch2/catch_test_macros.hpp>

typedef uint8_t u8;
typedef uint16_t u16;

u16 lsfr(u16 state)
{
  return (state >> 1) | (((state >> 0) ^ (state >> 2) ^ (state >> 3) ^ (state >> 5)) & 1) << 15;
}

void test(u16 initial)
{
  VExercise2 model;

  for (int i = 0; i < 1000; ++i)
  {
    model.clk = 0;
    model.eval();
    model.clk = 1;
    model.eval();

    if (model.out != lsfr(initial))
    {
      FAIL("Output is not correct");
      // return 1;
    }

    initial = lsfr(initial);
  }
}

int main()
{
  // generate random number from  0 to 65535
  for (int i = 0; i < 1000; ++i)
  {
    test(rand() % 65536);
  }

}