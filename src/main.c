/*******************************************************************
 * @file main.c
 *
 * @brief Main file.
 * @author João Matheus Nascimento Dias (jmnd@ic.ufal.br)
 * @version 0.1
 * @date 26/08/2026
 *******************************************************************/

#include "commands.h"
#include <zephyr/kernel.h>

int main(void)
{
	/* TODO (Atividade-02): criar command.{h, c} e commands.{h, c}
	 * (Command Pattern), montar a tabela de comandos e despachar.
	 */

	dispatch_command("ping");
	dispatch_command("led_on");

	dispatch_command("abrir_porta");

	return 0;
}
