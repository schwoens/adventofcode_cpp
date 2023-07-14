#include <exception>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
using namespace std;

enum class Move {
  ROCK,
  PAPER,
  SCISSORS,
};

typedef pair<Move, Move> round;

Move fromChar(char c) {
  switch (c) {
  case 'A':
    return Move::ROCK;
  case 'B':
    return Move::PAPER;
  case 'C':
    return Move::SCISSORS;
  case 'X':
    return Move::ROCK;
  case 'Y':
    return Move::PAPER;
  case 'Z':
    return Move::SCISSORS;
  default:
    throw invalid_argument("invalid character");
  }
}

vector<round> parse_input(string path) {
  vector<round> rounds;
  round round;
  ifstream file(path);
  string line;
  while (file) {
    getline(file, line);
    try {
      Move enemy_move = fromChar(line.at(0));
      Move my_move = fromChar(line.at(2));
      rounds.push_back(make_pair(enemy_move, my_move));
    } catch (exception) {
      break;
    }
  }
  return rounds;
}

int getMoveScore(const Move &move) {
  switch (move) {
  case Move::ROCK:
    return 1;
  case Move::PAPER:
    return 2;
  case Move::SCISSORS:
    return 3;
  default:
    throw invalid_argument("invalid move");
  }
}

int getOutcomeScore(const round &round) {
  int score = 0;
  if (round.first == Move::ROCK && round.second == Move::ROCK) {
    score = 3;
  }
  if (round.first == Move::ROCK && round.second == Move::PAPER) {
    score = 6;
  }
  if (round.first == Move::ROCK && round.second == Move::SCISSORS) {
    score = 0;
  }
  if (round.first == Move::PAPER && round.second == Move::ROCK) {
    score = 0;
  }
  if (round.first == Move::PAPER && round.second == Move::PAPER) {
    score = 3;
  }
  if (round.first == Move::PAPER && round.second == Move::SCISSORS) {
    score = 6;
  }
  if (round.first == Move::SCISSORS && round.second == Move::ROCK) {
    score = 6;
  }
  if (round.first == Move::SCISSORS && round.second == Move::PAPER) {
    score = 0;
  }
  if (round.first == Move::SCISSORS && round.second == Move::SCISSORS) {
    score = 3;
  }
  return score;
}

int get_score(const round &round) {
  return getMoveScore(round.second) + getOutcomeScore(round);
}

int get_total_score(const vector<round> &rounds) {
  int total_score = 0;
  for (round round : rounds) {
    total_score += get_score(round);
  }
  return total_score;
}

void part1() {
  cout << "Part 1: " << get_total_score(parse_input("input.txt")) << "\n";
}

int main() { part1(); }
