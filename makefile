
SLIST := src/list/slist/slist.c
SNODE := src/list/slist/snode.c
SLIST_TEST := tests/slist_test.c

SLIST_TEST_OBJ = snode.o slist.o slist_test.o

FLAGS = -g3 -ggdb -O1 \
	-Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wconversion \
	-Wnull-dereference -Wdouble-promotion -Wimplicit-fallthrough \
	-Wcast-align -Wstrict-aliasing=3 -Wstrict-prototypes -Wmissing-prototypes \
	-Wmissing-declarations -Wunused-parameter -Wfloat-equal \
	-Winit-self -Wuninitialized -Wswitch-enum -Wredundant-decls \
	-Wpointer-arith -Wvla \
	-Werror \
	-fsanitize=address \
	-fsanitize=undefined \
	-fsanitize=leak \
	-fsanitize=pointer-compare \
	-fsanitize=pointer-subtract \
	-fsanitize=alignment \
	-fsanitize=bounds \
	-fsanitize=float-cast-overflow \
	-fsanitize=float-divide-by-zero \
	-fsanitize=signed-integer-overflow \
	-fno-omit-frame-pointer \
	-fno-optimize-sibling-calls \
	-fstack-protector-all \
	-D_FORTIFY_SOURCE=2 \
	-fPIC \
	-std=c11 -msse -mfpmath=sse

LDFLAGS = -fsanitize=undefined,address,leak	\
	  -lm	\
	  -Wl,-z,relro	\
	  -Wl,-z,now

all: slist_test

slist_test: $(SLIST_TEST_OBJ)
	gcc $(SLIST_TEST_OBJ) -o slist_test $(LDFLAGS)

snode.o: $(SNODE)
	gcc $(FLAGS) -c $(SNODE) -o snode.o

slist.o: $(SLIST)
	gcc $(FLAGS) -c $(SLIST) -o slist.o

slist_test.o: $(SLIST_TEST)
	gcc $(FLAGS) -c $(SLIST_TEST) -o slist_test.o

#==========================================================#

clean: 
	rm -f $(SLIST_TEST_OBJ)

#==========================================================#
