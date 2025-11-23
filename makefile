# it's basic implementation right now just for err obj check

singly_node := src/structures/list/singly/singly_node/singly_node.c
doubly_node := src/structures/list/doubly/doubly_node/doubly_node.c

singly_list := src/structures/list/singly/singly_list.c
doubly_list := src/structures/list/doubly/doubly_list.c

singly_test := tests/singly_test.c
doubly_test := tests/doubly_test.c

singly_test_obj_files = singly_node.o singly_list.o singly_test.o 
doubly_test_obj_files = doubly_node.o doubly_list.o doubly_test.o

flags = -g3 -ggdb -O1 \
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
         \
         -fstack-protector-all \
         -D_FORTIFY_SOURCE=2 \
         -fPIC \
         \
         -std=c11 -msse -mfpmath=sse

ldflags = -fsanitize=undefined,address,leak \
	-lm \
	-Wl,-z,relro \
	-Wl,-z,now

all: singly_test doubly_test

#==========================================================#
singly_test: $(singly_test_obj_files)
	gcc $(singly_test_obj_files) -o singly_test $(ldflags)

doubly_test: $(doubly_test_obj_files)
	gcc $(doubly_test_obj_files) -o doubly_test $(ldflags)
#==========================================================#
singly_node.o: $(singly_node)
	gcc $(flags) -c $(singly_node) -o singly_node.o

doubly_node.o: $(doubly_node)
	gcc $(flags) -c $(doubly_node) -o doubly_node.o
#==========================================================#
singly_list.o: $(singly_list)
	gcc $(flags) -c $(singly_list) -o singly_list.o

doubly_list.o: $(doubly_list)
	gcc $(flags) -c $(doubly_list) -o doubly_list.o
#==========================================================#
singly_test.o: $(singly_test)
	gcc $(flags) -c $(singly_test) -o singly_test.o

doubly_test.o: $(doubly_test)
	gcc $(flags) -c $(doubly_test) -o doubly_test.o
#==========================================================#

clean: 
	rm -f $(singly_test_obj_files) singly_test
	rm -f $(doubly_test_obj_files) doubly_test 
