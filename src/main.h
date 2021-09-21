#include <algorithm>
#include <array>
#include <filesystem>
#include <iostream>
#include <limits>
#include <numeric>
#include <regex>
#include <stack>
#include <string>
#include <vector>

#include "classes/StackParse.h"

// filesystem namespace
namespace fs = std::filesystem;

// Base file name prefix
#define FILEPREFIX "in"
// File extension for input files
#define FILETYPE "txt"