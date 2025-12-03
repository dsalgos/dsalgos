cmake_minimum_required(VERSION 3.10)
project(dsalgos CXX)

# Require C++17 or later
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# -------------------------------------------------------------------------- #
#                                Dependencies                                #
# -------------------------------------------------------------------------- #

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
  DOWNLOAD_EXTRACT_TIMESTAMP ON
)

FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
  GIT_TAG v6.1.9
)

FetchContent_MakeAvailable(googletest)
FetchContent_MakeAvailable(ftxui)

# -------------------------------------------------------------------------- #
#                             Package to be built                            #
# -------------------------------------------------------------------------- #

# ----------------------------- DSAlgos Library ---------------------------- #

add_library(dsalgos STATIC)
target_include_directories(dsalgos PUBLIC include)
target_sources(dsalgos PRIVATE src/dsalgos/list/linkedlist.cpp src/dsalgos/list/list.cpp)
target_sources(dsalgos PRIVATE src/dsalgos/sorting/bubble.cpp src/dsalgos/sorting/insertion.cpp src/dsalgos/sorting/selection.cpp src/dsalgos/sorting/merge.cpp src/dsalgos/sorting/quick.cpp)

# ------------------------------- Visualizer ------------------------------- #

add_executable(visualizer src/visualizer/main.cpp src/visualizer/menu/menu.cpp src/visualizer/sorting/sort_visualizer.cpp)
target_link_libraries(visualizer PRIVATE dsalgos ftxui::screen ftxui::dom ftxui::component)

# -------------------------------------------------------------------------- #
#                                    Tests                                   #
# -------------------------------------------------------------------------- #

enable_testing()

# ------------------------------- List Tests ------------------------------- #

add_executable(list_tests tests/list/test_list.cpp)
target_link_libraries(list_tests PRIVATE GTest::gtest_main)
target_link_libraries(list_tests PUBLIC dsalgos)
target_include_directories(list_tests PUBLIC include)

add_test(NAME list_tests COMMAND list_tests)

# ---------------------------- Linked List Tests --------------------------- #

add_executable(linked_list_tests tests/list/test_linkedlist.cpp)
target_link_libraries(linked_list_tests PRIVATE GTest::gtest_main)
target_link_libraries(linked_list_tests PUBLIC dsalgos)
target_include_directories(linked_list_tests PRIVATE include)

add_test(NAME linked_list_tests COMMAND linked_list_tests)

# ------------------------------ Sorting Tests ----------------------------- #

# Bubble Sort Tests
add_executable(bubble_sort_tests tests/sorting/test_bubble.cpp)
target_link_libraries(bubble_sort_tests PRIVATE GTest::gtest_main)
target_link_libraries(bubble_sort_tests PUBLIC dsalgos)
target_include_directories(bubble_sort_tests PRIVATE include)

add_test(NAME bubble_sort_tests COMMAND bubble_sort_tests)

# Insertion Sort Tests
add_executable(insertion_sort_tests tests/sorting/test_insertion.cpp)
target_link_libraries(insertion_sort_tests PRIVATE GTest::gtest_main)
target_link_libraries(insertion_sort_tests PUBLIC dsalgos)
target_include_directories(insertion_sort_tests PRIVATE include)

add_test(NAME insertion_sort_tests COMMAND insertion_sort_tests)

# Selection Sort Tests
add_executable(selection_sort_tests tests/sorting/test_selection.cpp)
target_link_libraries(selection_sort_tests PRIVATE GTest::gtest_main)
target_link_libraries(selection_sort_tests PUBLIC dsalgos)
target_include_directories(selection_sort_tests PRIVATE include)

add_test(NAME selection_sort_tests COMMAND selection_sort_tests)

# Merge Sort Tests
add_executable(merge_sort_tests tests/sorting/test_merge.cpp)
target_link_libraries(merge_sort_tests PRIVATE GTest::gtest_main)
target_link_libraries(merge_sort_tests PUBLIC dsalgos)
target_include_directories(merge_sort_tests PRIVATE include)

add_test(NAME merge_sort_tests COMMAND merge_sort_tests)

# Quick Sort Tests
add_executable(quick_sort_tests tests/sorting/test_quick.cpp)
target_link_libraries(quick_sort_tests PRIVATE GTest::gtest_main)
target_link_libraries(quick_sort_tests PUBLIC dsalgos)
target_include_directories(quick_sort_tests PRIVATE include)

add_test(NAME quick_sort_tests COMMAND quick_sort_tests)
