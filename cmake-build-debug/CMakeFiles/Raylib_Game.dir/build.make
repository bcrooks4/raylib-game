# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Bill\CLionProjects\Raylib Game"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Bill\CLionProjects\Raylib Game\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\Raylib_Game.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Raylib_Game.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Raylib_Game.dir\flags.make

CMakeFiles\Raylib_Game.dir\main.c.obj: CMakeFiles\Raylib_Game.dir\flags.make
CMakeFiles\Raylib_Game.dir\main.c.obj: ..\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Bill\CLionProjects\Raylib Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Raylib_Game.dir/main.c.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Raylib_Game.dir\main.c.obj /FdCMakeFiles\Raylib_Game.dir\ /FS -c "C:\Users\Bill\CLionProjects\Raylib Game\main.c"
<<

CMakeFiles\Raylib_Game.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Raylib_Game.dir/main.c.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe > CMakeFiles\Raylib_Game.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Bill\CLionProjects\Raylib Game\main.c"
<<

CMakeFiles\Raylib_Game.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Raylib_Game.dir/main.c.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Raylib_Game.dir\main.c.s /c "C:\Users\Bill\CLionProjects\Raylib Game\main.c"
<<

CMakeFiles\Raylib_Game.dir\Engine\SceneManager.c.obj: CMakeFiles\Raylib_Game.dir\flags.make
CMakeFiles\Raylib_Game.dir\Engine\SceneManager.c.obj: ..\Engine\SceneManager.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Bill\CLionProjects\Raylib Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Raylib_Game.dir/Engine/SceneManager.c.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Raylib_Game.dir\Engine\SceneManager.c.obj /FdCMakeFiles\Raylib_Game.dir\ /FS -c "C:\Users\Bill\CLionProjects\Raylib Game\Engine\SceneManager.c"
<<

CMakeFiles\Raylib_Game.dir\Engine\SceneManager.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Raylib_Game.dir/Engine/SceneManager.c.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe > CMakeFiles\Raylib_Game.dir\Engine\SceneManager.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Bill\CLionProjects\Raylib Game\Engine\SceneManager.c"
<<

CMakeFiles\Raylib_Game.dir\Engine\SceneManager.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Raylib_Game.dir/Engine/SceneManager.c.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Raylib_Game.dir\Engine\SceneManager.c.s /c "C:\Users\Bill\CLionProjects\Raylib Game\Engine\SceneManager.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_SplashScreen.c.obj: CMakeFiles\Raylib_Game.dir\flags.make
CMakeFiles\Raylib_Game.dir\Scenes\SCENE_SplashScreen.c.obj: ..\Scenes\SCENE_SplashScreen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Bill\CLionProjects\Raylib Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Raylib_Game.dir/Scenes/SCENE_SplashScreen.c.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Raylib_Game.dir\Scenes\SCENE_SplashScreen.c.obj /FdCMakeFiles\Raylib_Game.dir\ /FS -c "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_SplashScreen.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_SplashScreen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Raylib_Game.dir/Scenes/SCENE_SplashScreen.c.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe > CMakeFiles\Raylib_Game.dir\Scenes\SCENE_SplashScreen.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_SplashScreen.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_SplashScreen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Raylib_Game.dir/Scenes/SCENE_SplashScreen.c.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Raylib_Game.dir\Scenes\SCENE_SplashScreen.c.s /c "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_SplashScreen.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_MainMenu.c.obj: CMakeFiles\Raylib_Game.dir\flags.make
CMakeFiles\Raylib_Game.dir\Scenes\SCENE_MainMenu.c.obj: ..\Scenes\SCENE_MainMenu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Bill\CLionProjects\Raylib Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Raylib_Game.dir/Scenes/SCENE_MainMenu.c.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Raylib_Game.dir\Scenes\SCENE_MainMenu.c.obj /FdCMakeFiles\Raylib_Game.dir\ /FS -c "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_MainMenu.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_MainMenu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Raylib_Game.dir/Scenes/SCENE_MainMenu.c.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe > CMakeFiles\Raylib_Game.dir\Scenes\SCENE_MainMenu.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_MainMenu.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_MainMenu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Raylib_Game.dir/Scenes/SCENE_MainMenu.c.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Raylib_Game.dir\Scenes\SCENE_MainMenu.c.s /c "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_MainMenu.c"
<<

