#include <stdio.h>
#include <sys/stat.h>

#include <util.h>

void util_create_dir(char *dir, bool base) {
  char path[1024];

  if (base == false) {
    sprintf(path, "%s/%s", DATABASE_BASE, dir);

    dir = path;
  }

  /* Check if directory is present if not create directory */
  struct stat st = {0};
  int directory = stat(dir, &st);

  if (directory == -1) {
    mkdir(dir, 0700);
  }
}
