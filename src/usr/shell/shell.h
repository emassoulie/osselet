#ifndef _SHELL_H
#define _SHELL_H

void shell_repl();

int shell_eval(char *input);
int read_line(char *line);
int run(const char *command, char **args);

int exit(char **args);
int pwd(char **args);
int touch(char **args);
int mkdir(char **args);
int cd(char **args);
int rm(char **args);
int rmdir(char **args);
int echo(char **args);
int cat(char **args);
int append(char **args);

#endif