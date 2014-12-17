// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include <string>
#include <iostream>

#include <ForexConnect.h>

#include <list>
#include <map>
#include <vector>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <iterator>
#include <string>
#include <sstream>

#define _TIMEOUT 30000


#include "../include/sample_tools.h"
#include "FXCMAPIException.h"

double const NaN = std::numeric_limits<double>::quiet_NaN();
const bool debugMode = false;
const std::string sem_ver_string = "0.0.1";
