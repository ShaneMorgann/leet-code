# Leet Code Solutions

This repository serves as a catalog of my [leetcode.com](https://leetcode.com/) problem solutions.

### Structure
---
- Directories named `_master-[language]` contain the entry point to run a solution for the mentioned language
- Each solution directory contains a sub-directory for each language used to solve the problem

#### C++

- All solutions exist within their own namespace for convience of running and switching between different solutions using a single `main()` function.
- Namespaces are named using the problem number from [leetcode](https://leetcode.com) in a 4-digit format.
- All solutions are executed by invoking the `run()` function of the corresponding namespace.

### Build and Run
---
#### C++
In `/src/_master-cpp/main.cc` change the `solution` variable to the desired solution. Solutions available can be referenced in `src/_master-cpp/solutions.hh`

**Linux:**
<br>This project uses make. Navigate to the projects .build directory and execute 'build' or 'run'. 'run' will first build the project before running.
<br>
```
cd leet-code/.build

>>> make build
>>> make run
```
