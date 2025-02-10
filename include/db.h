#ifndef DB_H
#define DB_H

#define MEMBER_DELIMITER_SPACE " "
#define MEMBER_DELIMITER_COLON ":"
#define MEMBER_DELIMITER_COMMA ","
#define DATABASE_NEW_LINE "\n"

#define MAX_QUERY_BUFFER_SIZE 1024
#define MAX_VALUE_BUFFER_SIZE 1024

#define QUERY_SELECT "select"
#define QUERY_EXIT "exit"
#define QUERY_QUIT "quit"

extern char *database;
extern long int current_position;

void create_db(char *db);
void create_table(char *table, char *members);

void add_values_table(char *table, char *members);

void db_print_table(char *table);

#endif
