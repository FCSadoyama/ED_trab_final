#ifndef FILE_H_INCLUDED
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#define FILE_H_INCLUDED

Filme* movie_split(char* str);
TAB* readCatalog(char path[80], int t);
void writeCatalog(FILE* file, TAB* arv);

#endif // FILE_H_INCLUDED
