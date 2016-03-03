MESSAGE(STATUS "GENERADOR: Creando un ejemplo")


# ETSIDict library


ADD_EXECUTABLE(generator dict_creator2.cpp)




add_custom_command(
    TARGET generator
    POST_BUILD
    COMMAND ${CMAKE_COMMAND}
    ARGS -E copy ${CMAKE_CURRENT_SOURCE_DIR}/es_ES.aff ${CMAKE_CURRENT_BINARY_DIR}
)
add_custom_command(
    TARGET generator
    POST_BUILD
    COMMAND ${CMAKE_COMMAND}
    ARGS -E copy ${CMAKE_CURRENT_SOURCE_DIR}/es_ES.aff ${CMAKE_CURRENT_BINARY_DIR}
)