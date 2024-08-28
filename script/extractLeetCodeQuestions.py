import re

def extract_entries(input_file, titles):
    with open(input_file, 'r') as f:
        content = f.read()

    # Split the file content by the separator "-----"
    entries = content.split('--------------------------------------------------------------------------------')

    # Prepare a list to store the matched entries
    matched_entries = []

    # Regular expression to match titles like "409. Longest Palindrome"
    pattern = re.compile(r'^\s*Title:\s*(\d+)\.', re.MULTILINE)

    for entry in entries:
        match = pattern.search(entry)
        if match:
            # Extract the title number
            title_num = match.group(1)
            if title_num in titles:
                matched_entries.append(entry.strip())

    return matched_entries

def write_output(output_file, matched_entries):
    with open(output_file, 'w') as f:
        for entry in matched_entries:
            f.write(entry + "\n" + "-"*80 + "\n")

if __name__ == "__main__":
    # Input file containing the entries
    input_file = 'leetcode_questions_output.txt'
    
    # Array of titles to search for
    # malloc overflow
    # titles = ['22', '40', '78', '79', '84', '90', '118', '133', '179', '212', '332', '417', '589', '673', '739', '763', '853', '912']
    # no malloc overflow
    # titles = ['2', '3', '4', '5', '7', '9', '10', '11', '14', '15', '115', '138', '424', '435', '438', '523', '846', '2002']
    
    # # array out of bounds
    # titles = ['67', '150', '215', '279', '297', '332', '682', '691', '740', '1799']
    # # no array out of bounds
    # titles = ['23', '24', '25', '26', '27', '28', '33', '35', '36', '97']
    
    # # null dereference
    # titles = ['19', '417']
    # # no null dereference
    # titles = ['377', '392']
    
    # line length
    # titles = ['4', '15', '22', '39', '40', '48', '51', '54', '57', '78', '79', '84', '90', '118', '120', '213', '309', '332', '417', '463', '837', '973', '980', '994', '1189', '1299', '1406', '1899', '1905', '2140']

    # LOC
    titles = ['707', '297', '212', '332', '417', '208', '981', '2002', '155', '15', '51', '143', '73', '207', '46', '329', '994', '912', '76', '56', '138', '1799', '79', '199', '215', '148', '1856', '5', '57', '133']
    # Output file to write the matching entries
    output_file = 'loc.txt'

    # Extract matching entries from the input file
    matched_entries = extract_entries(input_file, titles)

    # Write the matched entries to the output file
    write_output(output_file, matched_entries)

    print(f"Matched entries written to {output_file}")
