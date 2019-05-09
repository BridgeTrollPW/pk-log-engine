#ifndef TEXTSEARCH_H
#define TEXTSEARCH_H

#include <fstream>
#include <string>
#include <vector>

#include "../../../util/logger/Logger.h"
#include "../../Dispatcher.h"
#include "../../IEngineAdapter.h"

namespace engine
{
        namespace adapter
        {
                class TextSearch: public engine::IEngineAdapter
                {
                        public:
                                TextSearch(std::string filePath, std::string searchTerms);
                                /**
                                 * get Engine name as string
                                 * immutable
                                 */
                                std::string getName() const
                                {
                                        return ("TextSearch");
                                }
                                /**
                                 * get engine function as integer value
                                 * immutable
                                 */
                                int getEngineFunction() const
                                {
                                        return (Dispatcher::ENGINE_FUNCTION::SEARCH);
                                }
                                void run();

                        protected:
                                ~TextSearch();
                        private:
                                util::Logger logger = util::Logger("TextSearch");
                                std::ifstream getFileInputStream(std::string filePath);

                                std::string filePath;
                                std::vector<std::string> searchTerms;
                };
        }
}
#endif
