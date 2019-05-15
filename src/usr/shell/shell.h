#ifndef _SHELL_H
#define _SHELL_H

void shell_repl();
void shell_eval(char *input);
void read_line(char *line);
void run(const char *command, char **args);

#endif
