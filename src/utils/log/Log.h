#pragma once

#define LOG(fmt, ...) \
  utils::Log("(%s: %d) " fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__)

namespace utils {
void Log(const char* format, ...);
}