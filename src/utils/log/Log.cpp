#include "Log.h"

#include <arduino.h>

namespace utils {

void Log(const char* format, ...) {
  va_list args;
  va_start(args, format);
  auto size = vsnprintf(nullptr, 0, format, args) + 1;
  auto buffer = new char[size];
  vsnprintf(buffer, size, format, args);
  Serial.println(buffer);
  delete[] buffer;
  va_end(args);
}
}