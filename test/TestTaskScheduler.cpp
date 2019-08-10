//
// Created by bt LAPNUG-win10 on 10.08.2019.
//

#include <task/TaskScheduler.h>
#include <adapter/TextSearch/TextSearchBufferElement.h>

class myTask : public IExecutionTask {
public:
    bool stopped{false};

    void run(AsyncExecutionBuffer* asyncExecutionBuffer) override {
        for (int i = 0; i < 200; i++) {
            if (stopped) {
                return;
            }
            asyncExecutionBuffer->push(new TextSearchBufferElement(i, "some text at line " + std::to_string(i)));
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }

    void terminate() override {
        stopped = true;
    }
};

int main() {
    TaskScheduler taskScheduler;
    taskScheduler.registerTask(new myTask);

    taskScheduler.start();
}