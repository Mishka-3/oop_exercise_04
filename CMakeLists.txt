# CMakeList.txt: проект CMake для oop_exercise_04; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("oop_exercise_04")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (oop_exercise_04 "oop_exercise_04.cpp" "oop_exercise_04.h" "Point.cpp" "Point.h" "Figure.h" "Fiveangle.cpp" "Fiveangle.h" "List.cpp" "List.h" "Item.cpp" "Item.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
