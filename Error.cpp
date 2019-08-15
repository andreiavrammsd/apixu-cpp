#include "Error.h"

int Apixu::Error::getCode() const {
    return code;
}

const string &Apixu::Error::getMessage() const {
    return message;
}
