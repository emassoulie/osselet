#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>

#include <string.h>

#include <stdio.h>
#include <tty.h>
#include <filesystem.h>

#include "shell.h"

// Commandes :
//  cd,
//  pwd,
//  mkdir,
//  touch,
//  rm,
//  rmdir,
//  cat,
//  echo,
//  ls,
//  append

// Syntaxe très stricte :
//   - le premier mot est la commande
//   - tous les modificateurs sont groupés immédiatement après la commande
//   - tous les mots qui suivent sont des arguments
//   - fin de la lecture quand on rencontre '\0', '|', ou '>'.


void shell_repl()
{
    int ret;
    char input[256];
    /*
    do {
        strcpy(kb_read(), input);
        ret = shell_eval(input);
        printf("Command exited with code %d", ret);
    } while (!(strlen(input) == 5 && memcmp(input, "exit", 4) == 0));
    */
    printf("\n> ");
    strcpy(kb_read(), input);
    printf("over");
    printf("Input : %s", input);
}

int shell_eval(char *input)
{
    printf("\n> %s\n", input);
    return read_line(input);
}

int read_line(char *line)
{
    // Identification de la commande
    char command[32];
    char *ptr = command;
    while (*line != '|' && *line != '>' && *line != ' ' && *line != '\0') {
        *ptr++ = *line++;
    }
    *ptr = '\0';
    while (*line == '|' || *line == '>' || *line == ' ')
        line++;

    // Identification des arguments : au plus 10 de 32 char.
    // Un malloc serait peut-être bien ici !
    char *args[10];
    char arg[320];
    // Nettoyage
    for (int i = 0; i < 320; i++)
        arg[i] = 0;
    for (int i = 0; i < 10; i++)
        args[i][0] = 0;

    char *debut = arg;
    char *fin = arg;

    // Gestion des guillemets pour autoriser les char spéciaux
    bool guillemets = false;

    int arg_no = 0;
    while (*line != '\0') {
        while (*line != '\0' && (guillemets || (!guillemets
                                                && *line != '|'
                                                && *line != '>'
                                                && *line != ' '))) {
            if (*line == '"') {
                guillemets = !guillemets;
                line++;
            } else {
                *fin++ = *line++;
            }
        }
        *fin = '\0';
        args[arg_no++] = debut;
        while (*line == '|' || *line == '>' || *line == ' ')
            line++;
        fin++;
        debut = fin;
    }
    args[arg_no] = "";
    return run(command, args);
}

int run(const char *command, char **args)
{
    if (strcmp(command, "exit") == 0) {
        return exit(args);
    }
    // else if (strcmp(command, "pwd") == 0) {
    //     return pwd(args);
    // }
    else if (strcmp(command, "touch") == 0) {
        return touch(args);
    }
    // else if (strcmp(command, "mkdir") == 0) {
    //     return mkdir(args);
    // }
    // else if (strcmp(command, "cd") == 0) {
    //     return cd(args);
    // }
    else if (strcmp(command, "rm") == 0) {
        return rm(args);
    }
    // else if (strcmp(command, "rmdir") == 0) {
    //     return rmdir(args);
    // }
    else if (strcmp(command, "echo") == 0) {
        return echo(args);
    }
    else if (strcmp(command, "cat") == 0) {
        return cat(args);
    }
    else if (strcmp(command, "ls") == 0) {
        return ls(args);
    }
    else if (strcmp(command, "append") == 0) {
        return append(args);
    } else {
        printf("Unsupported command : %s", command);
        return 0;
    }
}

int exit(char **args) {
    // Exit interrupt !
    // Kill PID etc
    return 0;
}

int touch(char **args) {
    for (int i = 0; args[i] != 0; i++) {
        // printf("  touch with argument %s", args[i]);
        ofs_touch(args[i]);
    }
    return 0;
}

int rm(char **args) {
    for (int i = 0; args[i] != 0; i++)
        ofs_remove(args[i]);
    return 0;
}

int ls(char **args) {
    ofs_ls();
    return 0;
}

int echo(char **args) {
    char *str = args[0];
    printf("%s", str);
    return 0;
}

int cat(char **args) {
    for (int i = 0; args[i] != 0; i++)
        printf("%s",ofs_cat(args[i]));
    return 0;
}

int append(char **args) {
    return 0;
}
