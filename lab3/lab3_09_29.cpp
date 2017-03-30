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
void inputRecords(ostream& open);
void promptMenu();
void menuSelect(char& choice);
void displayRecords(istream& is);
void displayAllRecords(istream& is);


int main(int argc, char const *argv[]) {

  string choice;

  if (argc != 2) {
    cerr << "Usage: {File name}";
    return 1;
  }

  fstream open(argv[1], ios_base::in | ios_base::out | ios_base::binary | ios_base::trunc);

  if (!open) {
    cerr << "unable to open file: " << argv[1] << endl;
    return 1;
  }

  int selection;

  while (1) {
    promptMenu();
    if (!getline(cin, choice)) {
      cin.clear();
      break;
    }
    istringstream iss(choice);
    iss>>selection;
    if (selection == 1) {
      inputRecords(open);
    } else if (selection == 2) {
      displayRecords(open);
    }
  }
}

void displayRecords(istream& is) {
  string choice;
  int index;
  string line;
  string id, grade;
  while (1) {
    cout << "Enter index:" << endl;
    if (!getline(cin, choice)) {
      cin.clear();
      break;
    }
    istringstream iss(choice);
    iss>>index;
    is.clear();
    if (index == 0) {
      break;
    } else if (index > 0) {
      if (is.seekg(index * 16 - 16, is.beg)) {
        is >> id >> grade;
        if (is.eof()) {
          cout << 'A' << id << ": " << grade;
        } else {
          cout << 'A' << id << ": " << grade << endl;
        }
      }
    } else if (index < 0) {
      if (is.seekg(index * -16 - 16, is.beg)) {
        displayAllRecords(is);
      }
    }
  }
}

void displayAllRecords(istream& is) {
  string id, grade;
  while (is >> id >> grade) {    
    if (is.eof()) {
      cout << 'A' << id << ": " << grade;
    } else {
      cout << 'A' << id << ": " << grade << endl;
    }
  }
}

void promptMenu() {
  cout << "1. Input records" << endl;
  cout << "2. Display records" << endl;
}

void inputRecords(ostream& open) {
  string promptInt ("Enter an Student ID");
  string promptFloat ("Enter a grade");
  int studentID;
  float grade;
  while (input_int(promptInt, studentID, checkInt)
          && input_float(promptFloat, grade, checkFloat)) {
      print(open, studentID, grade);
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
  os.seekp(0, os.end);
  os.clear();
  os<<setw(8)<<setfill('0')<<dec<<stdID<<setfill(' ')<<" "<<setw(6)<<fixed<<setprecision(2)<<grade<<" ";
}
