/**
 * @file unittest_transport.c
 * @author los
 * @date 20-10-2020
 * @brief Zephyr transport protocol for PlatformIO test framework
 * 
 * */

#include "unittest_transport.h"
#include <zephyr.h>
#include <drivers/uart.h>

static struct device * console_uart;

void unittest_uart_begin() {
    console_uart = device_get_binding( "UART_3" );
    struct uart_config config = {
        115200U,
        UART_CFG_PARITY_NONE,
        UART_CFG_STOP_BITS_1,
        UART_CFG_DATA_BITS_8,
        UART_CFG_FLOW_CTRL_NONE
    };
    uart_configure( console_uart, &config );
}

void unittest_uart_putchar(char c) {
    uart_poll_out( console_uart, c );
}

void unittest_uart_flush() {
}

void unittest_uart_end() {
}
