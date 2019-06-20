//
// Created by bt on 02.06.19.
//

#ifndef LOG_ENGINE_PATTERNABUSER_H
#define LOG_ENGINE_PATTERNABUSER_H

#include <Dispatcher.h>
#include "interface/IEngineAdapter.h"


namespace adapter
{
    class PatternAbuser : public IEngineAdapter
    {
    public:
        /**
         * get Engine name as string
         * immutable
         */
        std::string getName() const override
        {
            return ("PatternAbuser");
        }

        /**
         * get engine function as integer value
         * immutable
         * */
        int getEngineFunction() const override
        {
            return (Dispatcher::ENGINE_FUNCTION::PATTERN_ABUSER);
        }

        void run() override;

    protected:
        ~PatternAbuser() override;

    private:
        util::Logger logger = util::Logger(this->getName());
    };
}


#endif //LOG_ENGINE_PATTERNABUSER_H
