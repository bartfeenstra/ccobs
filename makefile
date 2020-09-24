CFLAGS  = -std=c99
CFLAGS += -g
# CFLAGS += -Wall
# CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror

VFLAGS  = --quiet
VFLAGS += --tool=memcheck
VFLAGS += --leak-check=full
VFLAGS += --error-exitcode=1

test: tests.out
	@./tests.out

memcheck: tests.out
	@valgrind $(VFLAGS) ./tests.out
	@echo "Memory check passed"

clean:
	rm -rf *.o *.out *.out.dSYM

tests.out: tests/test_ccobs.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) tests/test_ccobs.c -lcriterion -o tests.out
