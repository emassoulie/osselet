#ifndef _FILESYSTEM_H
#define _FILESYSTEM_H

void ofs_init();
int ofs_touch();
int ofs_create(char *file, char *nom);
void ofs_remove(char *n);
int ofs_append(char* mot2, char *n);
int lookup(char *n);
char* ofs_cat(char *n);
void ofs_ls();

#endif
