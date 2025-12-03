/**
 * @file menu.cpp
 * @author Arjun Singh
 * @brief Implementation of main menu
 */

#include "menu.hpp"

// External dependencies
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

// Internal dependencies
#include "../sorting/sort_visualizer.hpp"

using namespace ftxui;

/**
 * @brief Display the main menu interface
 */
void displayMenu() {
    auto screen = ScreenInteractive::Fullscreen();

    // Menu options
    std::vector<std::string> menuItems = {"Sorting Algorithms", "Exit"};

    int selected = 0;

    // Menu component
    auto menu = Menu(&menuItems, &selected);

    // Select button
    auto selectButton = Button("Select", [&] {
        if (selected == 0) {
            // Launch sorting visualizer
            screen.ExitLoopClosure()();
            visualizer::displaySortVisualizer();
            screen.Loop(Renderer([&] { return text(""); })); // Dummy to re-enter
        } else if (selected == 1) {
            // Exit
            screen.ExitLoopClosure()();
        }
    });

    // Exit button
    auto exitButton = Button("Exit", [&] { screen.ExitLoopClosure()(); });

    auto container = Container::Vertical({menu, Container::Horizontal({selectButton, exitButton})});

    auto renderer = Renderer(container, [&] {
        auto menuBox =
            vbox({text("Select a Visualizer:") | bold | center, separator(), menu->Render()})
            | border | size(WIDTH, EQUAL, 40);

        auto buttons =
            hbox({selectButton->Render() | center, separator(), exitButton->Render() | center})
            | border;

        return vbox(
                   {text("═══════════════════════════════════════════════════════") | bold | center,
                    text("        DSAlgos Visualizer") | bold | center,
                    text("═══════════════════════════════════════════════════════") | bold | center,
                    separator(), menuBox, separator(), buttons, filler()})
               | border | center;
    });

    screen.Loop(renderer);
}
