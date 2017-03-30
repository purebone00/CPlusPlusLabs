#include <atomic>
#include <thread>

class Timer {
public:
  Timer(unsigned sec = 0, bool ticking = false);
  void start();
  void stop();
private:
  std::atomic<unsigned long>  sec_;
  std::atomic<bool>           ticking_;
  void run();
};
