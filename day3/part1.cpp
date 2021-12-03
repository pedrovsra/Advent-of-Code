#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string readings[10000];
int c = 0;
int bin_size;

int sum_zero = 0;
int sum_one = 0;

int main() {
  fstream input;

  input.open("input.txt", ios::in);

  while(getline(input, readings[c++])) {}

  bin_size = readings[0].length();

  char gamma_rate[bin_size];
  char epsilon_rate[bin_size];

  for(int j = 0; j < bin_size; j++) {
    for (int i = 0; i < c; i++) {
      if (readings[i][j] == '0') sum_zero++;
      else sum_one++;
    }

    if (sum_zero > sum_one) {
      gamma_rate[j] = '0';
      epsilon_rate[j] = '1';
    } else {
      gamma_rate[j] = '1';
      epsilon_rate[j] = '0';
    }

    sum_zero = 0;
    sum_one = 0;
  }

  printf("%d\n", (stoi(gamma_rate, 0, 2) * stoi(epsilon_rate, 0, 2)));

  return 0;
}
