def parse_code_file(file_path):
    files_data = []
    current_file = None
    code_lines = 0

    with open(file_path, 'r') as file:
        for line in file:
            line = line.strip()
            if line.startswith("Processing"):
                current_file = line.split(" ")[1].strip("...")
            elif line.startswith("C") and current_file:
                code_lines = int(line.split()[-2])
            elif line.startswith("Done processing") and current_file:
                files_data.append((current_file, code_lines))
                current_file = None

    # Sort by code lines in descending order and get top 5
    top_files = sorted(files_data, key=lambda x: x[1], reverse=True)[:30]
    return top_files

def parse_code_file2(file_path):
    files_data = []
    current_file = None
    code_lines = 0

    with open(file_path, 'r') as file:
        for line in file:
            line = line.strip()
            if line.startswith("Processing"):
                current_file = line.split(" ")[1].strip("...")
            elif line.startswith("C") and current_file:
                code_lines = int(line.split()[-2])
            elif line.startswith("Done processing") and current_file:
                files_data.append((current_file, code_lines))
                current_file = None

    # Sort by code lines in descending order and get top 5
    top_files = sorted(files_data, key=lambda x: x[1], reverse=True)[:30]
    top_file_names = [file for file, _ in top_files]
    return top_file_names

# Example usage
# top_5_files = parse_code_file('../code/scc_chatgpt.txt')
# for file, code in top_5_files:
#     print(f"File: {file}, Code Lines: {code}")
top_5_file_names = parse_code_file2('../code/scc_chatgpt.txt')
print(top_5_file_names)
