cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME lab8)				 # имя проекта
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_definitions(-DSFML_STATIC)		 # дефайны

include_directories("C:\\Users\\richa\\dev\\c-practice\\SFML-2.6.1\\include\\")	# добавляем директории
include_directories("inc/")
link_directories("C:\\Users\\richa\\dev\\c-practice\\SFML-2.6.1\\lib\\")

add_executable("${PROJECT_NAME}" main.cpp inc/game.hpp inc/circle.hpp src/game.cpp src/circle.cpp inc/ship.hpp inc/Bullet.hpp inc/Object.hpp inc/Asteroid.hpp inc/Comet.hpp)

target_link_libraries("${PROJECT_NAME}"
						  sfml-graphics-s-d
						  sfml-window-s-d
						  sfml-system-s-d
						  opengl32
						  freetype
						  winmm
						  gdi32
						  sfml-audio-s-d
						  openal32
						  flac
						  vorbisenc
						  vorbisfile
						  vorbis
						  ogg)

file(COPY "assets" DESTINATION "/")
file(COPY "openal32.dll" DESTINATION "/")