#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/time.h"

#define LED_RED 11
#define LED_YELLOW 12
#define LED_GREEN 13

volatile int state = 0; // Estado do semáforo

bool repeating_timer_callback(struct repeating_timer *t) {
    // Alterna o estado do semáforo
    switch (state) {
        case 0: // Vermelho -> Amarelo
            gpio_put(LED_RED, 0);
            gpio_put(LED_YELLOW, 1);
            state = 1;
            break;
        case 1: // Amarelo -> Verde
            gpio_put(LED_YELLOW, 0);
            gpio_put(LED_GREEN, 1);
            state = 2;
            break;
        case 2: // Verde -> Vermelho
            gpio_put(LED_GREEN, 0);
            gpio_put(LED_RED, 1);
            state = 0;
            break;
    }
    return true; // Mantém o timer repetindo
}

int main() {
    stdio_init_all();

    // Configuração dos pinos dos LEDs
    gpio_init(LED_RED);
    gpio_init(LED_YELLOW);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    
    // Inicializa com o LED vermelho aceso
    gpio_put(LED_RED, 1);
    gpio_put(LED_YELLOW, 0);
    gpio_put(LED_GREEN, 0);

    struct repeating_timer timer;
    add_repeating_timer_ms(-3000, repeating_timer_callback, NULL, &timer);
    
    while (1) {
        printf("Semáforo ativo. Estado: %d\n", state);
        sleep_ms(1000); // Imprime mensagem a cada segundo
    }
}
