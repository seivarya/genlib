# ======================
#  Compiler & Flags
# ======================

CC = gcc

CFLAGS = -g3 -ggdb -O1 \
	 -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wconversion \
	 -Wnull-dereference -Wdouble-promotion -Wimplicit-fallthrough \
	 -Wcast-align -Wstrict-aliasing=3 -Wstrict-prototypes -Wmissing-prototypes \
	 -Wmissing-declarations -Wunused-parameter -Wfloat-equal \
	 -Winit-self -Wuninitialized -Wswitch-enum -Wredundant-decls \
	 -Wpointer-arith -Wvla \
	 -Werror \
	 -fsanitize=address,undefined,leak,pointer-compare,pointer-subtract,alignment \
	 -fsanitize=bounds,float-cast-overflow,float-divide-by-zero \
	 -fsanitize=signed-integer-overflow \
	 -fno-omit-frame-pointer -fno-optimize-sibling-calls \
	 -fstack-protector-all -D_FORTIFY_SOURCE=2 -fPIC \
	 -std=c11 -msse -mfpmath=sse \
	 -Iinclude -Isrc

LDFLAGS = -fsanitize=undefined,address,leak -lm

# ======================
#  Source files
# ======================

TD_SRC = src/td/td.c

SLIST_SRC = \
	    src/structures/list/slist/slist.c \
	    src/structures/list/slist/snode/snode.c

DLIST_SRC = \
	    src/structures/list/dlist/dlist.c \
	    src/structures/list/dlist/dnode/dnode.c

CLIST_SRC = \
	    src/structures/list/clist/clist.c \
	    src/structures/list/clist/cnode/cnode.c

STACK_SRC = \
	    src/structures/stack/stack.c \
	    src/structures/stack/stknode/stknode.c

QUEUE_SRC = \
	    src/structures/queue/queue.c \
	    src/structures/queue/qnode/qnode.c

# ======================
#  Tests
# ======================

SLIST_TEST = tests/slist_test.c
DLIST_TEST = tests/dlist_test.c
CLIST_TEST = tests/clist_test.c
STACK_TEST = tests/stack_test.c
QUEUE_TEST = tests/queue_test.c

# ======================
#  Build rules
# ======================

all: slist_test dlist_test clist_test stack_test queue_test

slist_test: $(SLIST_SRC) $(TD_SRC) $(SLIST_TEST)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

dlist_test: $(DLIST_SRC) $(TD_SRC) $(DLIST_TEST)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clist_test: $(CLIST_SRC) $(TD_SRC) $(CLIST_TEST)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

stack_test: $(STACK_SRC) $(TD_SRC) $(STACK_TEST)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

queue_test: $(QUEUE_SRC) $(TD_SRC) $(QUEUE_TEST)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# ======================
#  Cleanup
# ======================

clean:
	rm -f slist_test dlist_test clist_test stack_test queue_test
	find . -name '*.o' -delete

.PHONY: all clean
