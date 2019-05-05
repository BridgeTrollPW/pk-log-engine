#include <iostream>
#include <fstream>
#include <list>
#include <limits>
#include <string>
#include <chrono>

#include "StartRoutine.h"
#include "../../util/exceptions/InvalidConfigException.h"
#include "../../util/exceptions/InvalidArgumentException.h"
#include "../RuleProcessor/Rule.h"

#include "../../engine/Dispatcher.h"
#include "../../engine/model/EngineInput.h"

using json = nlohmann::json;

StartRoutine::StartRoutine(int argc, char **argv) {
	engine::model::EngineInput eIN;

	for (int i = 1; i < argc; ++i) {
		if (std::string(argv[i]) == "-help" || std::string(argv[i]) == "-h"
				|| std::string(argv[i]) == "-?") {
			std::cout << "" << std::endl;
		} else if (std::string(argv[i]) == "-function"
				|| std::string(argv[i]) == "-f") {
			if (i + 1 < argc) {
				eIN.function = std::stoi(argv[++i]);
			} else {
				throw InvalidArgumentException(
						"-function/-f option requires one argument.", 1);
			}
		} else if (std::string(argv[i]) == "-config"
				|| std::string(argv[i]) == "-c") {
			if (i + 1 < argc) {
				eIN.configFile = argv[++i];
			} else {
				throw InvalidArgumentException(
						"-config/-c option requires one argument.", 1);
			}
		} else if (std::string(argv[i]) == "-log"
				|| std::string(argv[i]) == "-l") {
			if (i + 1 < argc) {
				eIN.serverLogFile = argv[++i];
			} else {
				throw InvalidArgumentException(
						"-log/-l option requires one argument.", 1);
			}
		} else if (std::string(argv[i]) == "-search"
				|| std::string(argv[i]) == "-s") {
			if (i + 1 < argc) {
				eIN.searchStrings = argv[++i];
			} else {
				throw InvalidArgumentException(
						"-search/-s option requires one argument.", 1);
			}
		} else if (std::string(argv[i]) == "-lines"
				|| std::string(argv[i]) == "-ls") {
			if (i + 1 < argc) {
				eIN.linePairs = argv[++i];
			} else {
				throw InvalidArgumentException(
						"-lines/-ls option requires one argument.", 1);
			}
		} else if (std::string(argv[i]) == "-pretty-printing"
				|| std::string(argv[i]) == "-p") {
			eIN.prettyPrinting = true;
		}
	}
	engine::Dispatcher d = engine::Dispatcher(eIN);
}
