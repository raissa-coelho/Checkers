# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/checkers.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/checkers.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/checkers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/checkers.dir/flags.make

CMakeFiles/checkers.dir/main.c.o: CMakeFiles/checkers.dir/flags.make
CMakeFiles/checkers.dir/main.c.o: ../main.c
CMakeFiles/checkers.dir/main.c.o: CMakeFiles/checkers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/checkers.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/checkers.dir/main.c.o -MF CMakeFiles/checkers.dir/main.c.o.d -o CMakeFiles/checkers.dir/main.c.o -c "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/main.c"

CMakeFiles/checkers.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/checkers.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/main.c" > CMakeFiles/checkers.dir/main.c.i

CMakeFiles/checkers.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/checkers.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/main.c" -o CMakeFiles/checkers.dir/main.c.s

CMakeFiles/checkers.dir/checkers.c.o: CMakeFiles/checkers.dir/flags.make
CMakeFiles/checkers.dir/checkers.c.o: ../checkers.c
CMakeFiles/checkers.dir/checkers.c.o: CMakeFiles/checkers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/checkers.dir/checkers.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/checkers.dir/checkers.c.o -MF CMakeFiles/checkers.dir/checkers.c.o.d -o CMakeFiles/checkers.dir/checkers.c.o -c "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/checkers.c"

CMakeFiles/checkers.dir/checkers.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/checkers.dir/checkers.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/checkers.c" > CMakeFiles/checkers.dir/checkers.c.i

CMakeFiles/checkers.dir/checkers.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/checkers.dir/checkers.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/checkers.c" -o CMakeFiles/checkers.dir/checkers.c.s

CMakeFiles/checkers.dir/player.c.o: CMakeFiles/checkers.dir/flags.make
CMakeFiles/checkers.dir/player.c.o: ../player.c
CMakeFiles/checkers.dir/player.c.o: CMakeFiles/checkers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/checkers.dir/player.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/checkers.dir/player.c.o -MF CMakeFiles/checkers.dir/player.c.o.d -o CMakeFiles/checkers.dir/player.c.o -c "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/player.c"

CMakeFiles/checkers.dir/player.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/checkers.dir/player.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/player.c" > CMakeFiles/checkers.dir/player.c.i

CMakeFiles/checkers.dir/player.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/checkers.dir/player.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/player.c" -o CMakeFiles/checkers.dir/player.c.s

CMakeFiles/checkers.dir/input.c.o: CMakeFiles/checkers.dir/flags.make
CMakeFiles/checkers.dir/input.c.o: ../input.c
CMakeFiles/checkers.dir/input.c.o: CMakeFiles/checkers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/checkers.dir/input.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/checkers.dir/input.c.o -MF CMakeFiles/checkers.dir/input.c.o.d -o CMakeFiles/checkers.dir/input.c.o -c "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/input.c"

CMakeFiles/checkers.dir/input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/checkers.dir/input.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/input.c" > CMakeFiles/checkers.dir/input.c.i

CMakeFiles/checkers.dir/input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/checkers.dir/input.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/input.c" -o CMakeFiles/checkers.dir/input.c.s

CMakeFiles/checkers.dir/gamestate.c.o: CMakeFiles/checkers.dir/flags.make
CMakeFiles/checkers.dir/gamestate.c.o: ../gamestate.c
CMakeFiles/checkers.dir/gamestate.c.o: CMakeFiles/checkers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/checkers.dir/gamestate.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/checkers.dir/gamestate.c.o -MF CMakeFiles/checkers.dir/gamestate.c.o.d -o CMakeFiles/checkers.dir/gamestate.c.o -c "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/gamestate.c"

CMakeFiles/checkers.dir/gamestate.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/checkers.dir/gamestate.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/gamestate.c" > CMakeFiles/checkers.dir/gamestate.c.i

CMakeFiles/checkers.dir/gamestate.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/checkers.dir/gamestate.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/gamestate.c" -o CMakeFiles/checkers.dir/gamestate.c.s

# Object files for target checkers
checkers_OBJECTS = \
"CMakeFiles/checkers.dir/main.c.o" \
"CMakeFiles/checkers.dir/checkers.c.o" \
"CMakeFiles/checkers.dir/player.c.o" \
"CMakeFiles/checkers.dir/input.c.o" \
"CMakeFiles/checkers.dir/gamestate.c.o"

# External object files for target checkers
checkers_EXTERNAL_OBJECTS =

checkers: CMakeFiles/checkers.dir/main.c.o
checkers: CMakeFiles/checkers.dir/checkers.c.o
checkers: CMakeFiles/checkers.dir/player.c.o
checkers: CMakeFiles/checkers.dir/input.c.o
checkers: CMakeFiles/checkers.dir/gamestate.c.o
checkers: CMakeFiles/checkers.dir/build.make
checkers: /usr/lib/x86_64-linux-gnu/libOpenGL.so
checkers: /usr/lib/x86_64-linux-gnu/libGLX.so
checkers: /usr/lib/x86_64-linux-gnu/libGLU.so
checkers: /usr/lib/x86_64-linux-gnu/libglut.so
checkers: /usr/lib/x86_64-linux-gnu/libXi.so
checkers: /usr/lib/gcc/x86_64-linux-gnu/11/libgomp.so
checkers: /usr/lib/x86_64-linux-gnu/libpthread.a
checkers: CMakeFiles/checkers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable checkers"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/checkers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/checkers.dir/build: checkers
.PHONY : CMakeFiles/checkers.dir/build

CMakeFiles/checkers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/checkers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/checkers.dir/clean

CMakeFiles/checkers.dir/depend:
	cd "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers" "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers" "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/cmake-build-debug" "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/cmake-build-debug" "/mnt/c/Users/Matheus S. Menezes/Documents/Projetos/checkers/cmake-build-debug/CMakeFiles/checkers.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/checkers.dir/depend

