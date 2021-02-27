# https://developer.android.com/studio/projects/configure-cmake?hl=zh-cn
# https://developer.android.com/studio/projects/gradle-external-native-builds?hl=zh-cn

cmake_minimum_required(VERSION 3.4.1)

project("hippy_method_demo")

set(LIBHIPPY_ROOT_DIR ../../../../../../)
#include_directories(${LIBHIPPY_ROOT_DIR}core, ${LIBHIPPY_ROOT_DIR}android/sdk/src/main/jni/include, ${LIBHIPPY_ROOT_DIR}android/sdk/src/main/jni/include/jni)
include_directories(/Users/luckyzeng/workspace/projects/hippy/Hippy/core/include)

#link_directories(../../../../../../android/sdk/build/outputs/armeabi-v7a)
#link_libraries(libhippybridge.so)

add_library(libhippybridge SHARED IMPORTED)
#set_target_properties(libhippybridge PROPERTIES IMPORTED_LOCATION ${LIBHIPPY_ROOT_DIR}android/sdk/libs/armeabi-v7a/libhippybridge.so)
#${PROJECT_SOURCE_DIR}/third_party/${V8_VERSION}/v8/${ANDROID_ABI}/
set_target_properties(libhippybridge PROPERTIES IMPORTED_LOCATION /Users/luckyzeng/workspace/projects/hippy/Hippy/android/sdk/libs/armeabi-v7a/libhippybridge.so)

add_library(
        hippy_method_demo
        SHARED
        method_module.cpp)

find_library(
        log-lib
        log )

target_link_libraries(
        hippy_method_demo
        ${log-lib}
        libhippybridge)


