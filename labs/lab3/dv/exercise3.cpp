#include <VExercise3.h>
#include <cstdint>

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


int main() {
  VExercise3 model;


}
