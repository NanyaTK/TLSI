cmake_minimum_required(VERSION 3.13)

project(main)

set(CMAKE_C_STANDARD 99)


add_library(os SHARED src/OS/os.c)
target_include_directories(os PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
)
add_library(util SHARED src/util.c)
target_include_directories(util PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
)
add_library(network SHARED src/L2/network.c)
target_include_directories(network PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
)
add_library(dummy SHARED src/L2/interfaces/dummy.c)
target_include_directories(dummy PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
)
add_library(loopback SHARED src/L2/interfaces/loopback.c)
target_include_directories(loopback PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
)
if(UNIX)
  add_library(linux SHARED src/OS/linux.c)
  target_include_directories(linux PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
)
else()
  add_library(windows SHARED src/OS/windows.c)
  target_include_directories(windows PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
)
endif()

set(library os util dummy loopback network)

add_executable(os_osinit_test.exe ./test/os_osinit_test.c)
add_executable(util_log_test.exe ./test/util_log_test.c)
add_executable(util_getlocaltime_test.exe ./test/util_getlocaltime_test.c)
add_executable(os_flockfile_test.exe ./test/os_flockfile_test.c)
add_executable(network_ifnetalloc_test.exe ./test/network_ifnetalloc_test.c)

add_executable(dummy_dummyinit_test.exe ./test/dummy_dummyinit_test.c)
add_executable(loopback_loopbackinit_test.exe ./test/loopback_loopbackinit_test.c)
add_executable(loopback_loopbackoutput_test.exe ./test/loopback_loopbackoutput_test.c)

if(UNIX)
  target_link_libraries(os_osinit_test.exe ${library} network linux)
  target_link_libraries(util_log_test.exe ${library} network linux)
  target_link_libraries(util_getlocaltime_test.exe ${library} network linux)
  target_link_libraries(os_flockfile_test.exe ${library} network linux)
  target_link_libraries(network_ifnetalloc_test.exe ${library} network linux)
  target_link_libraries(dummy_dummyinit_test.exe ${library} network dummy linux)
  target_link_libraries(loopback_loopbackinit_test.exe ${library} linux)
  target_link_libraries(loopback_loopbackoutput_test.exe ${library} linux)
else()
  target_link_libraries(os_osinit_test.exe ${library} windows)
  target_link_libraries(util_log_test.exe ${library} windows)
  target_link_libraries(util_getlocaltime_test.exe ${library} windows)
  target_link_libraries(os_flockfile_test.exe ${library} windows)
  target_link_libraries(network_ifnetalloc_test.exe ${library} windows)
  target_link_libraries(dummy_dummyinit_test.exe ${library} windows)
  target_link_libraries(loopback_loopbackinit_test.exe ${library} windows)
  target_link_libraries(loopback_loopbackoutput_test.exe ${library} windows)
endif()