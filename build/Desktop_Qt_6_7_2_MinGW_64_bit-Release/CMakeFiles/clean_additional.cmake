# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "AltromonLauncher_autogen"
  "CMakeFiles\\AltromonLauncher_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\AltromonLauncher_autogen.dir\\ParseCache.txt"
  )
endif()
