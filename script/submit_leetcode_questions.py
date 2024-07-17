from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.service import Service as ChromeService
from selenium.webdriver.chrome.options import Options as ChromeOptions
from webdriver_manager.chrome import ChromeDriverManager
import time
import os

# Configuration
username = ''
password = ''
urls_file = 'test.txt'
solutions_directory = 'solutions'
log_file = 'submission_log.txt'

# Initialize WebDriver with ChromeDriverManager
chrome_service = ChromeService(ChromeDriverManager().install())
chrome_options = ChromeOptions()
driver = webdriver.Chrome(service=chrome_service, options=chrome_options)

# Function to login to LeetCode
def login():
    driver.get('https://leetcode.com/accounts/login/')
    time.sleep(2)
    
    username_field = driver.find_element(By.ID, 'id_login')
    password_field = driver.find_element(By.ID, 'id_password')
    
    username_field.send_keys(username)
    password_field.send_keys(password)
    
    password_field.send_keys(Keys.RETURN)
    time.sleep(20)

# Function to submit solution to a specific URL
def submit_solution(url, solution_code):
    driver.get(url)
    time.sleep(3)
    
    code_editor = driver.find_element(By.ID, "editor")
    driver.execute_script("arguments[0].value = arguments[1];", code_editor, solution_code)
    
    # Find and click the submit button
    submit_button = driver.find_element(By.ID, "ide-top-btns")
    submit_button.click()
    
    time.sleep(10)  # Wait for submission to complete
    
    # Extract submission results
    result = driver.find_element(By.ID, '')
    
    return result

# Main function
def main():
    login()
    
    urls = []
    titles = []
    with open(urls_file, 'r') as file:
        content = file.read()
        sections = content.split("--------------------------------------------------------------------------------")
        for section in sections:
            url_start = section.find("URL:") + len("URL:")
            url_end = section.find("Title:")
            url = section[url_start:url_end].strip()
            urls.append(url)
            title_start = section.find("Title:") + len("Title:")
            title_end = section.find(". ")
            title = section[title_start:title_end].strip()
            titles.append(title)
    results = dict(zip(titles, urls))
    
    with open(log_file, 'w') as log:
        for element in results:
            solution_path = os.path.join(solutions_directory, f'{element}_response.c')
            
            if os.path.exists(solution_path):
                with open(solution_path, 'r') as sol_file:
                    solution_code = sol_file.read()
                    print(solution_code)
                    submissionResults = submit_solution(url, solution_code)
                    log.write(f"Url: {results[element]}\nProblem: {element}\nResults: {submissionResults}\n\n")
            else:
                log.write(f"Solution file for {element} not found.\n\n")
    
    driver.quit()

if __name__ == "__main__":
    main()
