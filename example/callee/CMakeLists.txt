set(SRC_LIST user_service.cc ../user.pb.h)

add_executable(provider ${SRC_LIST})
target_link_libraries(provider rpc protobuf)