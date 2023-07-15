#include <cctype>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Backpack {
  pair<string, string> compartments;

public:
  Backpack(string str) {
    int length = str.length();
    string compartment1 = str.substr(0, length / 2);
    string compartment2 = str.substr(length / 2);
    this->compartments = make_pair(compartment1, compartment2);
  }

  int get_priority() {
    for (char c : compartments.first) {
      if (compartments.second.find(c) != string::npos) {
        int priority = c;
        if (islower(c)) {
          priority -= 96;
        } else {
          priority -= 38;
        }
        return priority;
      }
    }
    throw exception();
  }
};

vector<Backpack> parse_input(string path) {
  vector<Backpack> backpacks;
  ifstream file(path);
  string line;
  while (file) {
    getline(file, line);
    if (line.size()) {
      backpacks.push_back(line);
    }
  }
  return backpacks;
}

int get_priority_sum(vector<Backpack> backpacks) {
  int sum = 0;
  for (Backpack backpack : backpacks) {
    sum += backpack.get_priority();
  }
  return sum;
}

void part1() {
  cout << "Part 1: " << get_priority_sum(parse_input("input.txt"));
}

int main() { part1(); }
