# Description: This script is used to plot the complexity or complexity/code based on the difficulty level of the Leetcode questions.
# The script takes five input files as arguments and generates a bean plot comparing the metric for each file.
# First argument: metric (complexity or complexity/code)
# Second argument: input file 1 (output of scc tool for ChatGPT codebase)
# Third argument: input file 2 (output of scc tool for human codebase)
# Fourth argument: input file 3 (leetcode_questions_output.txt))
# Fifth argument: input file 4 (output of calculateTernaryOperator.py for ChatGPT codebase)
# Sixth argument: input file 5 (output of calculateTernaryOperator.py for human codebase)

# Example usage:
# python3 plotBeanGraph.py complexity scc_chatgpt.txt scc_human.txt leetcode_questions_output.txt ternary_chatgpt.txt ternary_human.txt

import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
import pandas as pd
import argparse

# Function to parse the input text
def parse_input(input_text):
    entries = [x.strip() for x in input_text.split("----------------------------------------------------------------------------------------------------------------------------------------------------------------")]
    file_data = []

    for entry in entries:
        if "Processing" in entry:
            lines = entry.splitlines()
            file_name = lines[0].split("Processing ")[1].split("...")[0].strip()
            for line in lines:
                if line.strip().startswith("Total"):
                    parts = line.split()
                    code = int(parts[-2])
                    complexity = int(parts[-1])
                    complexity_per_code = round (complexity / code, 2)
                    file_data.append((file_name, complexity, complexity_per_code, code))
    return file_data

def read_difficulties(input_text):
    titles = []
    difficulties = []
    sections = input_text.split("--------------------------------------------------------------------------------")
    for section in sections:
        title_start = section.find("Title:") + len("Title:")
        title_end = section.find(". ")
        title = section[title_start:title_end].strip().zfill(4)
        titles.append(title)
        difficulties_start = section.find("Difficulty:") + len("Difficulty:")
        difficulties_end = section.find("Content:")
        difficulty = section[difficulties_start:difficulties_end].strip()
        difficulties.append(difficulty)
    results = dict(zip(titles, difficulties))
    return results

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
def plot_data(file_data1, file_data2, metric, difficulties, ternary_1, ternary_2):
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

    if metric == 'complexity':
        y_index = 1
    elif metric == 'complexity/code':
        y_index = 2
    
    easyFileNames = [title for title, difficulty in difficulties.items() if difficulty == 'Easy']
    mediumFileNames = [title for title, difficulty in difficulties.items() if difficulty == 'Medium']
    hardFileNames = [title for title, difficulty in difficulties.items() if difficulty == 'Hard']
    # print(f"Easy {easyFileNames}")
    # print(f"Medium {mediumFileNames}")
    # print(f"Hard {hardFileNames}")
    
    # easyA = [[data[0][0:4], data[y_index]] for data in file_data1 if data[0][0:4] in easyFileNames]
    group_easyChatGPT = [data[y_index] for data in file_data1 if data[0][0:4] in easyFileNames]
    group_mediumChatGPT = [data[y_index] for data in file_data1 if data[0][0:4] in mediumFileNames]
    group_hardChatGPT = [data[y_index] for data in file_data1 if data[0][0:4] in hardFileNames]
    # print(easyA)
    
    group_easyHuman = [data[y_index] for data in file_data2 if data[0][0:4] in easyFileNames]
    group_mediumHuman = [data[y_index] for data in file_data2 if data[0][0:4] in mediumFileNames]
    group_hardHuman = [data[y_index] for data in file_data2 if data[0][0:4] in hardFileNames]

    # Combine the data into a DataFrame
    data = pd.DataFrame({
        'Value': group_easyChatGPT + group_easyHuman + group_mediumChatGPT + group_mediumHuman + group_hardChatGPT + group_hardHuman,
        'Difficulties': ['Easy'] * len(group_easyChatGPT) + ['Easy'] * len(group_easyHuman) +
                        ['Medium'] * len(group_mediumChatGPT) + ['Medium'] * len(group_mediumHuman) +
                        ['Hard'] * len(group_hardChatGPT) + ['Hard'] * len(group_hardHuman),
        'Group': ['ChatGPT-4o'] * len(group_easyChatGPT) + ['Human'] * len(group_easyHuman) +
                 ['ChatGPT-4o'] * len(group_mediumChatGPT) + ['Human'] * len(group_mediumHuman) +
                 ['ChatGPT-4o'] * len(group_hardChatGPT) + ['Human'] * len(group_hardHuman)
    })

    # Create the bean plot (violin plot)
    plt.figure(figsize=(10, 8))
    sns.violinplot(x='Difficulties', y='Value', data=data, split=True, inner="point", density_norm="width", bw_adjust=0.2, hue="Group", palette={'ChatGPT-4o': 'royalblue', 'Human': 'sandybrown'})

    # Add labels and title
    plt.xlabel('Group')
    plt.ylabel('Value')
    plt.title(f'Leetcode {metric} by difficulty and group'.capitalize())

    # Display the plot
    plt.show()


# Main function to handle arguments and plot
def main():
    parser = argparse.ArgumentParser(description='Plot complexity or complexity/code from two input files.')
    parser.add_argument('metric', choices=['complexity', 'complexity/code'], help='Metric to plot: complexity or complexity/code')
    parser.add_argument('input1', help='First input file')
    parser.add_argument('input2', help='Second input file')
    parser.add_argument('input3', help='Third input file')
    parser.add_argument('input4', help='Fourth input file')
    parser.add_argument('input5', help='Fifth input file')

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
        
    # Read the input from the fifth file
    with open(args.input5, 'r') as file5:
        input_text5 = file5.read()

    # Extract data from the input texts
    file_data1 = parse_input(input_text1)
    file_data2 = parse_input(input_text2)
    difficulties = read_difficulties(input_text3)
    ternary_1 = parse_ternary_operator(input_text4)
    ternary_2 = parse_ternary_operator(input_text5)
    #print(difficulties)

    # Plot the data based on the selected metric
    plot_data(file_data1, file_data2, args.metric, difficulties, ternary_1, ternary_2)

if __name__ == "__main__":
    main()


