#!/bin/bash

# Specify the directory containing the .c files
directory="../code"

# Loop through all .c files in the directory
for file in "$directory"/*.c; do
    # Remove the first line and last line of the file
    sed -i '' '1d;$d' "$file"
done