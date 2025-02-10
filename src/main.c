#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <db.h>

int main(int argc, char **argv) {
  printf("TextDB - Learn Database Management Systems\n");

  create_db("movies");

  printf("Database is %s.\n", database);

  /**********************************************************/

  char *table_values = "int year, int cost, int earnings, string director";

  char *table_values_buffer = calloc(1, strlen(table_values) + 1);

  strcpy(table_values_buffer, table_values);

  create_table("movies", table_values_buffer);

  /**********************************************************/

  char *row_1 = "2022, 20000, 400000, ABC";

  char *row_1_buffer = calloc(1, strlen(row_1) + 1);

  strcpy(row_1_buffer, row_1);

  add_values_table("movies", row_1_buffer);

  /**********************************************************/

  char *row_2 = "2024, 40000, 800000, DEF";

  char *row_2_buffer = calloc(1, strlen(row_2) + 1);

  strcpy(row_2_buffer, row_2);

  add_values_table("movies", row_2_buffer);

  while (true) {
    fprintf(stdout, "\n> ");
    char query[MAX_QUERY_BUFFER_SIZE] = {0};

    if (fgets(query, MAX_QUERY_BUFFER_SIZE, stdin) == NULL) {
      return -1;
    };

    /* Parse all the queries */

    if (strstr(query, QUERY_SELECT)) {
      db_print_table("movies");
    } else if (strstr(query, QUERY_EXIT)) {
      break;
    } else if (strstr(query, QUERY_QUIT)) {
      break;
    } else {
      fprintf(stdout, "Error: query command not found.\n");
    }
  }

  return 0;
}
