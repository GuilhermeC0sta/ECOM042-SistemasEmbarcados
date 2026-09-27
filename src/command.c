#include "command.h"
#include <stddef.h> 

void command_execute(const command_t *cmd) {
    if (cmd != NULL && cmd->execute != NULL) {
        cmd->execute();
    }
}