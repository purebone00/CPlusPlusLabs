#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int n;
  int width;
  char base = 'd';

  while (cin >> n >> width >> base) {
    if (base == 'd')
      cout<<dec;
    else if (base == 'o')
      cout<<oct;
    else if (base == 'x')
      cout<<hex<<nouppercase;
    else if (base == 'X')
      cout<<hex<<uppercase;

    cout<<setw(width)<<n<<endl;
  }
}
