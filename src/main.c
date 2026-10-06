/*******************************************************************
 * @file main.c
 *
 * @brief Main file.
 * @author João Matheus Nascimento Dias (jmnd@ic.ufal.br)
 * @author José Félix de Oliveira Neto (jfon@ic.ufal.br)
 * @version 0.1
 * @date 26/08/2026
 *******************************************************************/

#include "board_io.h"

#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/gpio/gpio_emul.h>
#include <zephyr/kernel.h>

int main(void)
{
	static const int sequence[] = {0, 1, 0, 1};
	const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(DT_ALIAS(sw0), gpios);
	int ret;

	ret = io_init();
	if (ret < 0) {
		return ret;
	}

	for (size_t i = 0; i < ARRAY_SIZE(sequence); i++) {
		int level;

		ret = gpio_emul_input_set(button.port, button.pin, sequence[i]);
		if (ret < 0) {
			return ret;
		}

		level = button_read();
		if (level < 0) {
			return level;
		}

		ret = led_set(level != 0);
		if (ret < 0) {
			return ret;
		}

		printk("Button: %d -> LED: %d\n", level, level);
	}

	return 0;
}
