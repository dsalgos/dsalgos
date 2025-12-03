# `dsalgos`

This is a C++ project that defines a static library that can be used to create basic data structures and perform basic algorithms on them.

## Code Organiztion

- The header files are present in the `/include` folder.
- The source code is present in `/src`.
- The `Doxyfile` defines a configuration for `doxygen` that allows you automatically generate complete documentation for the API exposed by this library.

## Documentation

Apart from this `README.md` file, documentation for the entire API exposed by this library can be generated using `doxygen` by following the steps listed below:

1. **Install `doxygen`**: `sudo apt install doxygen` on Debian-based Linux distros.
2. **Run `doxygen`**: `doxygen Doxyfile`
3. **View documentation**: Open up `docs/html/index.html` to view the generated documentation.

## Testing

The tests for this library are present in the `/tests` folder. You can compile and run them using `CMake` as follows:

```bash
cmake ..
make
ctest
```

The testing framework used is `Google Test`.

## Current Status

For now, the library is limited to the List ADT and basic sorting algorithms.

## AI Disclosure

We have focused on defining a clear structure and writing documentation and configuration files for the project.
Most of the implementation code is AI-written. In addition, AI has been used to generate the following two configuration files:

- `.clang-format`: To describe a consistent formatting for the entire codebase
- `Doxyfile`: To create a configuration for Doxygen

## Contributors

1. Arjun Singh (R.No. 10)
2. Ashish Pal (R.No. 12)
