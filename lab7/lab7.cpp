#include "Student.h"
#include <map>
using namespace std;

int main() {
  try {
    map<Student, int> m;
    Student s;
    int score;
    while(cin >> s >> score)
      m[s] += score;

    cout << "Student and total score" << endl;
    for (auto x : m) {
      cout << x.first << " " << x.second << endl;
    }

  } catch (const char* e) {
    cout << e;
  }
}
