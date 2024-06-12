#pragma once

#include <string>

using std::string;

namespace Utils {
    class String {
        public:
        static string centering(const string &str, const int& width) {
            int len = str.length();
            if(width < len) { return str; }

            int diff = width - len;
            int pad1 = diff/2;
            int pad2 = diff - pad1;
            return string(pad1, ' ') + str + string(pad2, ' ');
        }
    };
}