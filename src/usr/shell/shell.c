#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

#include <string.h>

#include <stdio.h>

#include "shell.h"

enum commands {
    cd,
    pwd,
    mkdir,
    touch,
    rm,
    rmdir,
    cat,
    echo
};

void shell_repl()
{
    char input[256];
    do {
        // fgets(input, 50, stdin); 
        shell_eval(input);
    } while (!(strlen(input) == 5 && memcmp(input, "exit", 4) == 0));
}

// Syntaxe très stricte :
//   - le premier mot est la commande
//   - tous les modificateurs sont groupés immédiatement après la commande
//   - tous lesmots qui suivent sont des arguments
//   - fin de la lecture quand on rencontre '\0', '|', ou '>'.

void shell_eval(char *input)
{
    return read_command(input);
}

void read_command(char *line)
{
    char command[32];
    char *ptr = command;
    while (*line != '|' && *line != '>' && *line != ' ' && *line != '\0') {
        *ptr++ = *line++;
    }
    *ptr = '\0';
    printf("Commande : %s\n", command);
    while (*line == '|' || *line == '>' || *line == ' ')
        line++;
    return read_arguments(command, line);
}

void read_arguments(const char *command, char *line)
{
    int arg_no = 0;
    char arg[32]; 
    char *ptr = arg;
    while (*line != '\0') {
        ptr = arg;
        while (*line != '|' && *line != '>' && *line != ' ' && *line != '\0') {
            *ptr++ = *line++;
        }
        *ptr = '\0';
        printf("Argument no %d : %s\n", arg_no, arg);
        while (*line == '|' || *line == '>' || *line == ' ')
            line++;
        arg_no ++;
    }
}
