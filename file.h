#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

Filme* movie_split(char* str);
TAB* readCatalog(char path[80], int t);
void writeCatalog(char path[80], TAB* arv);

#endif // FILE_H_INCLUDED
