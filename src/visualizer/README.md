# Visualizer

This is a standalone C++ application that can be used to visualize the functioning of the `dsalgos` library.

Apart from the `dsalgos` library, it also depends upon the `FTXUI` library for building a command line interface for the application.

## Project Structure

```
visualizer/
├── CMakeLists.txt          # Build configuration
├── README.md               # This file
├── src/
│   ├── main.cpp           # Application entry point
│   ├── menu/              # Main menu module
│   │   ├── menu.hpp      # Menu interface header
│   │   └── menu.cpp      # Menu implementation
│   └── sorting/           # Sorting visualizer module
│       ├── sort_visualizer.hpp    # Sorting visualizer header
│       └── sort_visualizer.cpp    # Sorting visualizer implementation
```

## Features

### Sorting Algorithm Visualizer

The sorting visualizer provides an interactive interface for:

1. **Input**: Enter a comma-separated list of integers
2. **Algorithm Selection**: Choose from five sorting algorithms:

   - Bubble Sort
   - Insertion Sort
   - Selection Sort
   - Merge Sort
   - Quick Sort

3. **Order Selection**: Sort in ascending or descending order

4. **Results Display**:
   - Original list
   - Sorted list
   - Execution time in microseconds (μs)

## Building the Application

```bash
cd visualizer
mkdir build && cd build
cmake ..
make
./visualizer
```

## Usage

1. Launch the application
2. Select "Sorting Algorithms" from the main menu
3. Enter comma-separated integers (e.g., `5, 3, 8, 1, 9, 2`)
4. Select a sorting algorithm using arrow keys
5. Choose ascending or descending order
6. Click "Sort" to see the results
7. Click "Clear" to reset and try different inputs
8. Click "Exit" to return to the main menu

## Implementation Details

### Architecture

- **Modular Design**: Separate modules for menu and sorting visualization
- **FTXUI Components**: Uses interactive components like Input, Radiobox, Button, and Menu
- **Performance Measurement**: High-resolution clock for microsecond-precision timing
- **Error Handling**: Gracefully handles invalid input

### Input Parsing

The application accepts comma-separated integers with flexible whitespace handling:

- Valid: `1,2,3`, `1, 2, 3`, `1 , 2 , 3`
- Invalid entries are skipped automatically

### Time Complexity

The visualizer measures actual execution time, allowing comparison of:

- **O(n²) algorithms**: Bubble, Insertion, Selection Sort
- **O(n log n) algorithms**: Merge, Quick Sort

## Future Enhancements

Potential additions to the visualizer:

- List operations (insert, remove, search)
- Tree visualizations (Binary Tree, BST)
- Heap operations
- Graph algorithms
- Step-by-step animation of sorting process
- Comparison of multiple algorithms side-by-side
