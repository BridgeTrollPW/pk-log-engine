#ifndef TEXTSEARCH_H
#define TEXTSEARCH_H

#include "../../IEngineAdapter.h"
#include "../../../util/logger/Logger.h"

namespace engine
{
namespace adapter
{
class TextSearch: public engine::IEngineAdapter
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
