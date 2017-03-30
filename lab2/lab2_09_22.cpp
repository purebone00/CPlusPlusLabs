#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

bool checkInt(const int& n);
bool checkFloat(const float& n);
void print(ostream& os, int& stdID, float& grade);
bool input_int(const string& prompt, int& n, bool (*isvalid)(const int&));
bool input_float(const string& prompt, float& n, bool (*isvalid)(const float&));



int main() {

  fstream out("test.dat", ios_base::out | ios_base::binary);

  if (!out) {
    cerr << "unable to write to file" << endl;
    return 1;
  }

  string promptInt ("Enter an Student ID");
  string promptFloat ("Enter a grade");
  int studentID;
  float grade;

  while (input_int(promptInt, studentID, checkInt)
          && input_float(promptFloat, grade, checkFloat)) {

      print(out, studentID, grade);
  }
}

bool input_int(const string& prompt, int& n, bool (*isvalid)(const int&)) {
  int check;
  string line;
  while (1) {
    cout<<prompt<<endl;
    if (!getline(cin, line)) {
      cin.clear();
      break;
    }
    istringstream iss(line);
    if ((iss>>check) && isvalid(check)) {
      n = check;
      return true;
    }
  }
  return false;
}

bool input_float(const string& prompt, float& n, bool (*isvalid)(const float&)) {
  float check;
  string line;
  while (1) {
    cout<<prompt<<endl;
    if (!getline(cin, line)) {
      cin.clear();
      break;
    }
    istringstream iss(line);
    if ((iss>>check) && isvalid(check)) {
      n = check;
      return true;
    }
  }
  return false;
}

bool checkInt(const int& n) {
  return (n < 10000 || n > 99999999) ? false : true;
}

bool checkFloat(const float& n) {
  return (n < 0 || n > 100) ? false : true;
}

void print(ostream& os, int& stdID, float& grade) {
  os<<setw(8)<<dec<<stdID<<" "<<setw(6)<<fixed<<setprecision(2)<<grade<<" ";
}
