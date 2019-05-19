# Rapport de projet OS 2019 - Rock'n Roll

Maximilien Dupont de Dinechin et Eloi Massoulié

## 1. Objectifs

L'objectif était d'implémenter un OS minimal, appelé `OSselet`, sous forme d'un microkernel et d'un shell. Nous n'avons pas atteint tous nos objectifs, loin de là, mais voici un desscriptif de ce que l'on souhaitait réaliser.

Pour le kernel :
- démarrer sur une architecture virtuelle `x86` dans `qemu`,
- être indépendant des fonctions C non standard en les réecrivant dans `lib/`, de sorte à pouvoir cross-compiler,
- être capable d'afficher des choses sur l'écran en sortie VGA (notamment en réecrivant `printf`),
- être capable de gérer une entrée clavier standard avec une gestion minimaliste des interruptions,
- fournir un système de fichier minimal : un seul dossier, création et suppression de fichiers, écriture, concarénation...

Pour le shell :
- Quelques commandes simples (echo, ls, pwd, touch, ...),
- Exécution de scripts shell basiques (pas fait)

## 2. Réferences

En plus du cours, deux sources principales : OSDev et Kernel 101 (et 201) sur https://arjunsreedharan.org.

## 3. Compilation

La compilation du projet suppose d'avoir un cross-compiler GCC, dont l'installation est documentée ici : https://wiki.osdev.org/GCC_Cross-Compiler .

Le fichier Makefile décrit la compilation automatisée du projet avec `make`, il n'y a plus qu'à lancer `qemu` avec l'option `-kernel OSselet.bin`.

## 4. Structure du projet

Le dossier `kernel/` contient le minimum vital : le code assembleur permettant de charger la fonction kernel_main, le code c correspondant, et le linker.

Le dossier `lib/` contient une réimplémentation de quelques fonctions des librairies standard C ; en plus de la gestion écran et clavier (`tty/`)

Le dossier `usr/` contient les applications utilisateurs : une calculatrice (inechevée), et le shell (dans `usr/shell/`).

Le dossier `mem/` contient le système de fichiers (et un embryon de malloc).

### 4.1 `kernel/`

#### 4.1.1 Démarrage, chargement du kernel

#### 4.1.2 Affichage

#### 4.1.3 Entrée clavier

### 4.2 `lib/`

Description des implémentations.

### 4.3 `usr/shell/`

Description su shell

### 4.4 `mem/`

Description du fs d'Éloi.

### 5. Conclusions

