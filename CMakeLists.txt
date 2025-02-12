project(PhysicsSim)

add_subdirectory(lib/glfw)
add_subdirectory(lib/glad)
add_subdirectory(lib/imgui)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(
  "${CMAKE_PROJECT_NAME}"  
)

target_sources("${CMAKE_PROJECT_NAME}" PRIVATE ${MY_SOURCES})


target_link_libraries(
  "${CMAKE_PROJECT_NAME}" PRIVATE
  glfw glad imgui
)
