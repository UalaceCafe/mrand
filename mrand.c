#include <stdio.h>
#include <stdlib.h>
#include "include/mrand.h"

void seed_gen(int _seed)
{
  gen_index = N;
  gen_state[0] = _seed;
  for(int i = 1; i < N; i++)
  {
    long int num = (F * (gen_state[i - 1] ^ (gen_state[i - 1] >> (WORD - 2))) + i) & ((1 << WORD) - 1);
    gen_state[i] = num;
  }
}

long unsigned int mrand()
{
  if(gen_index >= N)
  {
    if(gen_index > N)
    {
      seed_gen(rand() % 5489);
    }
    twist();
  }

  int y = gen_state[gen_index];
  y = y ^ ((y >> U) & D);
  y = y ^ ((y << S) & B);
  y = y ^ ((y << T) & C);
  y = y ^ (y >> L);

  gen_index += 1;
  return y & ((1 << WORD) - 1);
}

void twist()
{
  for(int i = 0; i < N; i++)
  {
    long int x = (gen_state[i] & upper_mask) + (gen_state[(i + 1) % N] & lower_mask);
    long int xA = x >> 1;
    if(x % 2)
    {
      xA ^= A;
    }
    gen_state[i] = gen_state[(i + MWORD) % N] ^ xA;
  }
  gen_index = 0;
}

int main(int argc, char ** argv) {

  // Prints 1000 numbers to test the algorithm
  for(int i = 0; i < 100; i++)
  {
    int x = mrand() % 1000;
    printf("%d\n", x);
  }

  return 0;
}
