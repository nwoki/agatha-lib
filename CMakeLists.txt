project(libAgatha)

cmake_minimum_required(VERSION 2.6)

# Find Qt4. Need this to link and create static lib
FIND_PACKAGE(Qt4 REQUIRED)

include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

include_directories(${QT_INCLUDE_DIR})

set(libAgatha_SRCS
    src/player.cpp
)

# final lib
add_library(Agatha STATIC ${libAgatha_SRCS})

# link lib with Qt libs
target_link_libraries(Agatha ${QT_LIBRARIES})

# tests
enable_testing()
add_subdirectory(tests)