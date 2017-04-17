#include "Result.h"
#include "rapidjson/document.h"

Result::Result() {
    is_successful = true;
}

Result::Result(int line, ErrorType etype) {
    is_successful = false;
    line_number = line;
    type = etype;
}

Result::Result(string json) {
    rapidjson::Document document;
    document.Parse<0>(json.c_str());
    is_successful = document["valid"].GetBool();
    if(!is_successful) {
        line_number = document["error"]["line"].GetInt();
        type = ErrorTypeFromString(document["error"]["type"].GetString());
    }
}

bool Result::isValid() {
    return is_successful;
}

int Result::getLineError() {
    return line_number;
}

ErrorType Result::getErrorType() {
    return type;
}

string Result::toJson() {
    string result = "{\n";
    if (is_successful) {

        // Generate successful ...
        result = result + "  \"valid\": true\n";

    } else {
        result = result + "  \"valid\": false,\n";
        result = result + "  \"error\": {\n";

        result = result + "    \"line\":" + to_string(line_number) + ",\n";
        result = result + "    \"type\": \"" + ErrorTypeToString(type) + "\"\n";
        result = result + "  }\n";
    }
    result = result + "}";
    return result;
}
