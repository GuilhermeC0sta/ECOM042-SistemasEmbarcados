#ifndef COMMAND_H
#define COMMAND_H

typedef struct {
    const char *name;
    void (*execute)(void);  
} command_t;

void command_execute(const command_t *cmd);

#endif 