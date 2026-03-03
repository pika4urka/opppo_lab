#ifndef _HAND_COMMANDS_
#define _HAND_COMMANDS_

#include <iostream>
#include "container/container.h"
#include <stdexcept>
#include <string>
#include "utils/utils.h"

namespace handCom
{
    void exect_com(container &cont, std::string& com_line);
}

#endif //_HAND_COMMANDS_