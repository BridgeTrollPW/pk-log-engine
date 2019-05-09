#ifndef IENGINE_H
#define IENGINE_H

#include <string>

namespace engine
{

        class IEngineAdapter
        {
                public:
                        virtual int getEngineFunction() const = 0;
                        virtual void run() = 0;
                        virtual std::string getName() const = 0;
                protected:
                        virtual ~IEngineAdapter()
                        {
                                //Todo cleanup
                        }
        };

}
#endif
