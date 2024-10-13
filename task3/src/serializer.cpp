#include <format>

#include "serializer.h"
#include "stringtools.h"

std::string ToXML(const std::string& tagName, const std::map<Key, std::string>& data, const std::string& indent) {
	std::string result = indent + "<" + tagName + ">\n";

	for (const auto& [key, value] : data) {
		result += indent + "  <" + key + ">" + value + "</" + key + ">\n";
	}

	result += indent + "</" + tagName + ">";
	return result;
}

std::string ToXML(const std::string& tagName, const std::vector<std::string>& data, const std::string& indent) {
	std::vector<std::string> result;

	for (const auto& value : data) {
		result.push_back( indent + "<" + tagName + ">" + value + "</" + tagName + ">" );
	}
	return join(result, "\n");
}

std::string ToXML(const std::string& tagName, const std::string& data, const std::string& indent ) {
	return indent + "<" + tagName + ">" + data + "</" + tagName + ">";
}

std::string ToJSON(const std::string& tagName, const std::map<Key, std::string>& data, const std::string& indent) {
	std::string result = indent + '"' + tagName + "\": { ";
	std::vector<std::string> key_values;
	for (const auto& [key, value] : data) {
		key_values.push_back('"' + key + '"' + ": " +  '"' + value  + '"');
	}

	return result + join(key_values, ", ") + " }";
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
	std::string result = indent  + tagName + ":\n";

	for (const auto& [key, value] : data) {
		result += indent + indent + key + ": " + value  + "\n";
	}

	return result;
}

std::string ToYAML(const std::string& tagName, const std::vector<std::string>& data, const std::string& indent) {
	std::string result = indent  + tagName + ":\n";

	for (const auto& value : data) {
		result += indent + indent + "- " + value  + "\n";
	}

	return result;
}

std::string ToYAML(const std::string& tagName, const std::string& data, const std::string& indent) {
	return indent + tagName + ": " + data;
}
