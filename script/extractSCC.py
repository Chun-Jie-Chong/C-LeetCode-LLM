import re

def extract_entries(input_file, filenames):
    with open(input_file, 'r') as f:
        content = f.read()
    
    # Split the file content by the separator
    entries = content.split('----------------------------------------------------------------------------------------------------------------------------------------------------------------')

    # Prepare a list to store the matched entries
    matched_entries = []

    # Regular expression to match the processing file name like "Processing 0002_response.c..."
    pattern = re.compile(r'Processing\s+(\d+)_response\.c', re.MULTILINE)

    for entry in entries:
        match = pattern.search(entry)
        if match:
            # Extract the file number
            file_num = match.group(1)
            if file_num in filenames:
                matched_entries.append(entry.strip())

    return matched_entries

def write_output(output_file, matched_entries):
    with open(output_file, 'w') as f:
        for entry in matched_entries:
            f.write(entry + "\n" + "-"*160 + "\n")

if __name__ == "__main__":
    # Input file containing the entries
    input_file = '../code/scc_chatgpt.txt'
    
    # Array of filenames to search for
    # yes issues
    # filenames = ['0022', '0040', '0078', '0079', '0084', '0090', '0118', '0133', '0179', '0212', '0332', '0417', '0589', '0673', '0739', '0763', '0853', '0912'
    #             ,'0067', '0150', '0215', '0279', '0297', '0332', '0682', '0691', '0740', '1799'
    #             ,'0019', '0417']
    
    # no issues
    # filenames = ['0002', '0003', '0004', '0005', '0007', '0009', '0010', '0011', '0014', '0015', '0115', '0138', '0424', '0435', '0438', '0523', '0846', '2002'
    #              ,'0023', '0024', '0025', '0026', '0027', '0028', '0033', '0035', '0036', '0097'
    #              , '0377', '0392']
    
    # line length
    # filenames = ['0004', '0015', '0022', '0039', '0040', '0048', '0051', '0054', '0057', '0078', '0079', '0084', '0090', '0118', '0120', '0213', '0309', '0332'
    #              , '0417', '0463', '0837', '0973', '0980', '0994', '1189', '1299', '1406', '1899', '1905', '2140']
    
    # LOC
    filenames = ['0707', '0297', '0212', '0332', '0417', '0208', '0981', '2002', '0155', '0015', '0051', '0143', '0073', '0207', '0046', '0329', '0994', '0912'
                 , '0076', '0056', '0138', '1799', '0079', '0199', '0215', '0148', '1856', '0005', '0057', '0133']
    

    # Output file to write the matching entries
    output_file = 'scc_loc_before.txt'

    # Extract matching entries from the input file
    matched_entries = extract_entries(input_file, filenames)

    # Write the matched entries to the output file
    write_output(output_file, matched_entries)

    print(f"Matched entries written to {output_file}")
