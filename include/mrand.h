#define WORD 16      // The word size in bits
#define N 624        // Degree of recurrence
#define MWORD 397    // Offset
#define R 15         // Separation point
#define A 0x9908B0DF // Rational coefficient
#define B 0x9D2C5680 // Tempering bitmask
#define C 0xEFC60000 // Tempering bitmask
#define S 7          // Tempering bit shift
#define T 15         // Tempering bit shift
#define U 11         // Extra
#define D 0xFFFFFFFF // Extra
#define L 18         // Extra
#define F 1812433253

long unsigned int gen_state[N]; // Holds all the states of the generator
long unsigned int gen_index = N + 1;
const long unsigned int lower_mask = (1 << R) - 1; // One's complement of R
const long unsigned int upper_mask = (~lower_mask) & ((1 << WORD) - 1); // Lower WORD bits of ~lower_mask

void seed_gen(int);
long unsigned int mrand();
void twist();
