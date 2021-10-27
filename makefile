CXX			:= g++

SDL_CFLAGS := $(shell sdl2-config --cflags)
SDL_LDFLAGS := $(shell sdl2-config --libs) -lSDL2_image -lSDL2_ttf

CXXFLAGS 	:= -I. -I./include ${SDL_CFLAGS} ${SDL_LDFLAGS}

EXE_NAME	:= Lab0

MSG_START	:= "Build Started"
MSG_END		:= "Build Complete"
MSG_CLEAN	:= "Cleaning up"

BUILD_DIR	:= ./bin
SRC_DIR		:= ./src
SDL_INCLUDE	:= "${SDL_SDK}/include"
SDL_LIB		:= "${SDL_SDK}/lib"

SRC			:= ${SRC_DIR}/*

all			:= build

build:
	@echo ${MSG_START}

	#remove directory if it exits and then create directory
	rm -rf ${BUILD_DIR} || true

	#create bin directory
	mkdir ${BUILD_DIR}

	${CXX} -o ${EXE_NAME} ${SRC} ${CXXFLAGS}
	@echo ${MSG_END}
	./${EXE_NAME}

.PHONY: clean

clean:
	@echo ${MSG_CLEAN}
	rm -rf ${BUILD_DIR} || true