#include "commands.h"
#include "command.h"
#include <zephyr/sys/printk.h>
#include <string.h>

static void action_ping(void) {
    printk("Executando: Pong!\n");
}

static void action_led_on(void) {
    printk("Executando: Ligando o LED...\n");
}

static const command_t command_table[] = {
    {"ping", action_ping},
    {"led_on", action_led_on}
};

#define NUM_COMMANDS (sizeof(command_table) / sizeof(command_table[0]))

void dispatch_command(const char *cmd_name) {
    for(int i = 0; i < NUM_COMMANDS; i++) {
        if (strcmp(command_table[i].name, cmd_name) == 0) {
            command_execute(&command_table[i]);
            return;
        }
    }
    printk("Erro: Comando '%s' nao encontrado.\n", cmd_name);
}