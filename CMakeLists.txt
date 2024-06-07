cmake_minimum_required(VERSION 3.0)
project(RhythmGame C CXX)

set(CMAKE_CXX_STANDARD 20)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

add_subdirectory(libs/raylib)

add_executable(${PROJECT_NAME} 
	game/framework/resourcemanager.h
	game/framework/resourcemanager.cpp
	game/framework/core.cpp
	game/framework/core.h
	game/framework/sprite.cpp
	game/framework/sprite.h
	game/framework/drawsprite.cpp
	game/framework/drawsprite.h
	game/framework/textsprite.cpp
	game/framework/textsprite.h
	game/framework/scene.h
	game/framework/scene.cpp
	game/framework/button.h
	game/framework/button.cpp
	game/main.cpp

	game/callibrationscene.cpp
	game/callibrationscene.h
	game/scenemanager.cpp
	game/scenemanager.h
	game/level1scene.cpp
	game/level1scene.h
	game/level.cpp
	game/level.h
	game/menuscene.cpp
	game/menuscene.h
	game/settings.h
	game/indicatorlight.cpp
	game/indicatorlight.h
	game/background.cpp
	game/background.h
)
file(
	COPY game/assets
	DESTINATION ${CMAKE_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
#target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="relative-path-to-assets-in-the-game-package") # Set the asset path macro in release mode
