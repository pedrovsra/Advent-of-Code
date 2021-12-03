#include <stdio.h>
using namespace std;

int counter = 0;

int lastWindowSum = -1;
int currentWindowSum = 0;

int reading;
int readings[10000];
int index = 0;

int sumOfArray(int* arr, int length);

int main() {
  FILE* f = fopen("day1.txt", "r");

  while(!feof(f)) fscanf(f, "%d", &readings[index++]);

  for (int i = 0; i <= index - 3; i++) {
    currentWindowSum = sumOfArray(readings + i, 3);

    if (lastWindowSum != -1 && currentWindowSum > lastWindowSum) counter++;

    lastWindowSum = currentWindowSum;
  }

  printf("%d", counter);

  return 0;
}

int sumOfArray(int* arr, int length) {
  int sum = 0;

  for(int i = 0; i < length; i++) sum += arr[i];

  return sum;
}
