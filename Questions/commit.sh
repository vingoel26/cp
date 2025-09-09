#!/bin/bash

cd ..

# Stage all changes
git add .

# Get list of staged C++ files
files=$(git diff --cached --name-only -- '*.cpp')

if [ -z "$files" ]; then
    echo "No .cpp files staged. Exiting."
    exit 1
fi

# Commit with file names in message
commitMessage="solved: $files"
git commit -m "$commitMessage"

# Push changes
git push
