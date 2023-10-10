#include <VExercise3.h>
#include <cstdint>
#include <catch2/catch_test_macros.hpp>
#include <random>

typedef uint8_t u8;
typedef uint16_t u16;

u8 mystery1(int a, int b, int c)
{
  switch(a)
  {
  case 0: return 0b00000000 | ((b & 7) << 3) | (c & 7);
  case 1: return 0b01000000 | ((c & 7) << 3) | (b & 7);
  case 2: return b;
  case 3: return c;
  }
}

struct Mystery2
{
  u8 i = 0;
  u16 out;

  u16 step(u8 a_in, u8 b_in)
  {
    i %= 5;
    switch(i++)
    {
    case 0: out = (a_in << 8) | (out & 0xFF);
    case 1: out = ((out & 0xFF00)) | b_in;
    case 2: out = (out << 8) | (out >> 8);
    case 3: out = ((out >> 12) & 0xF) << 12 | ((out >> 8) & 0xF) << 8 | ((out >> 4) & 0xF) << 4 | (out & 0xF); 
    case 4: out = (std::popcount(out) & 1);
    }
    return 0;
  }

  u16 reset(u8 a, u8 b)
  {
    out = (b << 8) | a;
    i = 0;
    return out;
  }
};

struct Exercise3Sim {
  Mystery2 state;

  u16 step(u8 a, u8 b, u16 c)
  {
    u8 a_in { mystery1(a & 0x3, b & 0xFF, c & 0xFF) };
    u8 b_in { mystery1(a >> 2, b >> 8, c >> 8) };
    return state.reset(a_in, b_in);
  }

  u16 reset(u8 a, u8 b, u16 c)
  {
    u8 a_in { mystery1(a & 0x3, b & 0xFF, c & 0xFF) };
    u8 b_in { mystery1(a >> 2, b >> 8, c >> 8) };
    return state.reset(a_in, b_in);
  }
};

void step(VExercise3& model)
{
  model.clk = 1;
  model.eval();
  model.clk = 0;
  model.eval();
}

TEST_CASE("Random Test") 
{
  VExercise3 model;
  Exercise3Sim sim;

  std::random_device rd; // obtain a random number from hardware
  std::mt19937 gen(rd()); // seed the generator
  std::uniform_int_distribution<> distr(0, 65535); // define the range

  // generate three random numbers, a, b ,c

  model.a = distr(gen) % 4;
  model.b = distr(gen) % 65535;
  model.c = distr(gen) % 256;
  model.out = 0;
  model.reset = 1;
  step(model);

  REQUIRE(model.out == sim.reset(model.a, model.b, model.c));

  model.reset = 0;
  
  for (int i = 0; i < 1000; ++i)
  {
    model.a = distr(gen) % 4;
    model.b = distr(gen) % 65535;
    model.c = distr(gen) % 65535;
    step(model);
    REQUIRE(model.out == sim.step(model.a, model.b, model.c));
  }
}
