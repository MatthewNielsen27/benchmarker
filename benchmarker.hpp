#include <string>
#include <vector>
#include <chrono>

class Benchmarker{
  private:
  std::vector<std::string> breakpoints;
  std::vector<std::chrono::high_resolution_clock::time_point> times;

  bool started;

  public:
  Benchmarker();
  bool start();
  bool checkpoint(std::string title);
  bool end();
  void display();
};