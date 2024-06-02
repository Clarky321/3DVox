# Установка минимальной версии CMake
cmake_minimum_required(VERSION 3.12)

# Определение названия проекта RayEngineCore
set(ENGINE_PROJECT_NAME 3DVoxCore)

# Список публичных заголовочных файлов
set(ENGINE_PUBLIC_INCLUDES
	includes/3DVoxCore/test.h
	
	includes/3DVoxCore/cube.h
	includes/3DVoxCore/cameraController.h
	includes/3DVoxCore/tileMap.h
	includes/3DVoxCore/UI.h
)

# Список приватных исходных файлов
set(ENGINE_PRIVATE_SOURCES	
	src/3DVoxCore/test.cpp
	
	src/3DVoxCore/cube.cpp
	src/3DVoxCore/cameraController.cpp
	src/3DVoxCore/tileMap.cpp
	src/3DVoxCore/UI.cpp
)

# Общий список исходных файлов
set(ENGINE_ALL_SOURCE
	${ENGINE_PUBLIC_INCLUDES}
	${ENGINE_PRIVATE_SOURCES}
)

# Создание статической библиотеки с названием RayEngineCore
add_library(${ENGINE_PROJECT_NAME} STATIC ${ENGINE_ALL_SOURCE})

# Группировка файлов в структуру проекта в IDE
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ENGINE_ALL_SOURCE})

# Добавление путей к заголовочным файлам для внешних пользователей и для компиляции
target_include_directories(${ENGINE_PROJECT_NAME}
	PUBLIC
		includes
	PRIVATE
		src
)

# Установка стандарта C++ для компиляции
target_compile_features(${ENGINE_PROJECT_NAME} PUBLIC cxx_std_17)

# ------------------------------------------------------------------------------------- #

# Добавление подмодуля RAYLIB и его сборка
add_subdirectory(../external/raylib ${CMAKE_CURRENT_BINARY_DIR}/raylib)
# Линковка с библиотекой RAYLIB
target_link_libraries(${ENGINE_PROJECT_NAME} PUBLIC raylib)

# ------------------------------------------------------------------------------------- #

set(IMGUI_INCLUDES
	../external/imgui/imgui.h
)

set(IMGUI_SOURCES
	../external/imgui/imgui.cpp
	
	../external/imgui/imgui_draw.cpp
	../external/imgui/imgui_widgets.cpp
	../external/imgui/imgui_tables.cpp
	
	../external/imgui/imgui_demo.cpp
)

add_library(ImGui STATIC
	${IMGUI_INCLUDES}
	${IMGUI_SOURCES}
)

target_include_directories(ImGui PUBLIC ../external)
target_include_directories(ImGui PUBLIC ../external/imgui)

target_link_libraries(${ENGINE_PROJECT_NAME} PUBLIC ImGui)