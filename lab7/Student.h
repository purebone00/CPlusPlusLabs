#include <string>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <iostream>

typedef std::pair<std::string, std::string>Name;

class Student {
public:
  explicit Student(std::string id = "a00000000", std::string firstName = "Ned", std::string lastName = "Flanders")
  : id_(id), name_(firstName, lastName) {
      if (!isValidId(id) || !isValidName(firstName) || !isValidName(lastName)) {
        throw "Invalid values";
      }
  }

  bool operator<(const Student& rhs) const {
    return this->id_ < rhs.id_;
  }

  friend std::ostream& operator<<(std::ostream& os, const Student& student) {
    return os << student.id_ << " " << student.name_.first << " " << student.name_.second;
  }

  friend std::istream& operator>>(std::istream& is, Student& student) {
    std::string id, firstName, lastName;
    is.clear();

    if (is >> id >> firstName >> lastName) {
      std::transform(id.begin(), id.end(), id.begin(), ::tolower);
      std::transform(firstName.begin(), firstName.end(), firstName.begin(), ::tolower);
      std::transform(lastName.begin(), lastName.end(), lastName.begin(), ::tolower);

      Student temp(id, firstName, lastName);
      student = temp;
    }

    return is;
  }

  virtual ~Student() {}
private:
  std::string id_;
  Name        name_;

  static bool isValidId(const std::string& id) {
    if (std::tolower(id[0]) != 'a' || id.size() != 9) {
      return false;
    }
    return true;
  }

  static bool isValidName(const std::string& name) {
    if (name.size() == 0) {
      return false;
    }
    for (auto it = name.begin() ; it != name.end() ; ++it) {
      if (std::isspace(*it)) {
        return false;
      }
    }
    return true;
  }
};
