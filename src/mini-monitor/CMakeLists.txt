
include_directories(/data/test/usemuduo/src/)
include_directories(/usr/include)
link_directories(/usr/lib64)
link_directories(/data/test/usemuduo/lib)

#must payattention to the link order!!!!
add_executable(client itc.cpp fileMonitor.cpp processMonitor.cpp client.cc global.cpp)
#target_link_libraries(client muduo_net)
#target_link_libraries(client muduo_base)
target_link_libraries(client libmuduo_base_cpp11.a)
target_link_libraries(client libmuduo_net_cpp11.a)
target_link_libraries(client pthread)
target_link_libraries(client boost_thread)
target_link_libraries(client boost_system)

add_executable(server server.cc)
target_link_libraries(server libmuduo_base_cpp11.a)
target_link_libraries(server libmuduo_net_cpp11.a)
target_link_libraries(server pthread)
target_link_libraries(server boost_thread)
target_link_libraries(server boost_system)