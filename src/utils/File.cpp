#include "File.h"

namespace utils {
    const char *File::readFile(const char *filepath) {
        // open file
        FILE *fp = fopen(filepath, "rt");

        // determing the length (move the file pointer to the end)
        fseek(fp, 0, SEEK_END);
        long length = ftell(fp);

        // allocate memory
        fseek(fp, 0, SEEK_SET);
        auto *contents = new char[length + 1]; // + extra char end file

        // cleanup
        for (int i = 0; i < length + 1; i++) {
            contents[i] = 0;
        }

        // read the file
        fread(contents, 1, length, fp);

        // EOF
        contents[length + 1] = '\0';

        // close file
        fclose(fp);

        return contents;
    }
}
