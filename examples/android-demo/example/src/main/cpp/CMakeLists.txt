# https://developer.android.com/studio/projects/configure-cmake?hl=zh-cn
# https://developer.android.com/studio/projects/gradle-external-native-builds?hl=zh-cn

cmake_minimum_required(VERSION 3.4.1)

include_directories(/Users/luckyzeng/workspace/projects/hippy/Hippy/core/include)

add_library( # Specifies the name of the library.
        hippy_method_demo

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        method_module.cpp)
