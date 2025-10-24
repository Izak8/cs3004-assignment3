.POSIX:
.SUFFIXES:

# Use the system's default C compiler
# was gnu89 reallyyyy necessary ....
# surely gradescope machines have a compiler which can do post Y2K C ....

CC		= cc
CFLAGS	= -Wall -Wpointer-arith -Wstrict-prototypes -std=c11 -fPIC

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

# Suffix rules to create .o and .d files from sources
.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) $(INC) -c $<

.SUFFIXES: .c .d
.c.d:
	$(CC) -MM $< -o $@

# Generate LSP database on each clean
db:
	$(DB)
	
clean: db
	rm -fr $(BIN)
	rm -fr $(OBJ)
	rm -fr $(DEP)
	
# For FreeBSD make use -include
-include $(DEP)
