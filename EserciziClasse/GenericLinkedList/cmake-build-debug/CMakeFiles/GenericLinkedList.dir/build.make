# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/salvatorebramante/Programmazione1/EserciziClasse/GenericLinkedList

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/salvatorebramante/Programmazione1/EserciziClasse/GenericLinkedList/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GenericLinkedList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GenericLinkedList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GenericLinkedList.dir/flags.make

CMakeFiles/GenericLinkedList.dir/main.cpp.o: CMakeFiles/GenericLinkedList.dir/flags.make
CMakeFiles/GenericLinkedList.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/salvatorebramante/Programmazione1/EserciziClasse/GenericLinkedList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GenericLinkedList.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GenericLinkedList.dir/main.cpp.o -c /Users/salvatorebramante/Programmazione1/EserciziClasse/GenericLinkedList/main.cpp

CMakeFiles/GenericLinkedList.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GenericLinkedList.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/salvatorebramante/Programmazione1/EserciziClasse/GenericLinkedList/main.cpp > CMakeFiles/GenericLinkedList.dir/main.cpp.i

CMakeFiles/GenericLinkedList.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GenericLinkedList.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/salvatorebramante/Programmazione1/EserciziClasse/GenericLinkedList/main.cpp -o CMakeFiles/GenericLinkedList.dir/main.cpp.s

CMakeFiles/GenericLinkedList.dir/LinkedList.cpp.o: CMakeFiles/GenericLinkedList.dir/flags.make
CMakeFiles/GenericLinkedList.dir/LinkedList.cpp.o: ../LinkedList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/salvatorebramante/Programmazione1/EserciziClasse/GenericLinkedList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GenericLinkedList.dir/LinkedList.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GenericLinkedList.dir/LinkedList.cpp.o -c /Users/salvatorebramante/Programmazione1/EserciziClasse/GenericLinkedList/LinkedList.cpp

CMakeFiles/GenericLinkedList.dir/LinkedList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GenericLinkedList.dir/LinkedList.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/salvatorebramante/Programmazione1/EserciziClasse/GenericLinkedList/LinkedList.cpp > CMakeFiles/GenericLinkedList.dir/LinkedList.cpp.i

CMakeFiles/GenericLinkedList.dir/LinkedList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GenericLinkedList.dir/LinkedList.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/salvatorebramante/Programmazione1/EserciziClasse/GenericLinkedList/LinkedList.cpp -o CMakeFiles/GenericLinkedList.dir/LinkedList.cpp.s

# Object files for target GenericLinkedList
GenericLinkedList_OBJECTS = \
"CMakeFiles/GenericLinkedList.dir/main.cpp.o" \
"CMakeFiles/GenericLinkedList.dir/LinkedList.cpp.o"

# External object files for target GenericLinkedList
GenericLinkedList_EXTERNAL_OBJECTS =

GenericLinkedList: CMakeFiles/GenericLinkedList.dir/main.cpp.o
GenericLinkedList: CMakeFiles/GenericLinkedList.dir/LinkedList.cpp.o
GenericLinkedList: CMakeFiles/GenericLinkedList.dir/build.make
GenericLinkedList: CMakeFiles/GenericLinkedList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/salvatorebramante/Programmazione1/EserciziClasse/GenericLinkedList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable GenericLinkedList"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GenericLinkedList.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GenericLinkedList.dir/build: GenericLinkedList

.PHONY : CMakeFiles/GenericLinkedList.dir/build

CMakeFiles/GenericLinkedList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GenericLinkedList.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GenericLinkedList.dir/clean

CMakeFiles/GenericLinkedList.dir/depend:
	cd /Users/salvatorebramante/Programmazione1/EserciziClasse/GenericLinkedList/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/salvatorebramante/Programmazione1/EserciziClasse/GenericLinkedList /Users/salvatorebramante/Programmazione1/EserciziClasse/GenericLinkedList /Users/salvatorebramante/Programmazione1/EserciziClasse/GenericLinkedList/cmake-build-debug /Users/salvatorebramante/Programmazione1/EserciziClasse/GenericLinkedList/cmake-build-debug /Users/salvatorebramante/Programmazione1/EserciziClasse/GenericLinkedList/cmake-build-debug/CMakeFiles/GenericLinkedList.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GenericLinkedList.dir/depend

