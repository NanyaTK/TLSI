CFLAGS = -std=gnu99

OBJS = src/OS/os.o \
       src/util.o \
       src/L2/network.o \

TRASH = src/OS/windows.o \

TESTS = ./test/os_osinit_test.exe \
        ./test/util_log_test.exe \
        ./test/util_getlocaltime_test.exe \
        ./test/os_flockfile_test.exe \
        ./test/network_ifnetalloc_test.exe \

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
	rm -rf $(OBJS) $(TRASH) $(TESTS) $(TESTS:.exe=.o)

cleanwin:
	del $(OBJS) $(TRASH) $(TESTS) $(TESTS:.exe=.o)