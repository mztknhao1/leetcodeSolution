include_directories(../include)

aux_source_directory(. SOLUTIONSRC)

add_library(SOLUTION ${SOLUTIONSRC})