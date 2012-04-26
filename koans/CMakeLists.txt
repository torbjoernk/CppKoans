# koans/CMakeList.txt

set(cppkoans_SOURCES
  ${cppkoans_SOURCES}
  ${PROJECT_SOURCE_DIR}/koans/koan00_get_started.cpp
  ${PROJECT_SOURCE_DIR}/koans/koan01_number_types.cpp
  ${PROJECT_SOURCE_DIR}/koans/koan02_character_types.cpp
  ${PROJECT_SOURCE_DIR}/koans/koan03_further_types.cpp
  ${PROJECT_SOURCE_DIR}/koans/koan04_arrays.cpp
  ${PROJECT_SOURCE_DIR}/koans/koan05_pointers.cpp
# When an episode of koans is added, it must be appended here
#   ${PROJECT_SOURCE_DIR}/koans/koanXX_sample_koans.cpp
  PARENT_SCOPE
)
