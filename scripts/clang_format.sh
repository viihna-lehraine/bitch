#!/bin/bash

# File: scripts/clang_format.sh

# define directories and file extensions to format

TARGET_DIRS=("src/")
FILE_EXTENSIONS=("*.cpp" "*.h")

# debug output
echo "Running Clang-Format..."
echo "Target directories: ${TARGET_DIRS[*]}"
echo "Target extensions: ${FILE_EXTENSIONS[*]}"

# find and format files
for DIR in "${TARGET_DIRS[@]}"; do
    echo "Searching in directory: $DIR"

    for EXT in "${FILE_EXTENSIONS[@]}"; do
        echo "Looking for files with extension: $EXT"

        FILES=$(find "$DIR" -type f -name "$EXT")

        if [[ -z "$FILES" ]]; then
            echo "No files found in $DIR with extension $EXT"
        else
            for FILE in $FILES; do
                echo "Formatting: $FILE"
                clang-format -style=file -i "$FILE" || echo "Error formatting $FILE"
            done
        fi
    done
done

echo "Clang-Format completed!"
