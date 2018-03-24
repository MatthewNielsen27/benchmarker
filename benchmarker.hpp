//////////////////////////////////////////////////////////////
// Title: Benchmarker ////////////////////////////////////////
// Description: C++ inline code benchmarking library /////////
// Written by: Matthew Nielsen ///////////////////////////////
// Date: March 24 2018 ///////////////////////////////////////
//////////////////////////////////////////////////////////////

#ifndef BENCHMARKER_HPP
#define BENCHMARKER_HPP

#include <string>
#include <vector>
#include <chrono>

class Benchmarker{
  private:
  //  Vectors to hold breakpoints and times
  std::vector<std::string> breakpoints;
  std::vector<std::chrono::high_resolution_clock::time_point> times;

  //  If the benchmark is underway
  bool started;

  public:
  //  Constructor
  Benchmarker();

  //  To start the benchmarker with a certain title
  //  Returns false if benchmark is currently underway
  bool start(std::string title);

  //  To add a checkpoint with a certain title
  //  Returns false if no benchmark is underway
  bool checkpoint(std::string title);

  //  To end the benchmark. If display_results is true
  //  benchmark results will be printed to the console.
  //  Returns false if no benchmark is underway
  bool end(bool display_results);

  // Print current benchmark results to the console
  void display();
};

#endif