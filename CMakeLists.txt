project(libAgatha)

cmake_minimum_required(VERSION 2.6)

# Find Qt4. Need this to link and create static lib
FIND_PACKAGE(Qt4 REQUIRED)

include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

include_directories(${QT_INCLUDE_DIR})

set(libAgatha_SRCS
    src/communicator.cpp
    src/player.cpp
    src/playerserializerobject.cpp
    src/responsegrabber.cpp
    src/requestmaker.cpp
    src/agathacallback.cpp
    src/buffer.cpp
    src/callbacklauncher.cpp
)

set(libAgatha_MOC_HDRS
    src/playerserializerobject.h
    src/responsegrabber.h
    src/buffer.h
)

qt4_wrap_cpp(libAgatha_MOC_SRCS ${libAgatha_MOC_HDRS})

# qjson
add_subdirectory(src/qjson/src)

# final lib
add_library(Agatha STATIC ${libAgatha_SRCS} ${libAgatha_MOC_SRCS})

# link lib with Qt libs
target_link_libraries(Agatha ${QT_LIBRARIES} qjson)

# tests
enable_testing()
add_subdirectory(tests)