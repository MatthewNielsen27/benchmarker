#include <iostream>
#include "benchmarker.hpp"

Benchmarker::Benchmarker(){
  started   = false;
}

bool Benchmarker::start(){
  using namespace std::chrono;

  if(!started){
    high_resolution_clock::time_point _start = high_resolution_clock::now();

    times.push_back(_start);

    breakpoints.push_back("START: ");

    started = true;

    return true;
  }else{
    return false;
  }
}

bool Benchmarker::checkpoint(std::string title){
  using namespace std::chrono;

  if(started){
    high_resolution_clock::time_point _checkpoint = high_resolution_clock::now();

    times.push_back(_checkpoint);

    breakpoints.push_back(title + ": ");

    return true;
  }else return false;
}

bool Benchmarker::end(){
  using namespace std::chrono;

  if(started){
    high_resolution_clock::time_point _end = high_resolution_clock::now();

    times.push_back(_end);

    breakpoints.push_back("END: ");

    started = false;

    return true;
  }else return false;
}

void Benchmarker::display(){
  using namespace std::chrono;

  int count = 0;

  std::string header = "--------------------BENCHMARK RESULTS";
  header.resize(66, '-');

  std::cout << header << "\n";

  for(auto name : breakpoints){
    duration<double> time_span = 
      duration_cast<duration<double> >(times[count] - times[0]);

    name.resize(50,' ');

    std::cout 
      << name 
      << time_span.count() 
      << " seconds\n";

    count++;
  }

  header = "";
  header.resize(66, '-');

  std::cout << header << "\n";
}