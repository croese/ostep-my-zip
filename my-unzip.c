#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  if (argc == 1) {
    printf("USAGE: %s file1 [file2...]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE* fd;
  int c;
  int count;
  size_t nread;
  for (int i = 1; i < argc; i++) {
    fd = fopen(argv[i], "r");
    if (!fd) {
      perror("fopen");
      exit(EXIT_FAILURE);
    }

    while ((nread = fread(&count, sizeof(int), 1, fd)) == 1) {
      c = fgetc(fd);
      for (int j = 0; j < count; j++) {
        printf("%c", c);
      }
    }

    if (ferror(fd)) {
      perror("fread");
      fclose(fd);
      exit(EXIT_FAILURE);
    }

    fclose(fd);
  }

  return 0;
}
