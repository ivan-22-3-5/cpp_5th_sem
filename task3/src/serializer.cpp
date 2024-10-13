#include <format>

#include "serializer.h"
#include "stringtools.h"

std::string ToXML(const std::string& tagName, const std::map<Key, std::string>& data, const std::string& indent) {
	return indent + "<!-- XML representation of MAP -->";
}

std::string ToXML(const std::string& tagName, const std::vector<std::string>& data, const std::string& indent) {
	return indent + "<!-- XML representation of VECTOR -->";
}

std::string ToXML(const std::string& tagName, const std::string& data, const std::string& indent) {
	return indent + "<!-- XML representation of STRING -->";
}

std::string ToJSON(const std::string& tagName, const std::map<Key, std::string>& data, const std::string& indent) {
	std::string result = indent + '"' + tagName + "\": { ";

	for (const auto& [key, value] : data) {
		result += "\"" + key + "\": " +  "\"" + value  + "\", ";
	}

	return result + "}";
}

std::string ToJSON(const std::string& tagName, const std::vector<std::string>& data, const std::string& indent) {
	auto data_with_quotes = std::vector<std::string>();
	for (const auto& value: data) {
		data_with_quotes.push_back('"' + value + '"');
	}
	return indent + '"' + tagName + '"' + ": [" + join(data_with_quotes, ", ") + "],";
}

std::string ToJSON(const std::string& tagName, const std::string& data, const std::string& indent) {
	return indent + '"' + tagName + '"' + ": " + '"' + data + '"';
}

std::string ToYAML(const std::string& tagName, const std::map<Key, std::string>& data, const std::string& indent) {
	return indent + "<!-- YAML representation of MAP -->";
}

std::string ToYAML(const std::string& tagName, const std::vector<std::string>& data, const std::string& indent) {
	return indent + "<!-- YAML representation of VECTOR -->";
}

std::string ToYAML(const std::string& tagName, const std::string& data, const std::string& indent) {
	return indent + "<!-- YAML representation of STRING -->";
}