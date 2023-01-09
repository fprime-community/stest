# STest

STest is a C++ framework for **scenario-based testing**.
To carry out scenario-based testing, you write **rules** that
express aspects of the behavior of a system under test.
Then you compose the rules into **scenarios**, either manually or
automatically. A scenario is a behavior that you want to test.

Compared to traditional methods of writing tests, scenario-based
testing is more modular and structured, because you can combine the
same rules into different scenarios.
You can also generate scenarios automatically from rules.
Auto-generated scenarios typically provide much more state and
path coverage than it is possible to achieve with purely handwritten tests.

Section 4.2 of [this paper](https://digitalcommons.usu.edu/smallsat/2018/all2018/328/)
describes the idea of scenario-based testing and provides some
examples.
See also the section on **Using the Framework** below.

## Contents

This repository contains the following items:

* `STest`: The STest framework.

* `defs`: Definitions used by the build system in this repository,
including system-specific configuration.

* `scripts`: Scripts used by the build system.

## Requirements

To use this software, you need the following:

1. A Linux or Mac OS environment.

2. The [`redo` build system](https://github.com/bocchino/redo).

3. The [GoogleTest testing framework](https://github.com/google/googletest).
   On Mac OS, you can use MacPorts: `sudo port install gtest`.

4. (Optional) The [`spin` model checker](http://spinroot.com/spin/whatispin.html).
   On Mac OS, you can use MacPorts: `sudo port install spin`.

If you skip step 4, then you won't be able to run the tests that depend
on Spin.

## Installation

To install the software, carry out the following steps:

1. Clone this repository to your computer.

2. Copy `defs/config.sh.example` to `defs/config.sh`.
   Edit the file so the following variables have the desired values:

   * `GTEST_INCLUDE_PATH`: The include path for your GoogleTest installation.
     If you use MacPorts, this is `/opt/local/include`.

   * `GTEST_LIBRARY_PATH`: The library path for your GoogleTest installation.
     If you use MacPorts, this is `/opt/local/lib`.

## Running the Tests in This Repository

### Running All the Tests

To run all the tests, run `redo tests` (note the `s` at the end)
in the top-level directory.

### Running Selected Tests

You can run selected tests by running `redo test` (note there is
no `s` at the end) in any directory that contains a target `test.do`
You can run `find . test.do` at the top level to see all these
directories.

## Using the Framework

### Writing Tests in C++

When writing tests in C++, you start by writing rules.
Each rule is derived from the abstract class `Rule` provided by STest.
Then you pass instances of rules into scenario instances.
Each scenario instantiates one of the `Scenario` classes provided
by STest.
You can combine scenarios into other scenarios.
For example, there are scenarios for (1) picking a random sequence of
rules and (2) randomly interleaving two scenarios.

To see examples of rules and scenarios written in C++, look at the directory
`STest/Scenario/test`. The subdirectories contain
code fragments that the build system stitches together into a suite of
tests. The build system provides a nice way to select
which tests to run. However, you don't need to use the
build system in your own tests. To see an example of tests written in straight
C++, look at `STest/Scenario/test/main-generated.cpp`. This file
represents the output of the code generator with all tests enabled.

### Using the Spin Model Checker

You can also write tests in a combination of C++ and Promela, the
language of the Spin model checker.
When using this method, you write rules in C++ as described in
the previous section.
However, instead of writing scenarios in C++ using the STest scenario
classes, you write scenarios in Promela.

To see examples of scenarios written in Promela, look at the directory
`STest/spin`. Each subdirectory has a file `test.pml` that contains
a scenario written in Promela.
Writing tests in Promela lets you use the Spin model checker to drive
the selection of rules. The Spin-driven selection should explore the
state space of your system more intelligently than the STest framework,
which uses pseudo-random numbers as the driver for rule selection.

### Compiling and Linking Your Tests

**Header Files:**
Building the STest repository as described above generates the
header file `STest/exported.hpp`.
C++ files that depend on STest should include this header file.
It includes other header files that provide all
the C++ definitions you will need to use STest. Alternatively, you
can include just the headers for the definitions you need; to see what
headers are available, look at the file `STest/exported.hpp`.

**Compiling:** If you are using Spin, then when compiling your tests,
you must set the flag
```
-DSTEST_MODE_spin
```
on the compiler command line. This will tell the STest framework to include
the correct header files for compilation with Spin.

**Linking:** Building this repository as described above builds static
libraries for your host platform.
You can link your tests against these libraries as follows:

1. If you are not using Spin, then you should link your tests against
   ```
   STest/build/[platform name]/default/lib.a
   ```
   The platform name is Darwin or Linux.

2. If you are using Spin, then you should link your tests against
   ```
   STest/build/[platform name]/spin/lib.a
   ```

