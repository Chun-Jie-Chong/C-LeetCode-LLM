import os
import re

def remove_includes_and_structs_from_file(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()
    
    # Flag to check if we are inside a struct declaration
    inside_struct = False

    with open(file_path, 'w') as file:
        for line in lines:
            stripped_line = line.strip()
            
            # Skip #include lines
            if stripped_line.startswith('#include'):
                continue
            
            # Detect start of struct declaration
            if stripped_line == "struct TreeNode {" or stripped_line == "struct ListNode {":
                inside_struct = True
                continue
            
            # Detect end of struct declaration
            if inside_struct and stripped_line.endswith('};'):
                inside_struct = False
                continue
            
            # Skip lines inside struct declaration
            if inside_struct:
                continue
            
            # Write other lines
            file.write(line)

def process_directory(directory_path):
    for root, _, files in os.walk(directory_path):
        for file_name in files:
            if file_name.endswith('.c'):
                file_path = os.path.join(root, file_name)
                remove_includes_and_structs_from_file(file_path)
                print(f"Processed: {file_path}")

if __name__ == "__main__":
    directory_path = 'solutions'  # Replace with the path to your directory
    process_directory(directory_path)
