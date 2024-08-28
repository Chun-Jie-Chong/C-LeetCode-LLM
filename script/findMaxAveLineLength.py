# import os

# def average_line_length(file_path):
#     with open(file_path, 'r') as file:
#         lines = file.readlines()
#         total_length = sum(len(line) for line in lines)
#         return total_length / len(lines) if lines else 0

# def find_file_with_max_avg_line_length(directory):
#     max_avg_length = 0
#     file_with_max_avg_length = None

#     for filename in os.listdir(directory):
#         if filename.endswith(".c"):
#             file_path = os.path.join(directory, filename)
#             avg_length = average_line_length(file_path)

#             if avg_length > max_avg_length:
#                 max_avg_length = avg_length
#                 file_with_max_avg_length = filename

#     return file_with_max_avg_length, max_avg_length

# # Set your directory path here
# directory_path = "../code"

# result = find_file_with_max_avg_line_length(directory_path)
# if result[0]:
#     print(f"The file '{result[0]}' has the highest average line length of {result[1]:.2f} characters.")
# else:
#     print("No .c files found in the directory.")
import os

def average_line_length(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()
        total_length = sum(len(line) for line in lines)
        return total_length / len(lines) if lines else 0

def find_top_n_files_with_max_avg_line_length(directory, top_n=30):
    file_avg_lengths = []

    for filename in os.listdir(directory):
        if filename.endswith(".c"):
            file_path = os.path.join(directory, filename)
            avg_length = average_line_length(file_path)
            file_avg_lengths.append((filename, avg_length))

    # Sort files by average line length in descending order and get the top N
    file_avg_lengths.sort(key=lambda x: x[1], reverse=True)
    return file_avg_lengths[:top_n]

# Set your directory path here
directory_path = "../code"

top_files = find_top_n_files_with_max_avg_line_length(directory_path)

if top_files:
    print("Top files with the highest average line length:")
    for i, (filename, avg_length) in enumerate(top_files, 1):
        print(f"{i}. {filename}: {avg_length:.2f} characters")
else:
    print("No .c files found in the directory.")
