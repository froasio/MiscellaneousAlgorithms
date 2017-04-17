#ifndef MML_ERRORTYPE_H
#define MML_ERRORTYPE_H


enum class ErrorType {
    /**
     * Wrong character in tag name.
     */
            WRONG_CHAR_IN_TAG_NAME,

    /**
     * Too many/few characters in tag name.
     */
            WRONG_NUMBER_CHARS_IN_TAG,

    /**
     * Closed tag (aka: />) without a opening pair
     */
            UNEXPECTED_CLOSING_TAG_CHAR,

    /**
     * No closed tag for a open tag or closing tag with an open pair
     */
            UNBALANCED_TAG,

    /**
     * Tag is opened with '<' character, but no matching '>' character was seen
     */
            UNCLOSED_TAG,

    /**
     * CDATA section not closed before end of file
     */
            UNEXPECTED_END_OF_STREAM,
    /**
     * Default tag error
     */
            DEFAULT_TAG_ERROR

};

inline const char *ErrorTypeToString(ErrorType v) {
    switch (v) {
        case ErrorType::WRONG_CHAR_IN_TAG_NAME:
            return "WRONG_CHAR_IN_TAG_NAME";
        case ErrorType::WRONG_NUMBER_CHARS_IN_TAG:
            return "WRONG_NUMBER_CHARS_IN_TAG";
        case ErrorType::UNEXPECTED_CLOSING_TAG_CHAR:
            return "UNEXPECTED_CLOSING_TAG_CHAR";
        case ErrorType::UNBALANCED_TAG:
            return "UNBALANCED_TAG";
        case ErrorType::UNCLOSED_TAG:
            return "UNCLOSED_TAG";
        case ErrorType::UNEXPECTED_END_OF_STREAM:
            return "UNEXPECTED_END_OF_STREAM";
        case ErrorType::DEFAULT_TAG_ERROR:
        default:
            return "DEFAULT_TAG_ERROR"; 
    }
}

#endif //MML_ERRORTYPE_H
