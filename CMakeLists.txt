cmake_minimum_required(VERSION 3.13)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake) # cp $PICO_SDK_PATH/external/pico_sdk_import.cmake .

project(pico-cli C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(pico-cli
        pico-cli.c
        )

# Pull in our pico_stdlib which aggregates commonly used features
target_link_libraries(pico-cli pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(pico-cli 1)
pico_enable_stdio_uart(pico-cli 0)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(pico-cli)