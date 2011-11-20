# Test libraries
set(TestLibraries ${QT_QTTEST_LIBRARY} ${QT_LIBRARIES} Agatha qjson)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# PlayerTest
set(PlayerTest_SRCS playertest.cpp)
qt4_automoc(${PlayerTest_SRCS})
add_executable(PlayerTest ${PlayerTest_SRCS})
target_link_libraries(PlayerTest ${TestLibraries})
add_test(NAME PlayerTest COMMAND PlayerTest)

# RequestMakerTest
set(RequestMakerTest_SRCS requestmakertest.cpp)
qt4_automoc(${RequestMakerTest_SRCS})
add_executable(RequestMakerTest ${RequestMakerTest_SRCS})
target_link_libraries(RequestMakerTest ${TestLibraries})
add_test(NAME RequestMakerTest COMMAND RequestMakerTest)