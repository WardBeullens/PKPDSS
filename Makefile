CC=gcc
CFLAGS=-I XKCP/bin/generic64/
LFLAGS=-L XKCP/bin/generic64/ -lkeccak -lcrypto

IMPLEMENTATION_SOURCE = sign.c test.c zkproof.c BLAKE2/sse/blake2b.c BLAKE2/sse/blake2xb.c
IMPLEMENTATION_HEADERS= sign.h keccaklib zkproof.h parameters.h BLAKE2/sse/blake2.h

test: $(IMPLEMENTATION_SOURCE) $(IMPLEMENTATION_HEADERS)
	gcc -o test $(IMPLEMENTATION_SOURCE) $(CFLAGS) $(LFLAGS) -std=c11 -O3 -g -march=native -DSUSHSY

keccaklib: 
	(cd XKCP; make generic64/libkeccak.a)

.PHONY: clean
clean:
	rm -f PQCgenKAT_sign test debug test_offline intermediateValues.txt *.req *.rsp >/dev/null