cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)

project(ALGO)

# Réglage du compilateur pour les warnings
if (MSVC)
    add_compile_options(/W3)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -pedantic-errors)
endif()

# On souhaite placer l'exécutable dans un sous-dossier "bin" au lieu de le mettre dans le dossier build
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Obtenir la liste des fichiers sources dans le dossier src
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "src/*.cpp")

# On indique que l'on veut créer un exécutable "ex01" compilé à partir du fichier td01_ex01.cpp
# add_executable(TD5exo1 TD5/TD5exo1.cpp)


add_executable(main src/main.cpp)


