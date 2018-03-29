#include <iostream>


GameEntry {
private:
  string name;
  int score;
public:
  GameEntry(const string& str=" ", int sc=0);
};

GameEntry::GameEntry(const string& str, int sc):
  name(str), score(sc) {;}
