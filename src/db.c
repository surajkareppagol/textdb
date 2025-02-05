#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <db.h>
#include <util.h>

/* Extern variable to hold database name */
char *database = NULL;

void create_db(char *db) {
  util_create_dir(DATABASE_BASE, true);

  util_create_dir(db, false);

  database = calloc(1, sizeof(db));
  strncpy(database, db, strlen(db));
}

void create_table(char *table, char *members) {
  char path[1024];
  sprintf(path, "%s/%s/%s", DATABASE_BASE, database, table);

  FILE *open_table = fopen(path, "w");

  if (open_table == NULL) {
    return;
  }

  fprintf(open_table, "%s", members);

  fclose(open_table);
}
