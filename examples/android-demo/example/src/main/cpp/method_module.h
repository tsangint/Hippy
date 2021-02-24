//
// Created by luckyzeng on 2021/2/21.
//

#ifndef ANDROID_DEMO_METHOD_MODULE_H
#define ANDROID_DEMO_METHOD_MODULE_H

#include "core/modules/module_base.h"
#include "core/napi/callback_info.h"
#include "core/napi/js_native_api_types.h"

class Scope;

class MethodModule: public ModuleBase {
public:
    explicit  MethodModule() {}
    void MethodDemo(const hippy::napi::CallbackInfo& info);
};

#endif //ANDROID_DEMO_METHOD_MODULE_H
