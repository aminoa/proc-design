#include <VExercise4.h>
#include <cstdint>
#include <catch2/catch_test_macros.hpp>

typedef uint8_t u8;
typedef uint16_t u16;

u8 select(u8 sel, u8 alpha, u8 beta, u8 gamma)
{
  switch(sel)
  {
  case 0: return alpha;
  case 1: return beta;
  case 2: return gamma;
  case 3: return alpha & (beta | gamma);
  }
}

TEST_CASE("Test")
{
  VExercise4 model;
  model.alpha = 1;
  model.beta = 2;
  model.gamma = 3;
  model.cs = 1;

  for (model.sel = 0; model.sel < 4; ++model.sel)
  {
    model.eval();
    REQUIRE(model.out == select(model.sel, model.alpha, model.beta, model.gamma));
  }

  model.cs = 0;
  model.eval();

  for (model.sel = 0; model.sel < 4; ++model.sel)
  {
    model.eval();
    REQUIRE(model.out == 0);
  }
}