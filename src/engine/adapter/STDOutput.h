//
// Created by bt LAPNUG-win10 on 10.08.2019.
//

#ifndef LOG_ENGINE_STDOUTPUT_H
#define LOG_ENGINE_STDOUTPUT_H


#include <interface/IEngineAdapter.h>

namespace adapter {
    class STDOutput : public IEngineAdapter {
    private:
        bool running;
        util::Logger logger = util::Logger(getName());

        bool shouldRun(AsyncExecutionBuffer &asyncExecutionBuffer);

    public:
        explicit STDOutput(std::condition_variable &conditionVariable);

        ~STDOutput() override = default;

        int getEngineFunction() const override;

        void run(AsyncExecutionBuffer &asyncExecutionBuffer) override;

        std::string getName() const override
        {
            return "STDOutput";
        };

        void terminate() override;
    };
}

#endif //LOG_ENGINE_STDOUTPUT_H
