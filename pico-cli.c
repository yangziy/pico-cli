#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const uint32_t LED = PICO_DEFAULT_LED_PIN;;
const uint32_t GPIO2 = 2;
const uint32_t GPIO3 = 3;

void gpio_click(uint32_t pin, uint32_t delay) {
    gpio_put(pin, 1);
    sleep_ms(delay);
    gpio_put(pin, 0);
}

int main() {
    
    gpio_init(LED);
    gpio_init(GPIO2);
    gpio_init(GPIO3);

    gpio_set_dir(LED, GPIO_OUT);
    gpio_set_dir(GPIO2, GPIO_OUT);
    gpio_set_dir(GPIO3, GPIO_OUT);

    stdio_init_all();

    while (true) {
        char cmd[100];
        printf("Enter command: ");
        fflush(stdout);
        scanf("%s", cmd);
        printf("Command: %s\n", cmd);
        for(int i=0; i<=strlen(cmd); i++) {
            printf("cmd[%d]=%d ('%c')", i, cmd[i],cmd[i]);
        }
        printf("\n");
        if (0 == strcmp("set-led", cmd))
        {
            printf("Setting LED\n");
            gpio_put(LED, 1);
        }
        else if (0 == strcmp("clear-led", cmd))
        {
            printf("Clearing LED\n");
            gpio_put(LED, 0);
        }
        else if (0 == strcmp("set-gpio2", cmd))
        {
            printf("Setting GPIO2\n");
            gpio_put(GPIO2, 1);
        }
        else if (0 == strcmp("clear-gpio2", cmd))
        {
            printf("Clearing GPIO2\n");
            gpio_put(GPIO2, 0);
        }
        else if (0 == strcmp("poweron", cmd)) {
            gpio_click(GPIO2, 500);
        }
        else if (0 == strcmp("poweroff", cmd)) {
            gpio_click(GPIO2, 5000);
        } else if (0 == strcmp("reset", cmd)) {
            gpio_click(GPIO3, 500);
        }
        else
        {
            printf("Unknown command: %s\n", cmd);
        }
    }

    return 0;

}
