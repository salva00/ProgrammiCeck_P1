# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/salvatorebramante/CLionProjects/ProgrammiCeck_P1/EserciziClasse/LinkedList

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/salvatorebramante/CLionProjects/ProgrammiCeck_P1/EserciziClasse/LinkedList/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LinkedList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LinkedList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LinkedList.dir/flags.make

CMakeFiles/LinkedList.dir/main.cpp.o: CMakeFiles/LinkedList.dir/flags.make
CMakeFiles/LinkedList.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/salvatorebramante/CLionProjects/ProgrammiCeck_P1/EserciziClasse/LinkedList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LinkedList.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LinkedList.dir/main.cpp.o -c /Users/salvatorebramante/CLionProjects/ProgrammiCeck_P1/EserciziClasse/LinkedList/main.cpp

CMakeFiles/LinkedList.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LinkedList.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/salvatorebramante/CLionProjects/ProgrammiCeck_P1/EserciziClasse/LinkedList/main.cpp > CMakeFiles/LinkedList.dir/main.cpp.i

CMakeFiles/LinkedList.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LinkedList.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/salvatorebramante/CLionProjects/ProgrammiCeck_P1/EserciziClasse/LinkedList/main.cpp -o CMakeFiles/LinkedList.dir/main.cpp.s

CMakeFiles/LinkedList.dir/StringNode.cpp.o: CMakeFiles/LinkedList.dir/flags.make
CMakeFiles/LinkedList.dir/StringNode.cpp.o: ../StringNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/salvatorebramante/CLionProjects/ProgrammiCeck_P1/EserciziClasse/LinkedList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LinkedList.dir/StringNode.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LinkedList.dir/StringNode.cpp.o -c /Users/salvatorebramante/CLionProjects/ProgrammiCeck_P1/EserciziClasse/LinkedList/StringNode.cpp

CMakeFiles/LinkedList.dir/StringNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LinkedList.dir/StringNode.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/salvatorebramante/CLionProjects/ProgrammiCeck_P1/EserciziClasse/LinkedList/StringNode.cpp > CMakeFiles/LinkedList.dir/StringNode.cpp.i

CMakeFiles/LinkedList.dir/StringNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LinkedList.dir/StringNode.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/salvatorebramante/CLionProjects/ProgrammiCeck_P1/EserciziClasse/LinkedList/StringNode.cpp -o CMakeFiles/LinkedList.dir/StringNode.cpp.s

CMakeFiles/LinkedList.dir/StringLinkedList.cpp.o: CMakeFiles/LinkedList.dir/flags.make
CMakeFiles/LinkedList.dir/StringLinkedList.cpp.o: ../StringLinkedList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/salvatorebramante/CLionProjects/ProgrammiCeck_P1/EserciziClasse/LinkedList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/LinkedList.dir/StringLinkedList.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LinkedList.dir/StringLinkedList.cpp.o -c /Users/salvatorebramante/CLionProjects/ProgrammiCeck_P1/EserciziClasse/LinkedList/StringLinkedList.cpp

CMakeFiles/LinkedList.dir/StringLinkedList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LinkedList.dir/StringLinkedList.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/salvatorebramante/CLionProjects/ProgrammiCeck_P1/EserciziClasse/LinkedList/StringLinkedList.cpp > CMakeFiles/LinkedList.dir/StringLinkedList.cpp.i

CMakeFiles/LinkedList.dir/StringLinkedList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LinkedList.dir/StringLinkedList.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/salvatorebramante/CLionProjects/ProgrammiCeck_P1/EserciziClasse/LinkedList/StringLinkedList.cpp -o CMakeFiles/LinkedList.dir/StringLinkedList.cpp.s

# Object files for target LinkedList
LinkedList_OBJECTS = \
"CMakeFiles/LinkedList.dir/main.cpp.o" \
"CMakeFiles/LinkedList.dir/StringNode.cpp.o" \
"CMakeFiles/LinkedList.dir/StringLinkedList.cpp.o"

# External object files for target LinkedList
LinkedList_EXTERNAL_OBJECTS =

LinkedList: CMakeFiles/LinkedList.dir/main.cpp.o
LinkedList: CMakeFiles/LinkedList.dir/StringNode.cpp.o
LinkedList: CMakeFiles/LinkedList.dir/StringLinkedList.cpp.o
LinkedList: CMakeFiles/LinkedList.dir/build.make
LinkedList: CMakeFiles/LinkedList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/salvatorebramante/CLionProjects/ProgrammiCeck_P1/EserciziClasse/LinkedList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable LinkedList"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LinkedList.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LinkedList.dir/build: LinkedList

.PHONY : CMakeFiles/LinkedList.dir/build

CMakeFiles/LinkedList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LinkedList.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LinkedList.dir/clean

CMakeFiles/LinkedList.dir/depend:
	cd /Users/salvatorebramante/CLionProjects/ProgrammiCeck_P1/EserciziClasse/LinkedList/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/salvatorebramante/CLionProjects/ProgrammiCeck_P1/EserciziClasse/LinkedList /Users/salvatorebramante/CLionProjects/ProgrammiCeck_P1/EserciziClasse/LinkedList /Users/salvatorebramante/CLionProjects/ProgrammiCeck_P1/EserciziClasse/LinkedList/cmake-build-debug /Users/salvatorebramante/CLionProjects/ProgrammiCeck_P1/EserciziClasse/LinkedList/cmake-build-debug /Users/salvatorebramante/CLionProjects/ProgrammiCeck_P1/EserciziClasse/LinkedList/cmake-build-debug/CMakeFiles/LinkedList.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LinkedList.dir/depend

