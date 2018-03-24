# Benchmarker

## A C++ library for in-line code performance benchmarking

### Usage

C++ implementation

```cpp
Benchmarker timer;

timer.start("Analysis of user input");

std::string input;
std::cin << input;

auto data = parseUserInput(input);
timer.checkpoint("Parse input");

auto result = performAnalysis(data);
timer.checkpoint("Analyze data");

logAnalysis(result);
timer.checkpoint("Log analyzed data");

timer.end(true);
```

Console output

```console
--------------------BENCHMARK RESULTS-----------------------------
START [Analysis of user input]:                   0.0 seconds
Parse input:                                      0.743928 seconds
Analyze data:                                     1.60011 seconds
Log analyzed data:                                0.447814 seconds
TOTAL:                                            2.79185 seconds
------------------------------------------------------------------
```

### License

[MIT LICENSE](LICENSE.md)