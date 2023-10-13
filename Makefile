OBJS = src/OS/os.o \
       # src/util.o \

TESTS = ./test/os_osinit_test.exe \
        ./test/util_log_test.exe \
        ./test/util_getlocaltime_test.exe \

CFLAGS := $(CFLAGS) -g -W -Wall 

ifeq ($(shell uname),Linux)
  # Linux
  OBJS := $(OBJS) src/OS/linux.o
else
  # Windows
  OBJS := $(OBJS) src/OS/windows.o
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
	rm -rf $(OBJS) $(TESTS) $(TESTS:.exe=.o)

cleanwin:
	del $(OBJS) $(TESTS) $(TESTS:.exe=.o)