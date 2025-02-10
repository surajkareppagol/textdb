#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <db.h>
#include <util.h>

/* Extern variable to hold database name */
char *database = NULL;
long int current_position = 0;

/**********************************************************/
/*                    CREATE_DB                           */
/**********************************************************/

void create_db(char *db) {
  util_create_dir(DATABASE_BASE, true);

  util_create_dir(db, false);

  database = calloc(1, sizeof(db));
  strncpy(database, db, strlen(db));
}

/**********************************************************/
/*                    CREATE_TABLE                        */
/**********************************************************/

void create_table(char *table, char *members) {
  char path[1024];
  /* DATABASE_STORAGE / DATABASE / TABLE */
  sprintf(path, "%s/%s/%s.txt", DATABASE_BASE, database, table);

  FILE *open_table = fopen(path, "w");

  if (open_table == NULL) {
    return;
  }

  char *token = strtok(members, MEMBER_DELIMITER_COMMA);
  fseek(open_table, current_position, SEEK_SET);

  while (true) {
    if (token == NULL) {
      break;
    }

    token = util_trim(token);
    util_create_label(token);
    
    fprintf(open_table, "%s ", token);
    current_position = ftell(open_table);

    token = strtok(NULL, MEMBER_DELIMITER_COMMA);
  }

  fprintf(open_table, "%s", DATABASE_NEW_LINE);

  fclose(open_table);
}

/**********************************************************/
/*                    ADD_VALUES_TABLE                    */
/**********************************************************/

void add_values_table(char *table, char *members) {
  char path[1024];
  /* DATABASE_STORAGE / DATABASE / TABLE */
  sprintf(path, "%s/%s/%s.txt", DATABASE_BASE, database, table);

  FILE *open_table = fopen(path, "a");

  if (open_table == NULL) {
    return;
  }

  char *token = strtok(members, MEMBER_DELIMITER_COMMA);
  fseek(open_table, current_position, SEEK_SET);

  while (true) {
    if (token == NULL) {
      break;
    }

    token = util_trim(token);
    util_create_label(token);
    
    fprintf(open_table, "%s ", token);
    current_position = ftell(open_table);

    token = strtok(NULL, MEMBER_DELIMITER_COMMA);
  }

  fprintf(open_table, "%s", DATABASE_NEW_LINE);

  fclose(open_table);
}

/**********************************************************/
/*                    DB_PRINT_TABLE                         */
/**********************************************************/

void db_print_table(char *table)
{
  char path[1024];
  /* DATABASE_STORAGE / DATABASE / TABLE */
  sprintf(path, "%s/%s/%s.txt", DATABASE_BASE, database, table);

  FILE *open_table = fopen(path, "r");

  if (open_table == NULL) {
    return;
  }

  char table_buffer[MAX_VALUE_BUFFER_SIZE] = {0};

  while(fgets(table_buffer, MAX_VALUE_BUFFER_SIZE, open_table) != NULL) {
    fprintf(stdout, "%s", table_buffer);
  }

  fclose(open_table);
}