CMakeFiles\Raylib_Game.dir\Engine\Engine.c.obj: CMakeFiles\Raylib_Game.dir\flags.make
CMakeFiles\Raylib_Game.dir\Engine\Engine.c.obj: ..\Engine\Engine.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Bill\CLionProjects\Raylib Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Raylib_Game.dir/Engine/Engine.c.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Raylib_Game.dir\Engine\Engine.c.obj /FdCMakeFiles\Raylib_Game.dir\ /FS -c "C:\Users\Bill\CLionProjects\Raylib Game\Engine\Engine.c"
<<

CMakeFiles\Raylib_Game.dir\Engine\Engine.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Raylib_Game.dir/Engine/Engine.c.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe > CMakeFiles\Raylib_Game.dir\Engine\Engine.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Bill\CLionProjects\Raylib Game\Engine\Engine.c"
<<

CMakeFiles\Raylib_Game.dir\Engine\Engine.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Raylib_Game.dir/Engine/Engine.c.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Raylib_Game.dir\Engine\Engine.c.s /c "C:\Users\Bill\CLionProjects\Raylib Game\Engine\Engine.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_Credits.c.obj: CMakeFiles\Raylib_Game.dir\flags.make
CMakeFiles\Raylib_Game.dir\Scenes\SCENE_Credits.c.obj: ..\Scenes\SCENE_Credits.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Bill\CLionProjects\Raylib Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Raylib_Game.dir/Scenes/SCENE_Credits.c.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Raylib_Game.dir\Scenes\SCENE_Credits.c.obj /FdCMakeFiles\Raylib_Game.dir\ /FS -c "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_Credits.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_Credits.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Raylib_Game.dir/Scenes/SCENE_Credits.c.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe > CMakeFiles\Raylib_Game.dir\Scenes\SCENE_Credits.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_Credits.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_Credits.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Raylib_Game.dir/Scenes/SCENE_Credits.c.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Raylib_Game.dir\Scenes\SCENE_Credits.c.s /c "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_Credits.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldPainter.c.obj: CMakeFiles\Raylib_Game.dir\flags.make
CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldPainter.c.obj: ..\Scenes\SCENE_WorldPainter.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Bill\CLionProjects\Raylib Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/Raylib_Game.dir/Scenes/SCENE_WorldPainter.c.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldPainter.c.obj /FdCMakeFiles\Raylib_Game.dir\ /FS -c "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_WorldPainter.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldPainter.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Raylib_Game.dir/Scenes/SCENE_WorldPainter.c.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe > CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldPainter.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_WorldPainter.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldPainter.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Raylib_Game.dir/Scenes/SCENE_WorldPainter.c.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldPainter.c.s /c "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_WorldPainter.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_MapViewer.c.obj: CMakeFiles\Raylib_Game.dir\flags.make
CMakeFiles\Raylib_Game.dir\Scenes\SCENE_MapViewer.c.obj: ..\Scenes\SCENE_MapViewer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Bill\CLionProjects\Raylib Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/Raylib_Game.dir/Scenes/SCENE_MapViewer.c.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Raylib_Game.dir\Scenes\SCENE_MapViewer.c.obj /FdCMakeFiles\Raylib_Game.dir\ /FS -c "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_MapViewer.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_MapViewer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Raylib_Game.dir/Scenes/SCENE_MapViewer.c.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe > CMakeFiles\Raylib_Game.dir\Scenes\SCENE_MapViewer.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_MapViewer.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_MapViewer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Raylib_Game.dir/Scenes/SCENE_MapViewer.c.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Raylib_Game.dir\Scenes\SCENE_MapViewer.c.s /c "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_MapViewer.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_NewWorldMenu.c.obj: CMakeFiles\Raylib_Game.dir\flags.make
CMakeFiles\Raylib_Game.dir\Scenes\SCENE_NewWorldMenu.c.obj: ..\Scenes\SCENE_NewWorldMenu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Bill\CLionProjects\Raylib Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/Raylib_Game.dir/Scenes/SCENE_NewWorldMenu.c.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Raylib_Game.dir\Scenes\SCENE_NewWorldMenu.c.obj /FdCMakeFiles\Raylib_Game.dir\ /FS -c "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_NewWorldMenu.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_NewWorldMenu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Raylib_Game.dir/Scenes/SCENE_NewWorldMenu.c.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe > CMakeFiles\Raylib_Game.dir\Scenes\SCENE_NewWorldMenu.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_NewWorldMenu.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_NewWorldMenu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Raylib_Game.dir/Scenes/SCENE_NewWorldMenu.c.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Raylib_Game.dir\Scenes\SCENE_NewWorldMenu.c.s /c "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_NewWorldMenu.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldPainterMenu.c.obj: CMakeFiles\Raylib_Game.dir\flags.make
CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldPainterMenu.c.obj: ..\Scenes\SCENE_WorldPainterMenu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Bill\CLionProjects\Raylib Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/Raylib_Game.dir/Scenes/SCENE_WorldPainterMenu.c.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldPainterMenu.c.obj /FdCMakeFiles\Raylib_Game.dir\ /FS -c "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_WorldPainterMenu.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldPainterMenu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Raylib_Game.dir/Scenes/SCENE_WorldPainterMenu.c.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe > CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldPainterMenu.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_WorldPainterMenu.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldPainterMenu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Raylib_Game.dir/Scenes/SCENE_WorldPainterMenu.c.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldPainterMenu.c.s /c "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_WorldPainterMenu.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_ProceduralWorldMenu.c.obj: CMakeFiles\Raylib_Game.dir\flags.make
CMakeFiles\Raylib_Game.dir\Scenes\SCENE_ProceduralWorldMenu.c.obj: ..\Scenes\SCENE_ProceduralWorldMenu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Bill\CLionProjects\Raylib Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/Raylib_Game.dir/Scenes/SCENE_ProceduralWorldMenu.c.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Raylib_Game.dir\Scenes\SCENE_ProceduralWorldMenu.c.obj /FdCMakeFiles\Raylib_Game.dir\ /FS -c "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_ProceduralWorldMenu.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_ProceduralWorldMenu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Raylib_Game.dir/Scenes/SCENE_ProceduralWorldMenu.c.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe > CMakeFiles\Raylib_Game.dir\Scenes\SCENE_ProceduralWorldMenu.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_ProceduralWorldMenu.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_ProceduralWorldMenu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Raylib_Game.dir/Scenes/SCENE_ProceduralWorldMenu.c.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Raylib_Game.dir\Scenes\SCENE_ProceduralWorldMenu.c.s /c "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_ProceduralWorldMenu.c"
<<

