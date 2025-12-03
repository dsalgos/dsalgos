/**
 * @file sort_visualizer.cpp
 * @author Arjun Singh
 * @brief Implementation of sorting algorithm visualizer
 */

#include "sort_visualizer.hpp"

// External dependencies
#include <chrono>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <sstream>

// Internal dependencies - dsalgos
#include <dsalgos/list/list.hpp>
#include <dsalgos/sorting/bubble.hpp>
#include <dsalgos/sorting/insertion.hpp>
#include <dsalgos/sorting/merge.hpp>
#include <dsalgos/sorting/quick.hpp>
#include <dsalgos/sorting/selection.hpp>

using namespace ftxui;

namespace visualizer {

/**
 * @brief Parse comma-separated integers from string
 */
std::vector<int> parseIntegers(const std::string& input) {
    std::vector<int>  numbers;
    std::stringstream ss(input);
    std::string       token;

    while (std::getline(ss, token, ',')) {
        // Trim whitespace
        token.erase(0, token.find_first_not_of(" \t\n\r"));
        token.erase(token.find_last_not_of(" \t\n\r") + 1);

        if (!token.empty()) {
            try {
                numbers.push_back(std::stoi(token));
            } catch (...) {
                // Skip invalid numbers
            }
        }
    }

    return numbers;
}

/**
 * @brief Convert list to string representation
 */
std::string listToString(const dsalgos::List& list) {
    if (list.isEmpty()) {
        return "[]";
    }

    std::string result = "[";
    for (int i = 0; i < list.size(); i++) {
        result += std::to_string(list.get(i));
        if (i < list.size() - 1) {
            result += ", ";
        }
    }
    result += "]";
    return result;
}

/**
 * @brief Execute sorting and measure time
 */
void sortWithTiming(dsalgos::List& list, int algorithmIndex, int orderIndex,
                    double& executionTime) {
    auto start = std::chrono::high_resolution_clock::now();

    // Apply selected algorithm and order
    if (orderIndex == 0) { // Ascending
        switch (algorithmIndex) {
            case 0:
                dsalgos::sorting::bubbleSort(list);
                break;
            case 1:
                dsalgos::sorting::insertionSort(list);
                break;
            case 2:
                dsalgos::sorting::selectionSort(list);
                break;
            case 3:
                dsalgos::sorting::mergeSort(list);
                break;
            case 4:
                dsalgos::sorting::quickSort(list);
                break;
        }
    } else { // Descending
        switch (algorithmIndex) {
            case 0:
                dsalgos::sorting::bubbleSortDescending(list);
                break;
            case 1:
                dsalgos::sorting::insertionSortDescending(list);
                break;
            case 2:
                dsalgos::sorting::selectionSortDescending(list);
                break;
            case 3:
                dsalgos::sorting::mergeSortDescending(list);
                break;
            case 4:
                dsalgos::sorting::quickSortDescending(list);
                break;
        }
    }

    auto                                      end      = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> duration = end - start;
    executionTime                                      = duration.count();
}

/**
 * @brief Display the sorting visualizer interface
 */
void displaySortVisualizer() {
    auto screen = ScreenInteractive::Fullscreen();

    // State variables
    std::string inputText         = "";
    int         algorithmSelected = 0;
    int         orderSelected     = 0;
    std::string originalList      = "";
    std::string sortedList        = "";
    std::string executionTimeStr  = "";
    bool        hasSorted         = false;

    // Algorithm options
    std::vector<std::string> algorithms = {"Bubble Sort", "Insertion Sort", "Selection Sort",
                                           "Merge Sort", "Quick Sort"};

    // Order options
    std::vector<std::string> orders = {"Ascending", "Descending"};

    // Input component
    auto inputComponent = Input(&inputText, "Enter comma-separated integers (e.g., 5, 3, 8, 1, 9)");

    // Algorithm selection
    auto algorithmMenu = Radiobox(&algorithms, &algorithmSelected);

    // Order selection
    auto orderMenu = Radiobox(&orders, &orderSelected);

    // Sort button
    auto sortButton = Button("Sort", [&] {
        // Parse input
        auto numbers = parseIntegers(inputText);

        if (numbers.empty()) {
            originalList     = "No valid numbers entered!";
            sortedList       = "";
            executionTimeStr = "";
            hasSorted        = false;
            return;
        }

        // Create list
        dsalgos::List list;
        for (int num : numbers) {
            list.insert(num);
        }

        originalList = listToString(list);

        // Sort and measure time
        double execTime;
        sortWithTiming(list, algorithmSelected, orderSelected, execTime);

        sortedList = listToString(list);

        // Format execution time
        std::stringstream ss;
        ss.precision(2);
        ss << std::fixed << execTime << " μs";
        executionTimeStr = ss.str();

        hasSorted = true;
    });

    // Clear button
    auto clearButton = Button("Clear", [&] {
        inputText        = "";
        originalList     = "";
        sortedList       = "";
        executionTimeStr = "";
        hasSorted        = false;
    });

    // Exit button
    auto exitButton = Button("Exit", [&] { screen.ExitLoopClosure()(); });

    // Layout
    auto container =
        Container::Vertical({inputComponent, Container::Horizontal({algorithmMenu, orderMenu}),
                             Container::Horizontal({sortButton, clearButton, exitButton})});

    // Renderer
    auto renderer = Renderer(container, [&] {
        auto inputBox = hbox({text("Input: ") | bold, inputComponent->Render() | flex}) | border;

        auto algorithmBox =
            vbox({text("Select Algorithm:") | bold | center, separator(), algorithmMenu->Render()})
            | border | size(WIDTH, EQUAL, 30);

        auto orderBox =
            vbox({text("Select Order:") | bold | center, separator(), orderMenu->Render()}) | border
            | size(WIDTH, EQUAL, 25);

        auto selectionBoxes = hbox({algorithmBox, orderBox});

        auto buttons =
            hbox({sortButton->Render() | center, separator(), clearButton->Render() | center,
                  separator(), exitButton->Render() | center})
            | border;

        Element resultBox;
        if (hasSorted) {
            resultBox =
                vbox(
                    {text("Results") | bold | center, separator(),
                     hbox({text("Original List: ") | bold, text(originalList)}),
                     hbox({text("Sorted List:   ") | bold, text(sortedList) | color(Color::Green)}),
                     hbox({text("Execution Time: ") | bold,
                           text(executionTimeStr) | color(Color::Yellow)})})
                | border;
        } else if (!originalList.empty()) {
            resultBox = vbox({text("Results") | bold | center, separator(),
                              text(originalList) | color(Color::Red)})
                        | border;
        } else {
            resultBox = vbox({text("Results") | bold | center, separator(),
                              text("Enter numbers and click Sort to see results") | dim})
                        | border;
        }

        return vbox(
                   {text("═══════════════════════════════════════════════════════") | bold | center,
                    text("        Sorting Algorithm Visualizer") | bold | center,
                    text("═══════════════════════════════════════════════════════") | bold | center,
                    separator(), inputBox, separator(), selectionBoxes, separator(), buttons,
                    separator(), resultBox})
               | border | center;
    });

    screen.Loop(renderer);
}

} // namespace visualizer
