#ifndef  OPTIONSTUDENT_H
#define  OPTIONSTUDENT_H
#include "Student.h"

class OptionStudent: public Student {
public:
  explicit OptionStudent(std::string id = "a00000000", std::string firstName = "Ned", std::string lastName = "Flanders", int term = 1, std::string option = "IS");

  OptionStudent(const OptionStudent& s);

  OptionStudent(OptionStudent&& s);

  static size_t getCount() { return count_; }
  virtual void display(std::ostream& os) const override;

  friend std::ostream& operator<<(std::ostream& os, const OptionStudent& s);
  friend std::istream& operator>>(std::istream& is, OptionStudent& s);

  virtual ~OptionStudent() { count_--; }

private:
  int           term_;
  std::string   option_;
  static size_t count_;
};

#endif
