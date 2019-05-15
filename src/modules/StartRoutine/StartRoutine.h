/* Created by BridgeTroll
 * https://bridgetroll.de
 * https://steamcommunity.com/id/Bridge_Troll/
 *
 * StartRoutine.h
 *
 *  Created on: 13.05.2019
 *      Author: bt
 */
#ifndef STARTROUTINE_H
#define STARTROUTINE_H

#include "../../util/logger/Logger.h"

class StartRoutine
{
    public:
        StartRoutine(int argc, char **argv);
    private:
        util::Logger logger = util::Logger("StartRoutine");
};

#endif /* STARTROUTINE_H */

