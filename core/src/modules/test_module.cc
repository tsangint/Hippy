#include "core/modules/module_register.h"
#include "core/modules/test_module.h"
#include "core/napi/js_native_api.h"
#include "core/base/logging.h"

REGISTER_MODULE(TestModule, Log)

namespace {

std::string EscapeMessage(const std::string& message) {
  size_t length = message.length();
  std::string escapMsg;
  for (size_t i = 0; i < length; i++) {
    char c = message[i];
    escapMsg += c;
    if (c == '%') {
      escapMsg += '%';
    }
  }

  return escapMsg;
}

}  // namespace

void TestModule::Log(const hippy::napi::CallbackInfo& info) {
  std::shared_ptr<Scope> scope = info.GetScope();
  std::shared_ptr<hippy::napi::Ctx> context = scope->GetContext();
  HIPPY_CHECK(context);

  std::string message;
  if (!context->GetValueString(info[0], &message)) {
    info.GetExceptionValue()->Set(context,
                                  "The first argument must be string.");
    return;
  }

  std::string str = EscapeMessage(message);
  const char* log_msg = str.c_str();
  if (info.Length() == 1) {
    HIPPY_LOG(hippy::Debug, log_msg);
  } else {
    std::string type;
    if (!context->GetValueString(info[1], &type) || type.empty()) {
      info.GetExceptionValue()->Set(
          context, "The second argument must be non-empty string.");
      return;
    }

    if (type.compare("info") == 0)
      HIPPY_LOG(hippy::Info, log_msg);
    else if (type.compare("warn") == 0)
      HIPPY_LOG(hippy::Warning, log_msg);
    else if (type.compare("error_") == 0)
      HIPPY_LOG(hippy::Error, log_msg);
    else if (type.compare("fatal") == 0)
      HIPPY_LOG(hippy::Fatal, log_msg);
    else
      HIPPY_LOG(hippy::Debug, log_msg);
  }

  info.GetReturnValue()->SetUndefined();
}