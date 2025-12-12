# Makefile - fixed and simplified
CC = gcc

# Compilation flags (kept your long list under FLAGS)
FLAGS = -g3 -ggdb -O1 \
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
	-std=c11 -msse -mfpmath=sse

LDFLAGS = -fsanitize=undefined,address,leak \
	  -lm -Wl,-z,relro -Wl,-z,now

# Sources
SLIST_SRC = src/list/slist/slist.c
SNODE_SRC = src/list/slist/snode.c
SLIST_TEST_SRC = tests/slist_test.c

DLIST_SRC = src/list/dlist/dlist.c
DNODE_SRC = src/list/dlist/dnode.c
DLIST_TEST_SRC = tests/dlist_test.c

CLIST_SRC = src/list/clist/clist.c
CNODE_SRC = src/list/clist/cnode.c
CLIST_TEST_SRC = tests/clist_test.c

STACK_SRC = src/stack/stack.c
STNODE_SRC = src/stack/stnode.c
STACK_TEST_SRC = tests/stack_test.c

QUEUE_SRC = src/queue/queue.c
QNODE_SRC = src/queue/qnode.c
QUEUE_TEST_SRC = tests/queue_test.c

# Object files per test
SLIST_OBJS = snode.o slist.o slist_test.o
DLIST_OBJS = dnode.o dlist.o dlist_test.o
CLIST_OBJS = cnode.o clist.o clist_test.o
STACK_OBJS = stack.o stnode.o stack_test.o
QUEUE_OBJS = queue.o qnode.o queue_test.o

.PHONY: all clean

all: slist_test dlist_test clist_test stack_test queue_test

# -----------------------
# slist
slist_test: $(SLIST_OBJS)
	$(CC) $(SLIST_OBJS) -o $@ $(LDFLAGS)

snode.o: $(SNODE_SRC)
	$(CC) $(FLAGS) -c $< -o $@

slist.o: $(SLIST_SRC)
	$(CC) $(FLAGS) -c $< -o $@

slist_test.o: $(SLIST_TEST_SRC)
	$(CC) $(FLAGS) -c $< -o $@

# -----------------------
# dlist
dlist_test: $(DLIST_OBJS)
	$(CC) $(DLIST_OBJS) -o $@ $(LDFLAGS)

dnode.o: $(DNODE_SRC)
	$(CC) $(FLAGS) -c $< -o $@

dlist.o: $(DLIST_SRC)
	$(CC) $(FLAGS) -c $< -o $@

dlist_test.o: $(DLIST_TEST_SRC)
	$(CC) $(FLAGS) -c $< -o $@

# -----------------------
# clist
clist_test: $(CLIST_OBJS)
	$(CC) $(CLIST_OBJS) -o $@ $(LDFLAGS)

cnode.o: $(CNODE_SRC)
	$(CC) $(FLAGS) -c $< -o $@

clist.o: $(CLIST_SRC)
	$(CC) $(FLAGS) -c $< -o $@

clist_test.o: $(CLIST_TEST_SRC)
	$(CC) $(FLAGS) -c $< -o $@

# -----------------------
# stack
stack_test: $(STACK_OBJS)
	$(CC) $(STACK_OBJS) -o $@ $(LDFLAGS)

stnode.o: $(STNODE_SRC)
	$(CC) $(FLAGS) -c $< -o $@

stack.o: $(STACK_SRC)
	$(CC) $(FLAGS) -c $< -o $@

stack_test.o: $(STACK_TEST_SRC)
	$(CC) $(FLAGS) -c $< -o $@

# -----------------------
# queue
queue_test: $(QUEUE_OBJS)
	$(CC) $(QUEUE_OBJS) -o $@ $(LDFLAGS)

qnode.o: $(QNODE_SRC)
	$(CC) $(FLAGS) -c $< -o $@

queue.o: $(QUEUE_SRC)
	$(CC) $(FLAGS) -c $< -o $@

queue_test.o: $(QUEUE_TEST_SRC)
	$(CC) $(FLAGS) -c $< -o $@

# -----------------------
clean:
	rm -f *.o slist_test dlist_test clist_test stack_test queue_test
