#include <iostream>
#include "benchmarker.hpp"

Benchmarker::Benchmarker(){
  started = false;
}

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

bool Benchmarker::checkpoint(std::string title){
  using namespace std::chrono;

  if(started){
    high_resolution_clock::time_point _checkpoint = high_resolution_clock::now();

    times.push_back(_checkpoint);

    breakpoints.push_back(title + ": ");

    return true;

  }else return false;
}

bool Benchmarker::end(bool display_results){
  using namespace std::chrono;

  if(started){
    if(display_results)
      display();

    started = false;
    
    return true;
  }else return false;
}

void Benchmarker::display(){
  using namespace std::chrono;
  std::string name;

  std::string header = "--------------------BENCHMARK RESULTS";

  header.resize(66, '-');

  std::cout << header << "\n";

  for(int x = 0; x < breakpoints.size(); x++){
    name = breakpoints[x];

    name.resize(50,' ');
    if(x == 0){
      std::cout 
        << name 
        << "0.0 seconds\n";

    }else if(x == breakpoints.size() - 1){
      duration<double> time_span = 
        duration_cast<duration<double> >(times[x] - times[x - 1]);

      std::cout 
        << name 
        << time_span.count() 
        << " seconds\n";

      time_span = 
        duration_cast<duration<double> >(times[x] - times[0]);

      name = "TOTAL:";
      name.resize(50,' ');

      std::cout 
        << name
        << time_span.count() 
        << " seconds\n";

    }else{
      duration<double> time_span = 
        duration_cast<duration<double> >(times[x] - times[x - 1]);

      std::cout 
        << name 
        << time_span.count() 
        << " seconds\n";

    }
  }

  header = "";
  header.resize(66, '-');

  std::cout << header << "\n";
}