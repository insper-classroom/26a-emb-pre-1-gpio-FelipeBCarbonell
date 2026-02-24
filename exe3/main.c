#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_R = 4;
const int LED_PIN_G = 6;
const int BTN_PIN_G = 26;
const int BTN_PIN_R = 28;

int main() {
  stdio_init_all();

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);

  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);

  gpio_init(BTN_PIN_G);
  gpio_set_dir(BTN_PIN_G, GPIO_IN);
  gpio_pull_up(BTN_PIN_G);

  gpio_init(BTN_PIN_R);
  gpio_set_dir(BTN_PIN_R, GPIO_IN);
  gpio_pull_up(BTN_PIN_R);

  bool prev_btn_g = true;
  bool prev_btn_r = true;

  while (true) {
    bool current_btn_g = gpio_get(BTN_PIN_G);
    bool current_btn_r = gpio_get(BTN_PIN_R);

    if (prev_btn_g && !current_btn_g) {
      gpio_put(LED_PIN_G, !gpio_get(LED_PIN_G));
    }

    if (prev_btn_r && !current_btn_r) {
      gpio_put(LED_PIN_R, !gpio_get(LED_PIN_R));
    }

    prev_btn_g = current_btn_g;
    prev_btn_r = current_btn_r;
  }
}
