#include <VExercise1.h>
#include <cstdint>
#include <catch2/catch_test_macros.hpp>

bool verify_xor(int a, int b, int out);
bool verify_left_shift(int a, int b, int out);
bool verify_mod(int a, int b, int out);
bool verify_not_and(int a, int b, int out);

typedef uint8_t u8;
typedef uint16_t u16;

void test_op(u8 code, u8(op)(u8, u8)) { 
  VExercise1 model; 
  model.op = code;
  model.a = 0;
  model.b = 0;

  do {
    do {
      model.eval(); //evaluates out
      u8 result {op(model.a, model.b)};
      REQUIRE(result == model.out); 
    } while(++model.b); 
  } while(++model.a); 
}

TEST_CASE("Opcode 0, Xor") {
  test_op(0, [](u8 a, u8 b) -> u8 { return a ^ b; });
}

TEST_CASE("Opcode 1, Left Shift") {
  test_op(1, [](u8 a, u8 b) -> u8 { return a << b; });
}

TEST_CASE("Opcode 2, Modulo") {
  test_op(2, [](u8 a, u8 b) -> u8 { return a % b; });
}

TEST_CASE("Opcode 3, Not And") {
  test_op(3, [](u8 a, u8 b) -> u8 { return ~(a & b); });
}
