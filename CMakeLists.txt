cmake_minimum_required(VERSION 3.10)
project(c_curriculum_design)

# 将头文件目录添加到搜索路径中
include_directories(include)

# 添加源文件
add_library(count src/count/count.c)
add_library(search src/search/search.c)
add_library(log src/log/log.c)
add_library(login src/user/user.c)
add_library(add src/actions/add.c)
add_library(delete src/actions/delete.c)
add_library(modify src/actions/modify.c)
add_library(sort src/actions/sort.c)
add_library(insert src/actions/insert.c)
add_library(date src/date/date.c)

set(CMAKE_CXX_STANDARD 17)

add_executable(c_curriculum_design main.c)

# 链接库文件到可执行文件
target_link_libraries(c_curriculum_design count)
target_link_libraries(c_curriculum_design search)
target_link_libraries(c_curriculum_design log)
target_link_libraries(c_curriculum_design login)
target_link_libraries(c_curriculum_design add)
target_link_libraries(c_curriculum_design delete)
target_link_libraries(c_curriculum_design modify)
target_link_libraries(c_curriculum_design sort)
target_link_libraries(c_curriculum_design insert)
target_link_libraries(c_curriculum_design date)