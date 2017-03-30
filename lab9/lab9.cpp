#include "timer.h"
#include <chrono>
#include <iostream>
#include <sstream>

using namespace std;

Timer::Timer(unsigned sec, bool ticking):sec_(sec), ticking_(ticking) {
  thread t(&Timer::run, this);
  t.detach();
}

void Timer::start() {
    cout << "Timer started" << endl;
    ticking_=true;
}

void Timer::stop() {
  ticking_=false;
  cout << "Timer stopped" << endl;
}

void Timer::run() {
  while (1) {
    std::this_thread::sleep_for(std::chrono::seconds(1));

    if (ticking_) {
      sec_++;
      cout<<sec_<<endl;
    }
  }
}

int main() {
  Timer timer(0, false);
  string input;
  cout << "'s' to start, 'h' to stop, 'x' to exit" << endl;
  while (cin >> input) {
    if (input == "s") {
      timer.start();
    } else if (input == "h") {
      timer.stop();
    } else if (input == "x") {
      timer.stop();
      break;
    }
  }
}
