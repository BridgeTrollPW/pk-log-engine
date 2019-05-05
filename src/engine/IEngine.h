#ifndef IENGINE_H
#define IENGINE_H

namespace engine {

class IEngine {
public:
	int getEngineFunction();
	void prepare();
	void run();
};
}
;
#endif
