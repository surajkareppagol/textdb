#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>

#define DATABASE_BASE "db"

void util_create_dir(char *dir, bool base);
char *util_trim(char *string);
void util_create_label(char *string);

#endif
