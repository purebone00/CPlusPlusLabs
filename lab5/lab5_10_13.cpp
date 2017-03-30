#include <iostream>
#include <vector>
using namespace std;

int kth_selection(const vector<int>& v, size_t k);
vector<string> subsets(size_t n);
vector<string> leftSubSets(size_t n);
vector<string> rightSubSets(size_t n);
template <typename T> void print(const vector<T>& v);
int pow(int base, int power);
string properNth(int number);

/* main */
int main() {
  vector<int> vec = {4,2,3,4,2,6,5};
  int nth   = 1;
  int elems = 4;

  cout << "Given the vector of ";
  print(vec);

  cout << "\nThe " << nth << properNth(nth) << " smallest element is: " << kth_selection(vec, nth) << endl;

  cout << "\nGiven " << elems << " bits you can create the following permentations "
                                            << "(ordered so only 1 bit changes):" << endl;
  print(subsets(elems));
}

/* part 1 */
int kth_selection(const vector<int>& v, size_t k) {
  vector<int> left, mid, right;

  int firstElement = v.front();

  if (v.size() == 1) {
    return v.front();
  }

  for( auto it = v.cbegin() ; it != v.cend() ; ++it) {
    if (*it == firstElement) {
      mid.push_back(*it);
    } else if (*it < firstElement) {
      left.push_back(*it);
    } else {
      right.push_back(*it);
    }
  }

  if (left.size() >= k) {
    return kth_selection(left, k);
  } else if ((left.size() + mid.size()) >= k) {
    return mid.front();
  } else {
    return kth_selection(right, k - (mid.size() + left.size()));
  }
}

/* part 2 */
vector<string> subsets(size_t n) {
  vector<string> v;

  if (n == 0) {
    v.push_back("");
    return v;
  }

  vector<string> nextV = subsets(n - 1);

  for (auto it = nextV.begin() ; it != nextV.end() ; ++it) {
    v.push_back("0" + *it);
  }

  for (auto it = nextV.rbegin() ; it != nextV.rend() ; ++it) {
    v.push_back("1" + *it);
  }

  return v;
}

/* print function */
template <typename T> void print(const vector<T>& v) {
  for (auto it = v.cbegin() ; it != v.cend() ; ++it) {
    cout << *it << " ";
  }
}

/* power fuction */
int pow(int base, int power) {
  return (power == 1) ? base : (base * pow(base, power - 1));
}

/* gives the proper grammer for nth */
string properNth(int number) {
  switch (number) {
    case 1:
      return "st";
      break;
    case 2:
      return "nd";
      break;
    case 3:
      return "rd";
      break;
    default:
      return "th";
  }
}

/*
vector<string> subsets(size_t n) {
  vector<string> v, left, right;

  int numberOfElements = pow(2, n);

  left = leftSubSets(numberOfElements/2);
  right = rightSubSets(numberOfElements/2);

  v.insert(v.end(), left.begin(), left.end());
  v.insert(v.end(), right.begin(), right.end());

  return v;
}

vector<string> leftSubSets(size_t n) {
  vector<string> result, left, right;
  if (n == 1) {
    result.push_back("0");
    return result;
  }

  left = leftSubSets(n/2);
  right = rightSubSets(n/2);

  result.insert(result.end(), left.begin(), left.end());
  result.insert(result.end(), right.begin(), right.end());

  for (auto it = result.begin() ; it != result.end(); ++it) {
    *it = "0" + *it;
  }

  return result;
}

vector<string> rightSubSets(size_t n) {
  vector<string> result, left, right;
  if (n == 1) {
    result.push_back("1");
    return result;
  }

  right = rightSubSets(n/2);
  left = leftSubSets(n/2);

  result.insert(result.end(), right.rbegin(), right.rend());
  result.insert(result.end(), left.rbegin(), left.rend());

  for (auto it = result.rbegin() ; it != result.rend(); ++it) {
    *it = "1" + *it;
  }

  return result;
}
*/
