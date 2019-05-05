#include "Dispatcher.h"
#include "adapter/Categorisation/Categorisation.h"
#include "adapter/TextSearch/TextSearch.h"

namespace engine {

Dispatcher::Dispatcher(model::EngineInput eIN) :
		engineInput(eIN)
{
	validate();
	execAdapter();
}

void Dispatcher::validate() {
	logger.info("Starting ...");
	std::ifstream i(engineInput.configFile);
	if (i.fail()) {
		logger.warn("Error loading config file " + engineInput.configFile);
		logger.warn("Trying default config file");
		i = std::ifstream("config.json");
		if (i.fail()) {
			throw InvalidConfigException("Invalid Config", 0);
		}
	}
	i >> configuration;
	logger.info(
			"Loaded config version "
					+ configuration["version"].get<std::string>());

	if(engineInput.serverLogFile == "")
	{
		logger.error("No log file specified");
		throw InvalidArgumentException("The log file needs to be specified with the -l/-log cli parameter", 404);
	}
}

void Dispatcher::execAdapter() {

	switch (engineInput.function) {
	case ENGINE_FUNCTION::SEARCH: {
		executionList.push_back(new adapter::TextSearch());
		break;
	}
	default: {
		logger.debug("Engine function is not implemented");
		break;
	}
	}
}
}
;
