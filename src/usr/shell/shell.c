#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>

#include <string.h>

#include <stdio.h>

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
//  ls

// Syntaxe très stricte :
//   - le premier mot est la commande
//   - tous les modificateurs sont groupés immédiatement après la commande
//   - tous lesmots qui suivent sont des arguments
//   - fin de la lecture quand on rencontre '\0', '|', ou '>'.


void shell_repl()
{
    char input[256];
    do {
        // fgets(input, 50, stdin); 
        shell_eval(input);
    } while (!(strlen(input) == 5 && memcmp(input, "exit", 4) == 0));
}

void shell_eval(char *input)
{
    return read_line(input);
}

void read_line(char *line)
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

void run(const char *command, char **args)
{
    printf("Commande : %s\n", command);
    for (int i = 0; *args[i] != '\0'; i++)
        printf("Argument %d : %s\n", i, args[i]);    
}
