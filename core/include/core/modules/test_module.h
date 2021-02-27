
#ifndef CORE_MODULES_TEST_MODULE_H_
#define CORE_MODULES_TEST_MODULE_H_

#include "core/modules/module_base.h"
#include "core/napi/callback_info.h"

class TestModule : public ModuleBase {
  public:
    explicit TestModule(){ };
    void Log(const hippy::napi::CallbackInfo& info);
};

#endif // CORE_MODULES_TEST_MODULE_H_