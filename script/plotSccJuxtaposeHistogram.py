# This is a Python script that reads two input files containing the output of the `scc` tool 
# for two different codebases and plots the complexity or complexity per code for each file. 
# The script takes two input files and a metric (complexity or complexity per code) as arguments 
# and generates a histogram comparing the metric for each file.

# First argument: metric (complexity or complexity/code)
# Second argument: input file 1 (output of scc tool for ChatGPT codebase)
# Third argument: input file 2 (output of scc tool for human codebase)
# Fourth argument: input file 3 (output of calculateTernaryOperator.py for ChatGPT codebase)
# Fifth argument: input file 4 (output of calculateTernaryOperator.py for human codebase)

# Example usage:
# python3 plotSccHistogram.py complexity scc_chatgpt.txt scc_human.txt

import matplotlib.pyplot as plt
import numpy as np
import argparse

# Function to parse the input text
def parse_input(input_text):
    entries = [x.strip() for x in input_text.split("----------------------------------------------------------------------------------------------------------------------------------------------------------------")]
    # print(entries)
    file_data = []

    for entry in entries:
        if "Processing" in entry:
            entry.strip()
            lines = entry.splitlines()
            file_name = lines[0].split("Processing ")[1].split("...")[0].strip()
            for line in lines:
                if line.strip().startswith("Total"):
                    parts = line.split()
                    code = int(parts[-2])
                    complexity = int(parts[-1])
                    complexity_per_code = round (complexity / code, 2)
                    # print(file_name, complexity, complexity_per_code)
                    file_data.append((file_name, complexity, complexity_per_code, code))
    return file_data

def parse_ternary_operator(input_text):
    entries = [x.strip() for x in input_text.splitlines()]
    file_data = []

    for entry in entries:
        parts = entry.split(':')
        file_name = parts[0]
        complexity = int(parts[1])
        file_data.append((file_name, complexity))
    return file_data

# Function to plot the data
def plot_data(file_data1, file_data2, ternary_1, ternary_2, metric):
    # Match file name in file_data1 with ternary_1 and add complexity from ternary_1 to file_data1
    for i, data in enumerate(file_data1):
        file_name = data[0]
        for data2 in ternary_1:
            if data2[0] == file_name:
                newComplexity = data2[1] + data[1]
                newComplexityPerCode = newComplexity / data[3]
                file_data1[i] = (file_name, newComplexity, newComplexityPerCode, data[3])
                break
    # Match file name in file_data2 with ternary_2 and add complexity from ternary_2 to file_data2
    for i, data in enumerate(file_data2):
        file_name = data[0]
        for data2 in ternary_2:
            if data2[0] == file_name:
                newComplexity = data2[1] + data[1]
                newComplexityPerCode = newComplexity / data[3]
                file_data2[i] = (file_name, newComplexity, newComplexityPerCode, data[3])
                break
    # Sort the first file data by the selected metric
    if metric == 'complexity':
        file_data1.sort(key=lambda x: x[1])
        y1_index = 1
    elif metric == 'complexity/code':
        file_data1.sort(key=lambda x: x[2])
        y1_index = 2
        
    # Prepare data for plotting
    file_names1 = [data[0][0:4] for data in file_data1]
    y1_values = [data[y1_index] for data in file_data1]
    
    #print(file_names1)

    # Create a dictionary for the second file data for easy lookup
    file_data2_dict = {data[0][0:4]: data[y1_index] for data in file_data2}
    # print(list(file_data2_dict))
    # Align the second file data to the sorted file names of the first file
    y2_values = [file_data2_dict.get(file_name, 0) for file_name in file_names1]
    
    # print(y1_values)
    # print(y2_values)
    # Compare y1_values with corresponding y2_values
    comparison = [abs(y1 - y2) / min(y1, y2) if y1 != 0 and y2 != 0 else 0 for y1, y2 in zip(y1_values, y2_values)]
    # Sort the zip(file_names1, comparison) based on comparison values
    sorted_data = sorted(zip(file_names1, comparison), key=lambda x: x[1])
    # Print the sorted data
    print(sorted_data)
    
    counter = 0
    for y1, y2 in zip(y1_values, y2_values):
        if y1 > y2:
            counter += 1
    print(f"ChatGPT has {counter} files with higher {metric} than human")

    # Plotting the histograms
    x = np.arange(len(file_names1))
    width = 0.35

    fig, ax = plt.subplots(figsize=(14, 8))  # Width: 14, Height: 8
    # Plotting the selected metric for both files as histograms
    ax.bar(x - width/2, y1_values, width, color='royalblue', label='ChatGPT')
    ax.bar(x + width/2, y2_values, width, color='sandybrown', label='Human')
    ax.set_title(f'Leetcode {metric} (sorted based on ChatGPT files)')
    ax.legend(loc='upper left')

    fig.tight_layout()

    plt.show()

# Main function to handle arguments and plot
def main():
    parser = argparse.ArgumentParser(description='Plot complexity or complexity/code from two input files.')
    parser.add_argument('metric', choices=['complexity', 'complexity/code'], help='Metric to plot: complexity or complexity/code')
    parser.add_argument('input1', help='First input file')
    parser.add_argument('input2', help='Second input file')
    parser.add_argument('input3', help='Third input file')
    parser.add_argument('input4', help='Forth input file')

    args = parser.parse_args()

    # Read the input from the first file
    with open(args.input1, 'r') as file1:
        input_text1 = file1.read()

    # Read the input from the second file
    with open(args.input2, 'r') as file2:
        input_text2 = file2.read()
    
    # Read the input from the third file
    with open(args.input3, 'r') as file3:
        input_text3 = file3.read()
    
    # Read the input from the forth file
    with open(args.input4, 'r') as file4:
        input_text4 = file4.read()

    # Extract data from the input texts
    file_data1 = parse_input(input_text1)
    file_data2 = parse_input(input_text2)
    ternary_1 = parse_ternary_operator(input_text3)
    ternary_2 = parse_ternary_operator(input_text4)

    # Plot the data based on the selected metric
    plot_data(file_data1, file_data2, ternary_1, ternary_2, args.metric)

if __name__ == "__main__":
    main()
