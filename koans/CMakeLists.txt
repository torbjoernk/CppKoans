# koans/CMakeList.txt

set(cppkoans_SOURCES
  ${cppkoans_SOURCES}
  ${PROJECT_SOURCE_DIR}/koans/koan00_get_started.cpp
  ${PROJECT_SOURCE_DIR}/koans/koan01_number_types.cpp
  ${PROJECT_SOURCE_DIR}/koans/koan02_character_types.cpp
  PARENT_SCOPE
)
