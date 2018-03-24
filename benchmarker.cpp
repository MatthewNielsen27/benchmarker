//////////////////////////////////////////////////////////////
// Title: Benchmarker ////////////////////////////////////////
// Description: C++ inline code benchmarking library /////////
// Written by: Matthew Nielsen ///////////////////////////////
// Date: March 24 2018 ///////////////////////////////////////
//////////////////////////////////////////////////////////////

#include <iostream>
#include "benchmarker.hpp"

//  Constructor
Benchmarker::Benchmarker(){
  started = false;
}

//  To start the benchmarker with a certain title
//  Returns false if benchmark is currently underway
bool Benchmarker::start(std::string title){
  using namespace std::chrono;

  if(!started){
    high_resolution_clock::time_point _start = high_resolution_clock::now();

    times.push_back(_start);

    breakpoints.push_back("START [" + title + "]:");

    started = true;

    return true;

  }else return false;
}

//  To add a checkpoint with a certain title
//  Returns false if no benchmark is underway
bool Benchmarker::checkpoint(std::string title){
  using namespace std::chrono;

  if(started){
    high_resolution_clock::time_point _checkpoint = high_resolution_clock::now();

    times.push_back(_checkpoint);

    breakpoints.push_back(title + ": ");

    return true;

  }else return false;
}

//  To end the benchmark. If display_results is true
//  benchmark results will be printed to the console.
//  Returns false if no benchmark is underway
bool Benchmarker::end(bool display_results){
  using namespace std::chrono;

  if(started){
    if(display_results)
      display();

    started = false;
    
    return true;
  }else return false;
}

// Print current benchmark results to the console
void Benchmarker::display(){
  using namespace std::chrono;

  std::string name;
  std::string header = "--------------------BENCHMARK RESULTS";

  //  Benchmark header
  header.resize(66, '-');
  std::cout << header << "\n";

  for(int x = 0; x < breakpoints.size(); x++){
    //Retrieve and format current title name
    name = breakpoints[x];
    name.resize(50,' ');

    if(x == 0){
      //  Benchmark start
      std::cout 
        << name 
        << "0.0 seconds\n";

    }else if(x == breakpoints.size() - 1){
      // Last checkpoint
      duration<double> time_span = 
        duration_cast<duration<double> >(times[x] - times[x - 1]);

      std::cout 
        << name 
        << time_span.count() 
        << " seconds\n";

      //  Total elapsed time
      time_span = 
        duration_cast<duration<double> >(times[x] - times[0]);

      name = "TOTAL:";
      name.resize(50,' ');

      std::cout 
        << name
        << time_span.count() 
        << " seconds\n";

    }else{
      //  Checkpoints
      duration<double> time_span = 
        duration_cast<duration<double> >(times[x] - times[x - 1]);

      std::cout 
        << name 
        << time_span.count() 
        << " seconds\n";

    }
  }

  //  Benchmark footer
  header = "";
  header.resize(66, '-');

  std::cout << header << "\n";
}