#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "volk::volk" for configuration "Release"
set_property(TARGET volk::volk APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(volk::volk PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libvolk.a"
  )

list(APPEND _cmake_import_check_targets volk::volk )
list(APPEND _cmake_import_check_files_for_volk::volk "${_IMPORT_PREFIX}/lib/libvolk.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
