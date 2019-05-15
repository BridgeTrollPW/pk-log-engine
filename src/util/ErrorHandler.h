/* Created by BridgeTroll
 * https://bridgetroll.de
 * https://steamcommunity.com/id/Bridge_Troll/
 *
 * ErrorHandler.h
 *
 *  Created on: 13.05.2019
 *      Author: bt
 */
#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include "Exception.h"
#include "logger/Logger.h"

class ErrorHandler
{
    public:
        int processException(Exception exception);
    private:
        util::Logger logger = util::Logger("ErrorHandler");
};
#endif // ERROR_HANDLER_H

