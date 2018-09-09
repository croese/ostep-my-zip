#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  if (argc == 1) {
    printf("USAGE: %s file1 [file2...]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  return 0;
}
