# Projet OS (osselet)

https://arjunsreedharan.org/post/82710718100/kernels-101-lets-write-a-kernel

## Fonctionnalités

### Noyau

- [ ] Exister
- [ ] Démarrer / s'éteindre / redémarrer
- [ ] Gestion du clavier
- [ ] Gestion de l'écran
- [ ] Communication avec le shell
- [ ] Système de fichiers (à inventer éventuellement)
- [ ] Donner et reprendre les commandes à un processus
- [ ] Lire et écrire dans la RAM
- [ ] Parallélisme ?
- [ ] Compilateur quelconque

### Shell

- [ ] Petit shell
- [ ] poweroff, reboot
- [ ] ls, cd, pwd
- [ ] cp, mv, rm, touch, mkdir
- [ ] boucles, variables, fonctions, communication avec les LEDs

### Système de fichiers

à spécifier

### Programmes

- [ ] Lanceur de scripts shell



## Agenda

- Idée plus précise de comment tout ça démarre
- Faire marcher en local l'émulateur avec un OS de rien du tout
- Réfléchir à un système de fichiers ?


## Notes de Max

- QEMU c'est pas mal
- Petit makefile bien pratique
- COmmande pour QEMU : `qemu-system-x86_64 -kernel ./kernel`
