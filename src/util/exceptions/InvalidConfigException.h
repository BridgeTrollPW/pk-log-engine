/* Created by BridgeTroll
 * https://bridgetroll.de
 * https://steamcommunity.com/id/Bridge_Troll/
 *
 * InvalidConfigException.h
 *
 *  Created on: 13.05.2019
 *      Author: bt
 */
#ifndef INVALIDCONFIGEXCEPTION_H
#define INVALIDCONFIGEXCEPTION_H

#include <string>

#include "../Exception.h"

class InvalidConfigException: public Exception
{
    private:
        std::string message;
        int code;
    public:

        InvalidConfigException(std::string message, int code) :
                Exception(message, code)
        {
            this->message = message;
            this->code = code;
        }

};

#endif /* INVALIDCONFIGEXCEPTION_H */