CMakeFiles\Raylib_Game.dir\Utility\ProceduralGeneration.c.obj: CMakeFiles\Raylib_Game.dir\flags.make
CMakeFiles\Raylib_Game.dir\Utility\ProceduralGeneration.c.obj: ..\Utility\ProceduralGeneration.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Bill\CLionProjects\Raylib Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/Raylib_Game.dir/Utility/ProceduralGeneration.c.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Raylib_Game.dir\Utility\ProceduralGeneration.c.obj /FdCMakeFiles\Raylib_Game.dir\ /FS -c "C:\Users\Bill\CLionProjects\Raylib Game\Utility\ProceduralGeneration.c"
<<

CMakeFiles\Raylib_Game.dir\Utility\ProceduralGeneration.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Raylib_Game.dir/Utility/ProceduralGeneration.c.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe > CMakeFiles\Raylib_Game.dir\Utility\ProceduralGeneration.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Bill\CLionProjects\Raylib Game\Utility\ProceduralGeneration.c"
<<

CMakeFiles\Raylib_Game.dir\Utility\ProceduralGeneration.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Raylib_Game.dir/Utility/ProceduralGeneration.c.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Raylib_Game.dir\Utility\ProceduralGeneration.c.s /c "C:\Users\Bill\CLionProjects\Raylib Game\Utility\ProceduralGeneration.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_BattleMap.c.obj: CMakeFiles\Raylib_Game.dir\flags.make
CMakeFiles\Raylib_Game.dir\Scenes\SCENE_BattleMap.c.obj: ..\Scenes\SCENE_BattleMap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Bill\CLionProjects\Raylib Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/Raylib_Game.dir/Scenes/SCENE_BattleMap.c.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Raylib_Game.dir\Scenes\SCENE_BattleMap.c.obj /FdCMakeFiles\Raylib_Game.dir\ /FS -c "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_BattleMap.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_BattleMap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Raylib_Game.dir/Scenes/SCENE_BattleMap.c.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe > CMakeFiles\Raylib_Game.dir\Scenes\SCENE_BattleMap.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_BattleMap.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_BattleMap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Raylib_Game.dir/Scenes/SCENE_BattleMap.c.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Raylib_Game.dir\Scenes\SCENE_BattleMap.c.s /c "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_BattleMap.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldCreation.c.obj: CMakeFiles\Raylib_Game.dir\flags.make
CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldCreation.c.obj: ..\Scenes\SCENE_WorldCreation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Bill\CLionProjects\Raylib Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/Raylib_Game.dir/Scenes/SCENE_WorldCreation.c.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldCreation.c.obj /FdCMakeFiles\Raylib_Game.dir\ /FS -c "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_WorldCreation.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldCreation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Raylib_Game.dir/Scenes/SCENE_WorldCreation.c.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe > CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldCreation.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_WorldCreation.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldCreation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Raylib_Game.dir/Scenes/SCENE_WorldCreation.c.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldCreation.c.s /c "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_WorldCreation.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldViewer.c.obj: CMakeFiles\Raylib_Game.dir\flags.make
CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldViewer.c.obj: ..\Scenes\SCENE_WorldViewer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Bill\CLionProjects\Raylib Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/Raylib_Game.dir/Scenes/SCENE_WorldViewer.c.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldViewer.c.obj /FdCMakeFiles\Raylib_Game.dir\ /FS -c "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_WorldViewer.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldViewer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Raylib_Game.dir/Scenes/SCENE_WorldViewer.c.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe > CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldViewer.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_WorldViewer.c"
<<

CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldViewer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Raylib_Game.dir/Scenes/SCENE_WorldViewer.c.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldViewer.c.s /c "C:\Users\Bill\CLionProjects\Raylib Game\Scenes\SCENE_WorldViewer.c"
<<

# Object files for target Raylib_Game
Raylib_Game_OBJECTS = \
"CMakeFiles\Raylib_Game.dir\main.c.obj" \
"CMakeFiles\Raylib_Game.dir\Engine\SceneManager.c.obj" \
"CMakeFiles\Raylib_Game.dir\Scenes\SCENE_SplashScreen.c.obj" \
"CMakeFiles\Raylib_Game.dir\Scenes\SCENE_MainMenu.c.obj" \
"CMakeFiles\Raylib_Game.dir\Engine\Engine.c.obj" \
"CMakeFiles\Raylib_Game.dir\Scenes\SCENE_Credits.c.obj" \
"CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldPainter.c.obj" \
"CMakeFiles\Raylib_Game.dir\Scenes\SCENE_MapViewer.c.obj" \
"CMakeFiles\Raylib_Game.dir\Scenes\SCENE_NewWorldMenu.c.obj" \
"CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldPainterMenu.c.obj" \
"CMakeFiles\Raylib_Game.dir\Scenes\SCENE_ProceduralWorldMenu.c.obj" \
"CMakeFiles\Raylib_Game.dir\Utility\ProceduralGeneration.c.obj" \
"CMakeFiles\Raylib_Game.dir\Scenes\SCENE_BattleMap.c.obj" \
"CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldCreation.c.obj" \
"CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldViewer.c.obj"

