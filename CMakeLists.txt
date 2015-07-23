project("Bite The Beat")
set(EXECUTABLE_OUTPUT_PATH build)

include_directories(${sfml_include_dir})

link_directories(${sfml_graphics_lib_dir})
link_directories(${sfml_window_lib_dir})
link_directories(${sfml_system_lib_dir})

file(GLOB_RECURSE source_files src/*)

#message(${source_files})

add_executable(BTB ${source_files})

add_definitions(-std=c++11)

target_link_libraries(BTB -lsfml-graphics -lsfml-window -lsfml-system)

