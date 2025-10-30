.POSIX:
.SUFFIXES:

# Use the system's default C compiler
# was gnu89 reallyyyy necessary ....
# surely gradescope machines have a compiler which can do post Y2K C ....

CC		= cc
CFLAGS	= -Wall -Wpointer-arith -Wstrict-prototypes -std=gnu11 -fPIC

# Pathname of the pkg-config compatible utility
# (not using this for this assignment at all)
#PC		= pkg-config

# Instructions to create an LSP db -- default is clangd with compile_flags.txt
# e.g. To use bear you can set DB="bear -- make" which will create compile_commands.json
DB		= echo $(LDFLAGS) $(CFLAGS) | tr ' ' '\n' > compile_flags.txt

# Project Files
BIN=test-mergesort
OBJ=test-mergesort.o mergesort.o 
SRC=$(OBJ:%.o=%.c)
DEP=$(OBJ:%.o=%.d)

all: $(BIN)

# Build binary from objects
$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

# Implicit suffix rules to create .o and .d files from sources
.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) $(INC) -c $<

.SUFFIXES: .c .d
.c.d:
	$(CC) -MM $< -o $@

# Unit tests -- lets anticipate all the unit tests
tests: mergesort.o merge.o buildargs.o my_mergesort.o parallel_mergesort.o

	$(CC) $(CFLAGS) -o merge.test 				merge.o mergesort.o
	$(CC) $(CFLAGS) -o buildargs.test 			buildargs.o mergesort.o
	$(CC) $(CFLAGS) -o my_mergesort.test 		my_mergesort.o mergesort.o
	$(CC) $(CFLAGS) -o parallel_mergesort.test	parallel_mergesort.o mergesort.o

# Explicit test source recipes
merge.o: tests/merge.c
	$(CC) $(CFLAGS) -c $< -o merge.o
buildargs.o: tests/buildargs.c
	$(CC) $(CFLAGS) -c $< -o buildargs.o
my_mergesort.o: tests/my_mergesort.c
	$(CC) $(CFLAGS) -c $< -o my_mergesort.o
parallel_mergesort.o: tests/parallel_mergesort.c
	$(CC) $(CFLAGS) -c $< -o parallel_mergesort.o

# Generate LSP database on each clean
db:
	$(DB)
	
clean: db
	rm -fr $(BIN)
	rm -fr $(OBJ)
	rm -fr $(DEP)
	
# For FreeBSD make use -include
-include $(DEP)
