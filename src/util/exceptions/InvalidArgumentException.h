/* Created by BridgeTroll
 * https://bridgetroll.de
 * https://steamcommunity.com/id/Bridge_Troll/
 *
 * InvalidArgumentException.h
 *
 *  Created on: 13.05.2019
 *      Author: bt
 */
#ifndef INVALIDARGUMENTEXCEPTION_H
#define INVALIDARGUMENTEXCEPTION_H

#include <string>

#include "../Exception.h"

class InvalidArgumentException: public Exception
{
    private:
        std::string message;
        int code;
    public:

        InvalidArgumentException(std::string message, int code) :
                Exception(message, code)
        {
            this->message = message;
            this->code = code;
        }

};

#endif /* INVALIDARGUMENTEXCEPTION_H */

