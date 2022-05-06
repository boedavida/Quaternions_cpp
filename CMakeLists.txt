# vim: et ts=4 sts=4 sw=4 tw=0
cmake_minimum_required( VERSION 3.8 )

project( quaternions )

set( CMAKE_MODULE_PATH
        ${CMAKE_MODULE_PATH}
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules"
        )

# Define project sources
set( PROJECT_SOURCES
        main.cpp
        quaternion.cpp
        linalg.cpp
        )

# Define project includes
set( PROJECT_INCLUDES
        quaternion.h
        linalg.h
        )

# Build the executable
add_executable( ${PROJECT_NAME} ${PROJECT_SOURCES} )

set( LIBS
        ${LIBS}
        )
# Link required libs to the executable
target_link_libraries( ${PROJECT_NAME}
        ${LIBS}
        ${EXTERNAL_LIBS}
        )

install( TARGETS ${PROJECT_NAME} DESTINATION ${PROJECT_SOURCE_DIR}/bin )
install( TARGETS ${PROJECT_NAME} DESTINATION ${PROJECT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE} )
