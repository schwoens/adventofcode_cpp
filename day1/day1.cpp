#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> elf;

vector<elf> parse_input(string path) {
  vector<elf> elves;
  elf elf;
  ifstream file(path);
  if (file.is_open()) {
    string line;
    while (file) {
      getline(file, line);
      try {
        elf.push_back(stoi(line));
      } catch (exception) {
        elves.push_back(elf);
        elf.clear();
      }
    }
  }
  return elves;
}

vector<int> get_calory_sums(vector<elf> elves) {
  vector<int> calory_sums;
  int sum;
  for (elf elf : elves) {
    sum = 0;
    for (int calories : elf) {
      sum += calories;
    }
    calory_sums.push_back(sum);
  }
  return calory_sums;
}

int get_max_carried_calories(vector<elf> elves, int amount = 1) {
  int sum = 0;
  vector<int> calory_sums = get_calory_sums(elves);
  sort(calory_sums.begin(), calory_sums.end());
  while (amount > 0) {
    sum += calory_sums.back();
    calory_sums.pop_back();
    amount--;
  }
  return sum;
}

void part1() {
  vector<elf> elves = parse_input("input.txt");
  int max_calories = get_max_carried_calories(elves);
  cout << "Part 1: " << max_calories << "\n";
}

void part2() {
  vector<elf> elves = parse_input("input.txt");
  int max_calories = get_max_carried_calories(elves, 3);
  cout << "Part 2: " << max_calories << "\n";
}

int main() {
  part1();
  part2();
  return 0;
}
