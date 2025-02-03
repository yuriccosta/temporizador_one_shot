#include <stdio.h>
#include "pico/stdlib.h"

#define LED_PIN_BLUE 11
#define LED_PIN_RED 12
#define LED_PIN_GREEN 13
#define BUTTON_PIN 5


volatile uint8_t step = 0; // Qual passo do processo de desligar os leds estamos
volatile uint8_t last_led_state = 0; // Estado do último led (RED)
volatile uint32_t last_time = 0; // Último tempo que o botão foi pressionado

int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    if (step == 0) {
        gpio_put(LED_PIN_BLUE, 0);
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    } else if (step == 1) {
        gpio_put(LED_PIN_RED, 0);
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    } else if (step == 2) {
        gpio_put(LED_PIN_GREEN, 0);
        step = 0;
        last_led_state = 0;
        return 0;
    }

    step++;

    return 0;
}



int main()
{
    // Inicializa os leds
    gpio_init(LED_PIN_BLUE);
    gpio_set_dir(LED_PIN_BLUE, GPIO_OUT);
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);

    // Inicializa o botão
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    // Inicializa a interrupção


    stdio_init_all();
    

    while (true) {
        if(gpio_get(BUTTON_PIN) == 0 && last_led_state == 0) {
            // Debounce
            uint32_t current_time = to_ms_since_boot(get_absolute_time());
            if (current_time - last_time > 200){
                last_led_state = 1;
                gpio_put(LED_PIN_BLUE, 1);
                gpio_put(LED_PIN_GREEN, 1);
                gpio_put(LED_PIN_RED, 1);
                add_alarm_in_ms(3000, turn_off_callback, NULL, false);
                last_time = current_time;
            }
        } 
        sleep_ms(10);
    }
}
