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
  int last;
  int count;
  for (int i = 1; i < argc; i++) {
    fd = fopen(argv[i], "r");
    if (!fd) {
      perror("fopen");
      exit(EXIT_FAILURE);
    }

    c = last = fgetc(fd);
    count = 0;
    while (c != EOF) {
      if (c != last) {
        fwrite(&count, sizeof(int), 1, stdout);
        fputc(last, stdout);
        count = 1;
      } else {
        count++;
      }

      last = c;
      c = fgetc(fd);
    }

    if (ferror(fd)) {
      perror("fgetc");
      fclose(fd);
      exit(EXIT_FAILURE);
    }

    fclose(fd);
  }

  return 0;
}
