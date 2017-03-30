// set of students

typedef pair<string, string> Name;

using Name = pair<string, string;

struct student {
  string id;
  Name name;
  Student(const string& i, const Name& n)

  :id(i), name(n) {

  }
};

bool operator< (const Student& st1, const Student& st2)  {
  return st1.id < st2.id;
}

int main()) {
  set <Student> s;
  Student       st;
  while (cin >> st) {
    s.insert(st);
  }

  for(const auto& x : s)
    cout << x << endl;
}

ostream& operator<< (ostream& os, const Student& s) {
  return os << s.id << ' ' << s.name.first << ' ' << s.name.second;
}

istream& operator>> (ostream& is, const Student& s) {
  return is >> s.id >> s.name.first >> s.name.second;
}

/*
what if we need another set of students
in the same program but using a different sorting order?

set can take a second duplicate parameter used to specify the sorting order

*/

set<Student, Cmp> s2;

struct Cmp {
  bool operator()(const Student& st1, const Student& st2) const {
    if (st1.name.second != st2.name.second) {
      return st1.name.second < st2.name.second;
    }
    return st1.name.first < st2.name.first;
  }
};
