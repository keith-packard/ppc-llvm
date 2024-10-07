CC=/local/llvm/bin/clang
CFLAGS= \
	--target=powerpc64le-linux-gnu \
	-O2 \
	-fstack-protector-strong \
	-mstack-protector-guard=tls \
	-mstack-protector-guard-reg=r13 \
	-mstack-protector-guard-offset=3192

foo.s: foo.c Makefile
	$(CC) $(CFLAGS) -S foo.c
