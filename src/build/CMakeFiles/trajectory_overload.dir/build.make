# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\dev\ballistic-calculate\src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\dev\ballistic-calculate\src\build

# Include any dependencies generated for this target.
include CMakeFiles/trajectory_overload.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/trajectory_overload.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/trajectory_overload.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/trajectory_overload.dir/flags.make

CMakeFiles/trajectory_overload.dir/trajectory_overload/main.c.obj: CMakeFiles/trajectory_overload.dir/flags.make
CMakeFiles/trajectory_overload.dir/trajectory_overload/main.c.obj: CMakeFiles/trajectory_overload.dir/includes_C.rsp
CMakeFiles/trajectory_overload.dir/trajectory_overload/main.c.obj: D:/dev/ballistic-calculate/src/trajectory_overload/main.c
CMakeFiles/trajectory_overload.dir/trajectory_overload/main.c.obj: CMakeFiles/trajectory_overload.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\dev\ballistic-calculate\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/trajectory_overload.dir/trajectory_overload/main.c.obj"
	D:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/trajectory_overload.dir/trajectory_overload/main.c.obj -MF CMakeFiles\trajectory_overload.dir\trajectory_overload\main.c.obj.d -o CMakeFiles\trajectory_overload.dir\trajectory_overload\main.c.obj -c D:\dev\ballistic-calculate\src\trajectory_overload\main.c

CMakeFiles/trajectory_overload.dir/trajectory_overload/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/trajectory_overload.dir/trajectory_overload/main.c.i"
	D:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\dev\ballistic-calculate\src\trajectory_overload\main.c > CMakeFiles\trajectory_overload.dir\trajectory_overload\main.c.i

CMakeFiles/trajectory_overload.dir/trajectory_overload/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/trajectory_overload.dir/trajectory_overload/main.c.s"
	D:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\dev\ballistic-calculate\src\trajectory_overload\main.c -o CMakeFiles\trajectory_overload.dir\trajectory_overload\main.c.s

CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/algorithm/algorithm.c.obj: CMakeFiles/trajectory_overload.dir/flags.make
CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/algorithm/algorithm.c.obj: CMakeFiles/trajectory_overload.dir/includes_C.rsp
CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/algorithm/algorithm.c.obj: D:/dev/ballistic-calculate/components/algorithm/algorithm.c
CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/algorithm/algorithm.c.obj: CMakeFiles/trajectory_overload.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\dev\ballistic-calculate\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/algorithm/algorithm.c.obj"
	D:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/algorithm/algorithm.c.obj -MF CMakeFiles\trajectory_overload.dir\D_\dev\ballistic-calculate\components\algorithm\algorithm.c.obj.d -o CMakeFiles\trajectory_overload.dir\D_\dev\ballistic-calculate\components\algorithm\algorithm.c.obj -c D:\dev\ballistic-calculate\components\algorithm\algorithm.c

CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/algorithm/algorithm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/algorithm/algorithm.c.i"
	D:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\dev\ballistic-calculate\components\algorithm\algorithm.c > CMakeFiles\trajectory_overload.dir\D_\dev\ballistic-calculate\components\algorithm\algorithm.c.i

CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/algorithm/algorithm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/algorithm/algorithm.c.s"
	D:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\dev\ballistic-calculate\components\algorithm\algorithm.c -o CMakeFiles\trajectory_overload.dir\D_\dev\ballistic-calculate\components\algorithm\algorithm.c.s

CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/missile_trajectory/missile_trajectory.c.obj: CMakeFiles/trajectory_overload.dir/flags.make
CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/missile_trajectory/missile_trajectory.c.obj: CMakeFiles/trajectory_overload.dir/includes_C.rsp
CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/missile_trajectory/missile_trajectory.c.obj: D:/dev/ballistic-calculate/components/calculate/missile_trajectory/missile_trajectory.c
CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/missile_trajectory/missile_trajectory.c.obj: CMakeFiles/trajectory_overload.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\dev\ballistic-calculate\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/missile_trajectory/missile_trajectory.c.obj"
	D:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/missile_trajectory/missile_trajectory.c.obj -MF CMakeFiles\trajectory_overload.dir\D_\dev\ballistic-calculate\components\calculate\missile_trajectory\missile_trajectory.c.obj.d -o CMakeFiles\trajectory_overload.dir\D_\dev\ballistic-calculate\components\calculate\missile_trajectory\missile_trajectory.c.obj -c D:\dev\ballistic-calculate\components\calculate\missile_trajectory\missile_trajectory.c

CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/missile_trajectory/missile_trajectory.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/missile_trajectory/missile_trajectory.c.i"
	D:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\dev\ballistic-calculate\components\calculate\missile_trajectory\missile_trajectory.c > CMakeFiles\trajectory_overload.dir\D_\dev\ballistic-calculate\components\calculate\missile_trajectory\missile_trajectory.c.i

CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/missile_trajectory/missile_trajectory.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/missile_trajectory/missile_trajectory.c.s"
	D:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\dev\ballistic-calculate\components\calculate\missile_trajectory\missile_trajectory.c -o CMakeFiles\trajectory_overload.dir\D_\dev\ballistic-calculate\components\calculate\missile_trajectory\missile_trajectory.c.s

CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/strategy_trajectory/strategy_trajectory.c.obj: CMakeFiles/trajectory_overload.dir/flags.make
CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/strategy_trajectory/strategy_trajectory.c.obj: CMakeFiles/trajectory_overload.dir/includes_C.rsp
CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/strategy_trajectory/strategy_trajectory.c.obj: D:/dev/ballistic-calculate/components/calculate/strategy_trajectory/strategy_trajectory.c
CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/strategy_trajectory/strategy_trajectory.c.obj: CMakeFiles/trajectory_overload.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\dev\ballistic-calculate\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/strategy_trajectory/strategy_trajectory.c.obj"
	D:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/strategy_trajectory/strategy_trajectory.c.obj -MF CMakeFiles\trajectory_overload.dir\D_\dev\ballistic-calculate\components\calculate\strategy_trajectory\strategy_trajectory.c.obj.d -o CMakeFiles\trajectory_overload.dir\D_\dev\ballistic-calculate\components\calculate\strategy_trajectory\strategy_trajectory.c.obj -c D:\dev\ballistic-calculate\components\calculate\strategy_trajectory\strategy_trajectory.c

CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/strategy_trajectory/strategy_trajectory.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/strategy_trajectory/strategy_trajectory.c.i"
	D:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\dev\ballistic-calculate\components\calculate\strategy_trajectory\strategy_trajectory.c > CMakeFiles\trajectory_overload.dir\D_\dev\ballistic-calculate\components\calculate\strategy_trajectory\strategy_trajectory.c.i

CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/strategy_trajectory/strategy_trajectory.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/strategy_trajectory/strategy_trajectory.c.s"
	D:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\dev\ballistic-calculate\components\calculate\strategy_trajectory\strategy_trajectory.c -o CMakeFiles\trajectory_overload.dir\D_\dev\ballistic-calculate\components\calculate\strategy_trajectory\strategy_trajectory.c.s

CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/log/log.c.obj: CMakeFiles/trajectory_overload.dir/flags.make
CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/log/log.c.obj: CMakeFiles/trajectory_overload.dir/includes_C.rsp
CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/log/log.c.obj: D:/dev/ballistic-calculate/components/log/log.c
CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/log/log.c.obj: CMakeFiles/trajectory_overload.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\dev\ballistic-calculate\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/log/log.c.obj"
	D:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/log/log.c.obj -MF CMakeFiles\trajectory_overload.dir\D_\dev\ballistic-calculate\components\log\log.c.obj.d -o CMakeFiles\trajectory_overload.dir\D_\dev\ballistic-calculate\components\log\log.c.obj -c D:\dev\ballistic-calculate\components\log\log.c

CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/log/log.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/log/log.c.i"
	D:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\dev\ballistic-calculate\components\log\log.c > CMakeFiles\trajectory_overload.dir\D_\dev\ballistic-calculate\components\log\log.c.i

CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/log/log.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/log/log.c.s"
	D:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\dev\ballistic-calculate\components\log\log.c -o CMakeFiles\trajectory_overload.dir\D_\dev\ballistic-calculate\components\log\log.c.s

# Object files for target trajectory_overload
trajectory_overload_OBJECTS = \
"CMakeFiles/trajectory_overload.dir/trajectory_overload/main.c.obj" \
"CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/algorithm/algorithm.c.obj" \
"CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/missile_trajectory/missile_trajectory.c.obj" \
"CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/strategy_trajectory/strategy_trajectory.c.obj" \
"CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/log/log.c.obj"

# External object files for target trajectory_overload
trajectory_overload_EXTERNAL_OBJECTS =

trajectory_overload.exe: CMakeFiles/trajectory_overload.dir/trajectory_overload/main.c.obj
trajectory_overload.exe: CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/algorithm/algorithm.c.obj
trajectory_overload.exe: CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/missile_trajectory/missile_trajectory.c.obj
trajectory_overload.exe: CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/calculate/strategy_trajectory/strategy_trajectory.c.obj
trajectory_overload.exe: CMakeFiles/trajectory_overload.dir/D_/dev/ballistic-calculate/components/log/log.c.obj
trajectory_overload.exe: CMakeFiles/trajectory_overload.dir/build.make
trajectory_overload.exe: CMakeFiles/trajectory_overload.dir/linkLibs.rsp
trajectory_overload.exe: CMakeFiles/trajectory_overload.dir/objects1.rsp
trajectory_overload.exe: CMakeFiles/trajectory_overload.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\dev\ballistic-calculate\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable trajectory_overload.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\trajectory_overload.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/trajectory_overload.dir/build: trajectory_overload.exe
.PHONY : CMakeFiles/trajectory_overload.dir/build

CMakeFiles/trajectory_overload.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\trajectory_overload.dir\cmake_clean.cmake
.PHONY : CMakeFiles/trajectory_overload.dir/clean

CMakeFiles/trajectory_overload.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\dev\ballistic-calculate\src D:\dev\ballistic-calculate\src D:\dev\ballistic-calculate\src\build D:\dev\ballistic-calculate\src\build D:\dev\ballistic-calculate\src\build\CMakeFiles\trajectory_overload.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/trajectory_overload.dir/depend

