#include <stdio.h>
using namespace std;

int firstReading;
int reading;
int counter = 0;

int main() {

  FILE* f = fopen("day1.txt", "r");

  fscanf(f, "%d", &firstReading);

  while(fscanf(f, "%d", &reading)==1) {
    if (reading > firstReading) counter++;

    firstReading = reading;
  }

  printf("%d", counter);

  return 0;
}
