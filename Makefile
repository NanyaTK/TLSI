BASE = src/OS \

OBJS = src/util.o \


TESTS = ./test/util_log_test.exe \

CFLAGS := $(CFLAGS) -g -W -Wall 

ifeq ($(shell uname),Linux)
  # Linux
  # OBJS := $(OBJS) $(BASE)/linux.o 
endif

.SUFFIXES:
.SUFFIXES: .c .o

.PHONY: all clean

all: $(TESTS)

$(TESTS): %.exe : %.o $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(APPS) $(APPS:.exe=.o) $(OBJS) $(DRIVERS) $(TESTS) $(TESTS:.exe=.o)