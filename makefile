CC = gcc

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

# -----------------------
# Sources
SLIST = src/list/slist/slist.c src/list/slist/snode/snode.c tests/slist_test.c
DLIST = src/list/dlist/dlist.c src/list/dlist/dnode/dnode.c tests/dlist_test.c
CLIST = src/list/clist/clist.c src/list/clist/cnode/cnode.c tests/clist_test.c
STACK = src/stack/stack.c src/stack/stknode/stknode.c tests/stack_test.c
QUEUE = src/queue/queue.c src/queue/qnode/qnode.c tests/queue_test.c

# Convert .c → .o
SLIST_OBJS = $(SLIST:.c=.o)
DLIST_OBJS = $(DLIST:.c=.o)
CLIST_OBJS = $(CLIST:.c=.o)
STACK_OBJS = $(STACK:.c=.o)
QUEUE_OBJS = $(QUEUE:.c=.o)

.PHONY: all clean

all: slist_test dlist_test clist_test stack_test queue_test

# -----------------------
# Link rules
slist_test:  $(SLIST_OBJS) ; $(CC) $^ -o $@ $(LDFLAGS)
dlist_test:  $(DLIST_OBJS) ; $(CC) $^ -o $@ $(LDFLAGS)
# clist_test:  $(CLIST_OBJS) ; $(CC) $^ -o $@ $(LDFLAGS)
# stack_test:  $(STACK_OBJS) ; $(CC) $^ -o $@ $(LDFLAGS)
# queue_test:  $(QUEUE_OBJS) ; $(CC) $^ -o $@ $(LDFLAGS)

# -----------------------
# Generic compile rule
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(SLIST_OBJS) $(DLIST_OBJS) $(CLIST_OBJS) \
	      $(STACK_OBJS) $(QUEUE_OBJS) \
	      slist_test dlist_test clist_test stack_test queue_test
