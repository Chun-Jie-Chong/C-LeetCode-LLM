import shutil
import os

def copy_files(file_names, src_dir, dest_dir):
    # Ensure the destination directory exists
    if not os.path.exists(dest_dir):
        os.makedirs(dest_dir)
    
    # Iterate over each file name in the array
    for file_name in file_names:
        # Construct full file paths
        src_file = os.path.join(src_dir, file_name)
        dest_file = os.path.join(dest_dir, file_name)
        
        # Check if the source file exists before copying
        if os.path.exists(src_file):
            shutil.copy(src_file, dest_file)
            print(f"Copied {src_file} to {dest_file}")
        else:
            print(f"File {src_file} does not exist and cannot be copied.")

# Example usage
file_names = ['0707_response.c', '0297_response.c', '0212_response.c', '0332_response.c', '0417_response.c', '0208_response.c', '0981_response.c', '2002_response.c', '0155_response.c', '0015_response.c', '0051_response.c', '0143_response.c', '0073_response.c', '0207_response.c', '0046_response.c', '0329_response.c', '0994_response.c', '0912_response.c', '0076_response.c', '0056_response.c', '0138_response.c', '1799_response.c', '0079_response.c', '0199_response.c', '0215_response.c', '0148_response.c', '1856_response.c', '0005_response.c', '0057_response.c', '0133_response.c'] # Replace with your actual file names
src_dir = "../code"  # Replace with your source directory path
dest_dir = "new_loc/before"  # Replace with your destination directory path

copy_files(file_names, src_dir, dest_dir)
