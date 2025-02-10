#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#include <util.h>

/**********************************************************/
/*                 UTIL_CREATE_DIR                        */
/**********************************************************/

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

/**********************************************************/
/*                    UTIL_TRIM                           */
/**********************************************************/

char *util_trim(char *string) {
  int length = strlen(string);

  /* Remove left spaces */
  while (true) {
    if (*string == ' ') {
      string++;
      length -= 1;
      continue;
    }

    break;
  }

  /* Remove right spaces */
  while (true) {
    if (*(string + length - 1) == ' ') {
      length -= 1;
      continue;
    }

    break;
  }

  string[length] = '\0';

  return string;
}

/**********************************************************/
/*                    UTIL_CREATE_LABEL                   */
/**********************************************************/

void util_create_label(char *string) {
  int length = strlen(string);

  for (int i = 0; i < length; i++) {
    if (isspace(string[i])) {
      string[i] = ':';
      break;
    }
  }
}