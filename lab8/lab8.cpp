#include "OptionStudent.h"
#include <vector>
using namespace std;

size_t OptionStudent::count_ = 0;

OptionStudent::OptionStudent(string id , string firstName , string lastName, int term, string option)
:Student(id, firstName, lastName), term_(term), option_(option) {
  count_++;
}

OptionStudent::OptionStudent(const OptionStudent& s):Student(s), term_(s.term_), option_(s.option_) {
  count_++;
}

OptionStudent::OptionStudent(OptionStudent&& s):Student(move(s)), term_(move(s.term_)), option_(move(s.option_)) {
  count_++;
}

void OptionStudent::display(ostream& os) const {
  Student::display(os);
  os << "\nTerm: " << term_ << "\nOption: " << option_ ;
}

ostream& operator<<(ostream& os, const OptionStudent& s) {
  return os << (const Student&)s << s.term_ << " " << s.option_ << " ";
}

istream& operator>>(istream& is, OptionStudent& s) {
    Student student;
    int term;
    string option;

    is.clear();

    if (is >> student >> term >> option) {
      (Student&) s = student;
      s.term_ = term;
      s.option_ = option;
    }
    return is;
}

int main() {
  vector<OptionStudent> optionStudents;
  OptionStudent s;

  while (cin >> s) {
    cout << "Creating student\n" << "Number of optionStudents: " << s.getCount() << endl;
    optionStudents.push_back(s);
  }

  cout << "Current Students" << endl;

  for (auto x = optionStudents.begin() ; x != optionStudents.end() ; ++x) {
    ((OptionStudent&)*x).display(cout);
  }


}
