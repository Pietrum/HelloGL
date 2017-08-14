#ifndef CLIENT_FILE_H
#define CLIENT_FILE_H

#include <string>

namespace utils {
    class File {
    public:
        static const char *readFile(const char *path);
    };
}

#endif //CLIENT_FILE_H
