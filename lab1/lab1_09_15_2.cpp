#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  float n;
  int width, precision;
  char base = 'f';

  while (cin >> n >> width >> precision >> base) {
      if (base == 'f')
        cout<<fixed;
      else if (base == 'e')
        cout<<scientific<<nouppercase;
      else if (base == 'E')
        cout<<scientific<<uppercase;

    cout<<setw(width)<<setprecision(precision)<<n<<endl;
  }
}
