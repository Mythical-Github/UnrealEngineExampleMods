cmake_minimum_required(VERSION 3.18)

set(TARGET Unreal)
project(${TARGET})

file(GLOB_RECURSE SOURCES src/**.cpp)
file(GLOB_RECURSE GENERATED_SOURCES generated_src/**.cpp)
set(${TARGET}_Sources
        ${SOURCES}
        ${GENERATED_SOURCES}
        )

string(REGEX REPLACE "(.)([A-Z])" "\\1_\\2" MODULE_NAME ${TARGET})
string(TOUPPER ${MODULE_NAME} MODULE_NAME)

if ((NOT DEFINED BUILD_SHARED_LIBS) OR (NOT (${BUILD_SHARED_LIBS})))
    set(BUILD_STATIC 1)
    set(BUILD_SHARED 0)
    message("Project: ${TARGET} (STATIC)")
else ()
    set(BUILD_STATIC 0)
    set(BUILD_SHARED 1)
    message("Project: ${TARGET} (SHARED)")
endif ()

add_library(${TARGET} ${${TARGET}_Sources})

if (NOT (${STATIC_EXPORTS}))
    target_compile_definitions(${TARGET} PRIVATE ${PRIVATE_COMPILE_DEFINITIONS} $<${BUILD_SHARED}:RC_${MODULE_NAME}_EXPORTS> $<${BUILD_STATIC}:RC_${MODULE_NAME}_BUILD_STATIC>)
else ()
    target_compile_definitions(${TARGET} PRIVATE ${PRIVATE_COMPILE_DEFINITIONS} RC_${MODULE_NAME}_EXPORTS)
endif ()

target_include_directories(${TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/generated_include)
if (${BUILD_STATIC} EQUAL 1)
    target_compile_definitions(${TARGET} PRIVATE
            RC_ASM_HELPER_BUILD_STATIC
            RC_FILE_BUILD_STATIC
            RC_DYNAMIC_OUTPUT_BUILD_STATIC
            RC_SINGLE_PASS_SIG_SCANNER_BUILD_STATIC
            )
endif ()

target_include_directories(${TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/generated_include)
target_compile_options(${TARGET} PRIVATE ${PRIVATE_COMPILE_OPTIONS})
target_compile_features(${TARGET} PUBLIC ${PUBLIC_COMPILE_FEATURES})
target_link_options(${TARGET} PRIVATE ${PRIVATE_LINK_OPTIONS})

if(${BUILD_SHARED_LIBS} EQUAL 0)
    target_compile_definitions(${TARGET} PUBLIC ZYDIS_STATIC_DEFINE ZYCORE_STATIC_DEFINE)
endif()


target_link_libraries(${TARGET} PUBLIC File DynamicOutput SinglePassSigScanner Constructs Helpers Function PolyHook_2 ASMHelper)
