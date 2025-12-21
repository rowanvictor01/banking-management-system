cmake_minimum_required(VERSION 3.23)

project(Banking Management System)

add_executable(bankc)

target_sources(bankc
	PRIVATE
	./src/main.c
	./src/utils.c
	./src/account.c
	./src/menu.c
)
