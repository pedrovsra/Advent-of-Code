#include <stdio.h>
#include <string.h>
using namespace std;

const char FORWARD[] = "forward";
const char DOWN[] = "down";
const char UP[] = "up";

char command[10];
int unit = 0;

int position = 0;
int depth = 0;

int main() {

  FILE* f = fopen("input.txt", "r");

  while(fscanf(f, "%s %d", command, &unit) > 0) {
    if (strcmp(command, FORWARD) == 0) position += unit;
    else if (strcmp(command, DOWN) == 0) depth += unit;
    else if (strcmp(command, UP) == 0) depth -= unit;
  }

  printf("%d\n", (position * depth));

  return 0;
}
