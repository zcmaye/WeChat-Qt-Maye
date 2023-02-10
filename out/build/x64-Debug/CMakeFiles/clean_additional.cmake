# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\WeChat_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\WeChat_autogen.dir\\ParseCache.txt"
  "WeChat_autogen"
  )
endif()
