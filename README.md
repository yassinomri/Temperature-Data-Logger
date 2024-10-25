# 🌡️ Temperature-Data-Logger
Welcome to the Temperature Data Logger project! This application simulates a vital component often found in embedded systems: a temperature data logger. Whether you're monitoring environmental conditions, keeping track of room temperatures, or developing products that require thermal management, this project showcases key skills in embedded programming.

# 🚀 Project Overview
In this project, I created a simple yet effective temperature logging system. The program simulates temperature readings, timestamps them, and saves the data to a file. This is a common requirement in embedded systems, where accurate and timely data logging is crucial for performance and diagnostics.
# Key Features :
* Simulated Temperature Readings: Generates random temperature values between 0 and 40 °C, mimicking a temperature sensor's output.
* Timestamped Logs: Each reading is logged with a timestamp, providing context and allowing for time-based analysis.
* Customizable Logging Frequency: The program allows you to set the interval for logging data, giving you flexibility based on your requirements.
* Error Handling: Ensures smooth execution with proper checks.

# 📂 File Structure
```
TemperatureLogger/
├── src/                          # Contains source code files
│   └── temp_data_logger.c        # Main source code file
├── logs/                         # Directory for log files (created during first execution)
│   └── temp_log.txt              # Log file generated during execution
└── README.md                     # Project overview and instructions
```


# 💻 How to Run the Project 
1. You can download the project as .zip file and then extract it, or use cloning command on your terminal :
```bash
git clone https://github.com/yassinomri/Temperature-Data-Logger
```
3. Navigate to the Project Directory, open Terminal, and compile the program using this command :
```bash
gcc src/temp_data_logger.c -o temp_data_logger
```
4. Run the .exe Application : 
./temp_data_logger
5. Check the Logged Data by opening logs/temp_log.txt to view the logged temperature entries.

# 📈 Future Enhancements
- Integration with Actual Hardware: Future iterations could interface with real temperature sensors to log actual environmental data.
- Graphical User Interface: Implementing a GUI could enhance user interaction and data visualization.
- Data Analysis Tools: Adding features for data analysis or alerts based on temperature thresholds would make it even more useful.

# 🤝 Let's Connect!
I'm always looking to learn and grow in the field of embedded systems. If you have any feedback, suggestions, or just want to connect, feel free to reach out! Your thoughts are invaluable to me as I embark on my journey as an embedded engineer.

Thank you for checking out my project! I hope you find it as exciting as I do. 🌟
