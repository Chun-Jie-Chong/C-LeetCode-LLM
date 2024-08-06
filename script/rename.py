import os
import re

def process_files(directory):
    # Regular expression to match the file name pattern
    pattern = re.compile(r'^(\d{1,3})_response\.c$')

    # Iterate over all files in the directory
    for filename in os.listdir(directory):
        match = pattern.match(filename)
        if match:
            number = match.group(1)
            # Pad the number to 4 digits
            new_number = number.zfill(4)
            new_filename = f"{new_number}_response.c"
            # Construct the full file paths
            old_path = os.path.join(directory, filename)
            new_path = os.path.join(directory, new_filename)
            # Rename the file
            os.rename(old_path, new_path)
            print(f"Renamed: {filename} -> {new_filename}")

# Example usage
directory_path = '../code'
process_files(directory_path)
