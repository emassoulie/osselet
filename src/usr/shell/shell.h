#ifndef _SHELL_H
#define _SHELL_H

void shell_repl();
void shell_eval(char *input);
void read_command(char *line);
void read_arguments(const char *command, char *line);

#endif
