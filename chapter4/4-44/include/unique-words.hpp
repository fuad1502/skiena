#pragma once

#include <functional>
#include <string>
#include <vector>

namespace UniqueWords {
std::vector<std::string>
getUniqueWords(std::vector<std::string> &words,
               std::function<void(std::vector<std::string> &)> sort);
}
