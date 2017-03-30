#include <iostream>
#include <string>
using namespace std;

string ltrim(const string& s, int (*is_junk)(int));
string rtrim(const string& s, int (*is_junk)(int));
string cdelete(const string& s, int (*is_junk)(int));
string sdelete(const string& s, const string& junk);
string squeeze(const string& s, char c);
int is_junk(int junk);

int main() {
  string testString ("       What fox         ");

  cout << testString << 'b' << endl;

  cout << ltrim(testString, is_junk) << "END" << endl;

  cout << rtrim(testString, is_junk) << "END" << endl;

  cout << cdelete(testString, is_junk) << "END" << endl;

  cout << sdelete(testString, "fox") << "END" << endl;

  cout << squeeze("aaahaaasapeemaapetilon", 'a') << endl;
}

int is_junk(int junk) {
  return isspace(junk);
}

string ltrim(const string& s, int (*is_junk)(int)) {
  string::size_type i, sz = s.size();
  string ss;
  for(i=0; i < sz; ++i)
    if(!is_junk(s[i]))
      break;
  ss=s.substr(i);
  return ss;
}

string rtrim(const string& s, int (*is_junk)(int)) {
  string::size_type i = s.size();
  string ss;
  while (1) {
    if (i != 0 && !is_junk(s[--i])) {
      break;
    }
  }
  ss = s.substr(0, ++i);
  return ss;
}

string cdelete(const string& s, int (*is_junk)(int)) {
  string::size_type i, j = 0, sz = s.size();
  string ss;

  for(i=0; i < sz ; i++) {
    if(!is_junk(s[i]))
      ss += s[i];
  }
  return ss;
}

string sdelete(const string& s, const string& junk) {
  string::size_type pos, sz = junk.size();
  string ss (s);
  while ((pos = ss.find(junk)) != string::npos) {
    ss = ss.erase(pos, sz);
  }
  return ss;
}

/*string squeeze(const string& s, char c) {
  string::size_type i, sz = s.size();
  string ss;
  bool bounce = false;
  for(i=0; i < sz ; i++) {
    if(s[i] != c) {
      bounce = false;
      ss += s[i];
      continue;
    }
    if (!bounce) {
      bounce = true;
      ss += s[i];
    }
  }
  return ss;
}*/

string squeeze(const string& s, char c) {
  string::size_type i = 0, sz = s.size();
  string ss;
  bool bounce = false;
  for(i=0; i < sz ; i++) {
    if (!bounce || s[i] != c) {
      ss+=s[i];
      bounce = (s[i] == c);
    }
  }
  return ss;
}
