#ifndef SIGN_H
#define SIGN_H 

#include <stdlib.h>

void *aligned_alloc( size_t alignment, size_t size );

#include "parameters.h"
#include "zkproof.h"

#define SIG_COMMITMENT(sig) (sig)
#define SIG_RESPONSE1(sig) (SIG_COMMITMENT(sig) + HASH_BYTES)
#define SIG_RESPONSE2(sig) (SIG_RESPONSE1(sig) + RESPONSE1_BYTES)
#define SIG_BYTES (SIG_RESPONSE2(0) + RESPONSE2_BYTES) 

void sign(const unsigned char *sk,  const unsigned char *pk,const unsigned char *m, uint64_t mlen, unsigned char *sig, uint64_t *sig_len);
int verify(const unsigned char *pk, const unsigned char *m, uint64_t mlen, const unsigned char *sig); 

#endif