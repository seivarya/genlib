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
	 -Iinclude -Isrc/structures

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

SLIST_TEST = tests/sltest.c
DLIST_TEST = tests/dltest.c
CLIST_TEST = tests/cltest.c
STACK_TEST = tests/stktest.c
QUEUE_TEST = tests/qtest.c

# ======================
#  Build rules
# ======================

MKDIR = mkdir -p
OUT_DIR = run_tests

all: crtdir addfiles

crtdir: $(OUT_DIR)

$(OUT_DIR):
	$(MKDIR) $(OUT_DIR)

addfiles: $(OUT_DIR)/sltest $(OUT_DIR)/dltest $(OUT_DIR)/cltest $(OUT_DIR)/stktest $(OUT_DIR)/qtest

$(OUT_DIR)/sltest: $(SLIST_SRC) $(TD_SRC) $(SLIST_TEST)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OUT_DIR)/dltest: $(DLIST_SRC) $(TD_SRC) $(DLIST_TEST)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OUT_DIR)/cltest: $(CLIST_SRC) $(TD_SRC) $(CLIST_TEST)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OUT_DIR)/stktest: $(STACK_SRC) $(TD_SRC) $(STACK_TEST)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OUT_DIR)/qtest: $(QUEUE_SRC) $(TD_SRC) $(QUEUE_TEST)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# ======================
#  Cleanup
# ======================

clean:
	rm -rf $(OUT_DIR)
	find . -name '*.o' -delete

.PHONY: all clean
