#!/bin/bash

FILE="jumpThingy.html"

run_file() {
    if [ -f "$FILE" ]; then
        echo "File $FILE exist. Executing..."
        emrun "$FILE"
        exit 0
    else
        return 1
    fi
}

if ! run_file; then
    echo "File $FILE doesn't exist. Executing build.sh..."
    ./build.sh
fi

if ! run_file; then
    echo "File $FILE doesn't exist. Aborting."
    exit 1
fi
