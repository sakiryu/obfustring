cmake_minimum_required(VERSION 3.13.0)

project(obfustring)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE obfustring)