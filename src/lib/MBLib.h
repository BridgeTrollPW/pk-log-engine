/*
 * MBLib.h
 *
 * Common stuff for our log engine
 *  Created on: 09.05.2019
 *      Author: BridgeTroll
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
                         * test
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
