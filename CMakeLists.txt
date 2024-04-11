cmake_minimum_required(VERSION 3.0.0)
project(xdp-lab VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# Kernel space ebpf programs
add_custom_target(samples ALL
                  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/build/first-kern.o
                  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/build/mappe.o
                  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/build/newmappe.o)

add_custom_command( OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/build/first-kern.o
                   DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/kernel/first-kern.c
                   COMMAND clang -g -target bpf -Wall -O2  -c ${CMAKE_CURRENT_SOURCE_DIR}/kernel/first-kern.c -o ${CMAKE_CURRENT_SOURCE_DIR}/build/first-kern.o)

                   add_custom_command( OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/build/mappe.o
                   DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/kernel/mappe.c
                   COMMAND clang -g -target bpf -Wall -O2 -c ${CMAKE_CURRENT_SOURCE_DIR}/kernel/mappe.c -o ${CMAKE_CURRENT_SOURCE_DIR}/build/mappe.o)

                   add_custom_command( OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/build/newmappe.o
                   DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/kernel/newmappe.c
                   COMMAND clang -g -target bpf -Wall -O2 -c ${CMAKE_CURRENT_SOURCE_DIR}/kernel/newmappe.c -o ${CMAKE_CURRENT_SOURCE_DIR}/build/newmappe.o)

# User space C++ apps
add_executable(dummy user/dummy.cpp)
target_link_libraries(dummy xdp)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
