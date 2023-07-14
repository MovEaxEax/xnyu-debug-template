#pragma once

struct DebugFunction {
	std::string nameParent;
	std::string nameChild;
	std::string nameFull;
	std::vector<std::string> description;
	std::string placeholder;
	bool rapid;
	std::vector<Variable> parameter;
};

struct DebugFunctionParent {
	std::string nameParent;
	std::vector<std::string> description;
	std::vector<DebugFunction> functions;
};
