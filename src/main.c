#include <stdio.h>

#include <db.h>

int main(int argc, char **argv) {
  printf("TextDB - Learn Database Management Systems\n");

  create_db("movies");

  printf("Database is %s.\n", database);

  create_table("movies", "year, cost, earnings, director");

  return 0;
}
