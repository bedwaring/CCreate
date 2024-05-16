#include "Extras.h"

void create_directory(const char *path) {
    if (mkdir(path, 0777) == -1) {
        if (errno != EEXIST) {
            warn("Error creating directory %s: %s", path, strerror(errno));
            exit(EXIT_FAILURE);
        }
    }
}

void create_file(const char *path, const char *content) {
    FILE *file = fopen(path, "w");
    if (!file) {
        warn("Error creating file %s: %s", path, strerror(errno));
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s", content);
    fclose(file);
}

void generate_cmake(const char *dir) {
    size_t dir_len = strlen(dir);
    size_t build_dir_len = dir_len + strlen("/build") + 1;
    size_t src_dir_len = dir_len + strlen("/src") + 1;
    size_t main_file_len = dir_len + strlen("/src/main.c") + 1;
    size_t cmake_file_len = dir_len + strlen("/CMakeLists.txt") + 1;

    char *build_dir = (char *)malloc(build_dir_len);
    char *src_dir = (char *)malloc(src_dir_len);
    char *main_file = (char *)malloc(main_file_len);
    char *cmake_file = (char *)malloc(cmake_file_len);

    if (!build_dir || !src_dir || !main_file || !cmake_file) {
        warn("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    snprintf(build_dir, build_dir_len, "%s/build", dir);
    snprintf(src_dir, src_dir_len, "%s/src", dir);
    snprintf(main_file, main_file_len, "%s/src/main.c", dir);
    snprintf(cmake_file, cmake_file_len, "%s/CMakeLists.txt", dir);

    create_directory(build_dir);
    create_directory(src_dir);

    const char *main_content = "#include <stdio.h>\n\nint main() {\n    printf(\"Hello, World!\\n\");\n    return 0;\n}\n";
    create_file(main_file, main_content);

    const char *cmake_content = 
        "cmake_minimum_required(VERSION 3.20)\n"
        "\n"
        "project(MyProject)\n"
        "\n"
        "add_executable(MyExecutable src/main.c)\n";
    create_file(cmake_file, cmake_content);

    free(build_dir);
    free(src_dir);
    free(main_file);
    free(cmake_file);

    okay("CMake project generated successfully in %s", dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        warn("Usage: %s <directory>", argv[0]);
        return EXIT_FAILURE;
    }

    generate_cmake(argv[1]);

    return EXIT_SUCCESS;
}

