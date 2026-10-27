cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

message(VERBOSE "Executing patch step for harfbuzz")

block(SCOPE_FOR VARIABLES)

execute_process(
  WORKING_DIRECTORY "C:/Codes/PROJECTS/windowed/build/_deps/harfbuzz-src"
  COMMAND_ERROR_IS_FATAL LAST
  COMMAND  [====[C:/Users/zakki/AppData/Local/Microsoft/WinGet/Packages/BrechtSanders.WinLibs.POSIX.UCRT_Microsoft.Winget.Source_8wekyb3d8bbwe/mingw64/bin/cmake.exe]====] [====[-DHARFBUZZ_DIR=C:/Codes/PROJECTS/windowed/build/_deps/harfbuzz-src]====] [====[-P]====] [====[C:/Codes/PROJECTS/windowed/build/_deps/sfml-src/tools/harfbuzz/PatchHarfBuzz.cmake]====]
)

endblock()
