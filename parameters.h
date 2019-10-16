
//#define BLAKE
#define KECCAK

#define SL1
//#define SL3
//#define SL5

#ifdef SL1

	#define A_COLS 69
	#define A_ROWS 41
	#define FIELD_PRIME 251
	#define FIELD_BITS 8
	#define SEED_BYTES 16
	#define HASH_BYTES 32
	#define ITERATIONS 157

#endif

#ifdef SL3

	#define A_COLS 94
	#define A_ROWS 54
	#define FIELD_PRIME 509
	#define FIELD_BITS 9
	#define SEED_BYTES 24
	#define HASH_BYTES 48
	#define ITERATIONS 229

#endif

#ifdef SL5

	#define A_COLS 106
	#define A_ROWS 47
	#define FIELD_PRIME 4093
	#define FIELD_BITS 12
	#define SEED_BYTES 32
	#define HASH_BYTES 64
	#define ITERATIONS 289

#endif

#define LEAVES (1 << DEPTH)
#define LEAF_BYTES (A_COLS*sizeof(uint16_t))
#define TREE_BYTES ((2*LEAVES-1)*HASH_BYTES)
#define PATH_BYTES (DEPTH*HASH_BYTES)

#ifdef KECCAK
	#include "libkeccak.a.headers/SimpleFIPS202.h"
	#define HASH(data,len,out) SHAKE128(out, HASH_BYTES, data, len);
	#define EXPAND(data,len,out,outlen) SHAKE128(out, outlen, data, len);
#endif

#ifdef BLAKE
	#include "BLAKE2/sse/blake2.h"
	#define HASH(data,len,out) blake2xb(out, HASH_BYTES, data, len,0,0);
	#define EXPAND(data,len,out,outlen) blake2xb(out, outlen, data, len,0,0);
#endif

#define FIELD_MASK ((1<<FIELD_BITS) -1)
#define POS_MASK ((1<<SEED_DEPTH) -1)
