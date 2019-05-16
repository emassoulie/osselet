#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include <string.h>
#include <stdio.h>

#include <filesystem.h>

#define MEM_SIZE 1024


struct emplacement {
	int debut;
	int fin;
	int libre;
	char nom[10];
};

char files[MEM_SIZE];

struct emplacement sommaire[MEM_SIZE];

void ofs_init()
{
    sommaire[0].debut = 0;
    sommaire[0].fin = MEM_SIZE;
    sommaire[0].libre = 1;
    strcpy(sommaire[0].nom, "");

    sommaire[1].debut = MEM_SIZE;
    sommaire[1].fin = MEM_SIZE;
    sommaire[1].libre = 0;
    strcpy(sommaire[1].nom, "");
}

int ofs_touch() {
	return(ofs_create("test","tch"));
}


int ofs_create(char *file, char *nom) {
	char *lettre = file;
	int size = 0;
	while (*lettre != '\0') {
		lettre ++;
		size ++;
	}
	int rk = 0;

	/*recherche du premier emplacement libre assez grand*/
	while (!(sommaire[rk].libre == 1 && sommaire[rk].fin - sommaire[rk].debut < size) && rk < MEM_SIZE)
		rk ++;
	if (rk < MEM_SIZE) {
		/*on rentre le nouveau fichier dans le sommaire*/
		sommaire[rk].libre = 0;
		sommaire[rk].fin = sommaire[rk].debut + size - 1;
        strcpy(sommaire[rk].nom, nom);

		/*on décale les suivants*/
		int rk1 = rk + 1;
		struct emplacement t1;
		struct emplacement t2;
		t1.debut = sommaire[rk].debut + size;
		t1.fin = sommaire[rk].fin;
		t1.libre = 1;
		strcpy(t1.nom,"");
		do {
			t2 = sommaire[rk1];
			sommaire[rk1] = t1;
			t1 = t2;
			rk1++;
		} while (t2.debut < MEM_SIZE);
		sommaire[rk1] = t2;
		/*on écrit le fichier à proprement parler*/
		char *curseur = file + sommaire[rk].debut;
		int i = 0;
		for (i = 0; i < size ; i++) {
			files[i+sommaire[rk].debut] = *curseur;
			curseur++;
		}
	}
	return rk;
}

int ofs_lookup(char *n) {
	int i = 0;
	int res;
	while (sommaire[i].nom != n && sommaire[i].debut != MEM_SIZE) i++;
	if (sommaire[i].debut != MEM_SIZE) {
		res = -1;
	}
	else {
		res = i;
	}
	return res;
}


void ofs_remove(char *n) {
	int rk = ofs_lookup(n);
    sommaire[rk].libre = 1;
}

int ofs_append(char *mot2, char *n) {
	int rk = ofs_lookup(n);
    char *mot1 = ofs_cat(rk);
    char *name = sommaire[rk].nom;
    ofs_remove(rk);
    return ofs_create(strcat(mot1, mot2), name);
}

char* ofs_cat(char *n) {
	int rk = ofs_lookup(n);
    struct emplacement empl = sommaire[rk];
    int size = empl.fin - empl.debut;
    char fich[size];
    int i;
    for (i = 0; i < size; i++)
        fich[i] = files[i + sommaire[rk].debut];
    return fich;
}

void ofs_ls() {
    int i = 0;
    while (sommaire[i].debut < MEM_SIZE) {
		printf("%d",i);
        if (sommaire[i].libre != 0)
            printf("\n%d - %s",i,sommaire[i].nom);
        i++;
    }
	printf("\n");
}