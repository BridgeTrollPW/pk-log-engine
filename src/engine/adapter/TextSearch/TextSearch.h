#ifndef TEXTSEARCH_H
#define TEXTSEARCH_H

#include "../../IEngine.h"
#include "../../../util/logger/Logger.h"

namespace engine
{
namespace adapter
{
class TextSearch: public engine::IEngine
{
public:
    TextSearch();
private:
    util::Logger logger = util::Logger("TextSearch");
};
}
;
}
;
#endif