# External object files for target Raylib_Game
Raylib_Game_EXTERNAL_OBJECTS =

Raylib_Game.exe: CMakeFiles\Raylib_Game.dir\main.c.obj
Raylib_Game.exe: CMakeFiles\Raylib_Game.dir\Engine\SceneManager.c.obj
Raylib_Game.exe: CMakeFiles\Raylib_Game.dir\Scenes\SCENE_SplashScreen.c.obj
Raylib_Game.exe: CMakeFiles\Raylib_Game.dir\Scenes\SCENE_MainMenu.c.obj
Raylib_Game.exe: CMakeFiles\Raylib_Game.dir\Engine\Engine.c.obj
Raylib_Game.exe: CMakeFiles\Raylib_Game.dir\Scenes\SCENE_Credits.c.obj
Raylib_Game.exe: CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldPainter.c.obj
Raylib_Game.exe: CMakeFiles\Raylib_Game.dir\Scenes\SCENE_MapViewer.c.obj
Raylib_Game.exe: CMakeFiles\Raylib_Game.dir\Scenes\SCENE_NewWorldMenu.c.obj
Raylib_Game.exe: CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldPainterMenu.c.obj
Raylib_Game.exe: CMakeFiles\Raylib_Game.dir\Scenes\SCENE_ProceduralWorldMenu.c.obj
Raylib_Game.exe: CMakeFiles\Raylib_Game.dir\Utility\ProceduralGeneration.c.obj
Raylib_Game.exe: CMakeFiles\Raylib_Game.dir\Scenes\SCENE_BattleMap.c.obj
Raylib_Game.exe: CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldCreation.c.obj
Raylib_Game.exe: CMakeFiles\Raylib_Game.dir\Scenes\SCENE_WorldViewer.c.obj
Raylib_Game.exe: CMakeFiles\Raylib_Game.dir\build.make
Raylib_Game.exe: CMakeFiles\Raylib_Game.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Bill\CLionProjects\Raylib Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_16) "Linking C executable Raylib_Game.exe"
	"C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Raylib_Game.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x64\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x64\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\Raylib_Game.dir\objects1.rsp @<<
 /out:Raylib_Game.exe /implib:Raylib_Game.lib /pdb:"C:\Users\Bill\CLionProjects\Raylib Game\cmake-build-debug\Raylib_Game.pdb" /version:0.0  /machine:x64 /debug /INCREMENTAL /subsystem:console   -LIBPATH:C:\dev\vcpkg\installed\x64-windows\lib  raylib.lib lua.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<
	powershell -noprofile -executionpolicy Bypass -file C:/dev/vcpkg/scripts/buildsystems/msbuild/applocal.ps1 -targetBinary "C:/Users/Bill/CLionProjects/Raylib Game/cmake-build-debug/Raylib_Game.exe" -installedDir C:/dev/vcpkg/installed/x64-windows/debug/bin -OutVariable out

# Rule to build all files generated by this target.
CMakeFiles\Raylib_Game.dir\build: Raylib_Game.exe

.PHONY : CMakeFiles\Raylib_Game.dir\build

CMakeFiles\Raylib_Game.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Raylib_Game.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Raylib_Game.dir\clean

CMakeFiles\Raylib_Game.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\Bill\CLionProjects\Raylib Game" "C:\Users\Bill\CLionProjects\Raylib Game" "C:\Users\Bill\CLionProjects\Raylib Game\cmake-build-debug" "C:\Users\Bill\CLionProjects\Raylib Game\cmake-build-debug" "C:\Users\Bill\CLionProjects\Raylib Game\cmake-build-debug\CMakeFiles\Raylib_Game.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\Raylib_Game.dir\depend

