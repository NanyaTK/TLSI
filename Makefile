BASE = src/OS

OBJS = $(BASE)/os.o \

TESTS = ./test/os_osinit_test.exe \

CFLAGS := $(CFLAGS) -g -W -Wall 

ifeq ($(shell uname),Linux)
  # Linux
  OBJS := $(OBJS) $(BASE)/linux.o 
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