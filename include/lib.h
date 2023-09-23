#pragma once
#include <string>

std::string ConvertTo24h(int hour, int minute, const std::string& period);
void ValidateInput(int hour, int minute, const std::string& period);
std::string FormatTime(int hour, int minute);