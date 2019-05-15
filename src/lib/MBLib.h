/* Created by BridgeTroll
 * https://bridgetroll.de
 * https://steamcommunity.com/id/Bridge_Troll/
 *
 * MBLib.h
 * Common functionalities for std::strings etc.
 *
 *  Created on: 13.05.2019
 *      Author: bt
 */
#ifndef SRC_LIB_MBLIB_H_
#define SRC_LIB_MBLIB_H_

#include <string>
#include <vector>

namespace MBKingdoms
{
    class Lib
    {
        public:
            /**
             * explode string by delimiter c into STL vector
             */
            static const std::vector<std::string> explode(const std::string& s, const char& c)
            {
                std::string buff { "" };
                std::vector<std::string> v;

                for (auto n : s)
                {
                    if (n != c)
                        buff += n;
                    else if (n == c && buff != "")
                    {
                        v.push_back(buff);
                        buff = "";
                    }
                }
                if (buff != "")
                    v.push_back(buff);

                return (v);
            }
    };
}
#endif /* SRC_LIB_MBLIB_H_ */
