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
CMAKE_SOURCE_DIR = /home/lilianbestial/Documents/VScode/Challenge48h/Jeu-CPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lilianbestial/Documents/VScode/Challenge48h/Jeu-CPP

# Utility rule file for obj.

# Include any custom commands dependencies for this target.
include CMakeFiles/obj.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/obj.dir/progress.make

CMakeFiles/obj: obj/affichage.o
CMakeFiles/obj: obj/main.o

obj/affichage.o: src/affichage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/lilianbestial/Documents/VScode/Challenge48h/Jeu-CPP/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building /home/lilianbestial/Documents/VScode/Challenge48h/Jeu-CPP/obj/affichage.o"
	/usr/bin/cmake -E make_directory /home/lilianbestial/Documents/VScode/Challenge48h/Jeu-CPP/obj
	/usr/bin/c++ -c -o /home/lilianbestial/Documents/VScode/Challenge48h/Jeu-CPP/obj/affichage.o /home/lilianbestial/Documents/VScode/Challenge48h/Jeu-CPP/src/affichage.cpp

obj/main.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/lilianbestial/Documents/VScode/Challenge48h/Jeu-CPP/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building /home/lilianbestial/Documents/VScode/Challenge48h/Jeu-CPP/obj/main.o"
	/usr/bin/cmake -E make_directory /home/lilianbestial/Documents/VScode/Challenge48h/Jeu-CPP/obj
	/usr/bin/c++ -c -o /home/lilianbestial/Documents/VScode/Challenge48h/Jeu-CPP/obj/main.o /home/lilianbestial/Documents/VScode/Challenge48h/Jeu-CPP/src/main.cpp

obj: CMakeFiles/obj
obj: obj/affichage.o
obj: obj/main.o
obj: CMakeFiles/obj.dir/build.make
.PHONY : obj

# Rule to build all files generated by this target.
CMakeFiles/obj.dir/build: obj
.PHONY : CMakeFiles/obj.dir/build

CMakeFiles/obj.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/obj.dir/cmake_clean.cmake
.PHONY : CMakeFiles/obj.dir/clean

CMakeFiles/obj.dir/depend:
	cd /home/lilianbestial/Documents/VScode/Challenge48h/Jeu-CPP && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lilianbestial/Documents/VScode/Challenge48h/Jeu-CPP /home/lilianbestial/Documents/VScode/Challenge48h/Jeu-CPP /home/lilianbestial/Documents/VScode/Challenge48h/Jeu-CPP /home/lilianbestial/Documents/VScode/Challenge48h/Jeu-CPP /home/lilianbestial/Documents/VScode/Challenge48h/Jeu-CPP/CMakeFiles/obj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/obj.dir/depend

