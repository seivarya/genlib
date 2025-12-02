singly_node := src/structures/list/singly/singly_node/singly_node.c
doubly_node := src/structures/list/doubly/doubly_node/doubly_node.c
circular_node := src/structures/list/circular/circular_node/circular_node.c
stack_node := src/structures/stack/stack_node/stack_node.c

singly_list := src/structures/list/singly/singly_list.c
doubly_list := src/structures/list/doubly/doubly_list.c
circular_list := src/structures/list/circular/circular_list.c
stack := src/structures/stack/stack.c

singly_test := tests/singly_test.c
doubly_test := tests/doubly_test.c
circular_test := tests/circular_test.c
stack_test := tests/stack_test.c

singly_test_obj_files = singly_node.o singly_list.o singly_test.o 
doubly_test_obj_files = doubly_node.o doubly_list.o doubly_test.o
circular_test_obj_files = circular_node.o circular_list.o circular_test.o
stack_test_obj_files = stack_node.o stack.o stack_test.o

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
         -fstack-protector-all \
         -D_FORTIFY_SOURCE=2 \
         -fPIC \
         -std=c11 -msse -mfpmath=sse

ldflags = -fsanitize=undefined,address,leak \
	-lm \
	-Wl,-z,relro \
	-Wl,-z,now

all: singly_test doubly_test circular_test stack_test

#==========================================================#

singly_test: $(singly_test_obj_files)
	gcc $(singly_test_obj_files) -o singly_test $(ldflags)

doubly_test: $(doubly_test_obj_files)
	gcc $(doubly_test_obj_files) -o doubly_test $(ldflags)

circular_test: $(circular_test_obj_files)
	gcc $(circular_test_obj_files) -o circular_test $(ldflags)

stack_test: $(stack_test_obj_files)
	gcc $(stack_test_obj_files) -o stack_test $(ldflags)

#==========================================================#

singly_node.o: $(singly_node)
	gcc $(flags) -c $(singly_node) -o singly_node.o

doubly_node.o: $(doubly_node)
	gcc $(flags) -c $(doubly_node) -o doubly_node.o

circular_node.o: $(circular_node)
	gcc $(flags) -c $(circular_node) -o circular_node.o

stack_node.o: $(stack_node)
	gcc $(flags) -c $(stack_node) -o stack_node.o

#==========================================================#

singly_list.o: $(singly_list)
	gcc $(flags) -c $(singly_list) -o singly_list.o

doubly_list.o: $(doubly_list)
	gcc $(flags) -c $(doubly_list) -o doubly_list.o

circular_list.o: $(circular_list)
	gcc $(flags) -c $(circular_list) -o circular_list.o

stack.o: $(stack)
	gcc $(flags) -c $(stack) -o stack.o
#==========================================================#

singly_test.o: $(singly_test)
	gcc $(flags) -c $(singly_test) -o singly_test.o

doubly_test.o: $(doubly_test)
	gcc $(flags) -c $(doubly_test) -o doubly_test.o

circular_test.o: $(circular_test)
	gcc $(flags) -c $(circular_test) -o circular_test.o

stack_test.o: $(stack_test)
	gcc $(flags) -c $(stack_test) -o stack_test.o
#==========================================================#

clean: 
	rm -f $(singly_test_obj_files) singly_test
	rm -f $(doubly_test_obj_files) doubly_test 
	rm -f $(circular_test_obj_files) circular_test
	rm -f $(stack_test_obj_files) stack_test
