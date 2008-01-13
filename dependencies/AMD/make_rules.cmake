CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_aat.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_aat.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_aat.c PROPERTIES  COMPILE_FLAGS " -DDINT " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_aat.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_1.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_1.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_1.c PROPERTIES  COMPILE_FLAGS " -DDINT " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_1.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_2.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_2.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_2.c PROPERTIES  COMPILE_FLAGS " -DDINT " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_2.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_dump.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_dump.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_dump.c PROPERTIES  COMPILE_FLAGS " -DDINT " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_dump.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_postorder.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_postorder.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_postorder.c PROPERTIES  COMPILE_FLAGS " -DDINT " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_postorder.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_post_tree.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_post_tree.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_post_tree.c PROPERTIES  COMPILE_FLAGS " -DDINT " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_post_tree.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_defaults.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_defaults.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_defaults.c PROPERTIES  COMPILE_FLAGS " -DDINT " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_defaults.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_order.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_order.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_order.c PROPERTIES  COMPILE_FLAGS " -DDINT " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_order.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_control.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_control.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_control.c PROPERTIES  COMPILE_FLAGS " -DDINT " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_control.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_info.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_info.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_info.c PROPERTIES  COMPILE_FLAGS " -DDINT " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_info.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_valid.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_valid.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_valid.c PROPERTIES  COMPILE_FLAGS " -DDINT " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_valid.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_preprocess.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_preprocess.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_preprocess.c PROPERTIES  COMPILE_FLAGS " -DDINT " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_preprocess.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_aat.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_aat.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_aat.c PROPERTIES  COMPILE_FLAGS " -DDLONG " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_aat.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_1.c ${CMAKE_CURRENT_BINARY_DIR}/Source/../Source/amd_l_1.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/../Source/amd_l_1.c PROPERTIES  COMPILE_FLAGS " -DDLONG " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_1.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_2.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_2.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_2.c PROPERTIES  COMPILE_FLAGS " -DDLONG " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_2.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_dump.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_dump.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_dump.c PROPERTIES  COMPILE_FLAGS " -DDLONG " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_dump.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_postorder.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_postorder.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_postorder.c PROPERTIES  COMPILE_FLAGS " -DDLONG " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_postorder.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_post_tree.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_post_tree.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_post_tree.c PROPERTIES  COMPILE_FLAGS " -DDLONG " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_post_tree.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_defaults.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_defaults.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_defaults.c PROPERTIES  COMPILE_FLAGS " -DDLONG " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_defaults.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_order.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_order.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_order.c PROPERTIES  COMPILE_FLAGS " -DDLONG " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_order.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_control.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_control.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_control.c PROPERTIES  COMPILE_FLAGS " -DDLONG " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_control.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_info.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_info.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_info.c PROPERTIES  COMPILE_FLAGS " -DDLONG " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_info.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_valid.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_valid.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_valid.c PROPERTIES  COMPILE_FLAGS " -DDLONG " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_valid.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_preprocess.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_preprocess.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_preprocess.c PROPERTIES  COMPILE_FLAGS " -DDLONG " OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_preprocess.c GENERATED 1)
CONFIGURE_FILE( 
${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_global.c ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_global.c
 COPYONLY)
SET_SOURCE_FILES_PROPERTIES(  ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_global.c PROPERTIES  OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/amd_global.c GENERATED 1)
ADD_LIBRARY( amd 
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_aat.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_1.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_2.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_dump.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_postorder.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_post_tree.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_defaults.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_order.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_control.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_info.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_valid.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_i_preprocess.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_aat.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/../Source/amd_l_1.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_2.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_dump.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_postorder.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_post_tree.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_defaults.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_order.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_control.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_info.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_valid.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_l_preprocess.c
 ${CMAKE_CURRENT_BINARY_DIR}/Source/amd_global.c
 )