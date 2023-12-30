cmake_minimum_required(VERSION 3.13)

project(main)

set(CMAKE_C_STANDARD 99)


add_library(os STATIC src/OS/os.c)
target_include_directories(os PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
)
add_library(util STATIC src/util.c)
target_include_directories(util PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
)
add_library(network STATIC src/L2/network.c)
target_include_directories(network PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
)
add_library(dummy STATIC src/L2/interfaces/dummy.c)
target_include_directories(dummy PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
)
add_library(loopback STATIC src/L2/interfaces/loopback.c)
target_include_directories(loopback PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
)
add_library(memory STATIC src/memory.c)
target_include_directories(memory PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
)
if(UNIX)
  add_library(linux STATIC src/OS/linux.c)
  target_include_directories(linux PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
)
else()
  add_library(windows STATIC src/OS/windows.c)
  target_include_directories(windows PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
)
endif()

set(library os util dummy loopback network memory)

add_executable(0200_os_osinit_test.exe ./test/0200_os_osinit_test.c)
add_executable(0101_util_log_test.exe ./test/0101_util_log_test.c)
add_executable(0100_util_getlocaltime_test.exe ./test/0100_util_getlocaltime_test.c)
add_executable(0201_os_flockfile_test.exe ./test/0201_os_flockfile_test.c)
add_executable(0500_network_ifnetalloc_test.exe ./test/0500_network_ifnetalloc_test.c)

add_executable(0300_dummy_dummyinit_test.exe ./test/0300_dummy_dummyinit_test.c)
add_executable(0400_loopback_loopbackinit_test.exe ./test/0400_loopback_loopbackinit_test.c)
add_executable(0402_loopback_loopbackoutput_test.exe ./test/0402_loopback_loopbackoutput_test.c)
add_executable(0600_memory_queueinittest_test.exe ./test/0600_memory_queueinittest_test.c)
add_executable(0601_memory_QueueEnque_test.exe ./test/0601_memory_QueueEnque_test.c)

add_executable(9900_union.exe ./test/9900_union.c)

target_link_libraries(dummy util)
target_link_libraries(loopback util)
target_link_libraries(network util)
target_link_libraries(memory util)
target_link_libraries(util os)

if(UNIX)
  target_link_libraries(os linux)
  target_link_libraries(0200_os_osinit_test.exe ${library} network linux)
  target_link_libraries(0101_util_log_test.exe ${library} network linux)
  target_link_libraries(0100_util_getlocaltime_test.exe ${library} network linux)
  target_link_libraries(0201_os_flockfile_test.exe ${library} network linux)
  target_link_libraries(0500_network_ifnetalloc_test.exe ${library} network linux)
  target_link_libraries(0300_dummy_dummyinit_test.exe ${library} network dummy linux)
  target_link_libraries(0400_loopback_loopbackinit_test.exe ${library} linux)
  target_link_libraries(0402_loopback_loopbackoutput_test.exe ${library} linux)
  target_link_libraries(0600_memory_queueinittest_test.exe ${library} linux)
  target_link_libraries(0601_memory_QueueEnque_test.exe ${library} linux)
  target_link_libraries(9900_union.exe ${library} linux)
  
else()
  target_link_libraries(os windows)
  target_link_libraries(0200_os_osinit_test.exe ${library} windows)
  target_link_libraries(0101_util_log_test.exe ${library} windows)
  target_link_libraries(0100_util_getlocaltime_test.exe ${library} windows)
  target_link_libraries(0201_os_flockfile_test.exe ${library} windows)
  target_link_libraries(0500_network_ifnetalloc_test.exe ${library} windows)
  target_link_libraries(0300_dummy_dummyinit_test.exe ${library} windows)
  target_link_libraries(0400_loopback_loopbackinit_test.exe ${library} windows)
  target_link_libraries(0402_loopback_loopbackoutput_test.exe ${library} windows)
  target_link_libraries(0600_memory_queueinittest_test.exe ${library} windows)
  target_link_libraries(0601_memory_QueueEnque_test.exe ${library} windows)

endif()