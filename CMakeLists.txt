cmake_minimum_required (VERSION 3.25.2)

project("GYVD")

set (VERSION_MAJOR 0)
set (VERSION_MINOR 1)
set (VERSION_PATH 0)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set (CMAKE_EXE_LINKER_FLAGS "-rdynamic")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DI}/lib)
set (CMAKE_BUILD_TYPE Debug)

find_package (PkgConfig)
if (PKG_CONFIG_FOUND)
  pkg_check_modules (GTK "gtk+-3.0")
  if (GTK_FOUND)
    add_executable(gyvd "")
    target_sources(gyvd
    PUBLIC
      ${CMAKE_CURRENT_LIST_DIR}/src/main.c
    )
    target_link_libraries(gyvd PUBLIC ${GTK_LIBRARIES})
    add_definitions(${GTK_CFLAGS} ${GTK_CFLAGS_OTHER})
  endif()
endif()

add_custom_command(TARGET gyvd POST_BUID
                    COMMAND ${CMAKE_COMMAND} -E create_symlink 
                    ${CMAKE_SOURCE_DIR/glade ${cmake-biNARY_DIR}/bin/glade)
