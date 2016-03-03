MESSAGE(STATUS "EXAMPLE: Creando un ejemplo")


# ETSIDict library


ADD_EXECUTABLE(example example.cpp)


TARGET_INCLUDE_DIRECTORIES(example PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)
