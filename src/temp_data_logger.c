#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>    //Uncomment if you're using Linux
#include <windows.h>   //comment this if you 're using Linux
#include <time.h>
#include <direct.h>   //for creating directories
#include <errno.h>

#define LOG_DIR "../log"   
#define LOG_FILE "../log/temp_log.txt"
#define MAX_ENTRIES 100
#define LOG_INTERVAL_SECONDS 5  //change it as you need

//simulates a temperature reading in celsius
float read_temperature() {
    return (float)(rand() % 400) / 10.0;  //gives temp between 0 and 40 degree 
}

//logs temperature with current timestamp
void log_temperature(FILE *file, int entry_count) {
    time_t rawtime;
    struct tm * timeinfo;
    char time_str[20];
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", timeinfo);
    
    float temperature = read_temperature();
    fprintf(file, "%d, %s, %.2f°C\n", entry_count, time_str, temperature);
    printf("logged entry %d: %s - temp: %.2f°C\n", entry_count, time_str, temperature);
}

//main logging loop
int main() {
    srand(time(NULL));  //init random seed for temp simulation

    //try to create log directory and ignore if it already exists
    int mkdir_result = _mkdir(LOG_DIR);
    if (mkdir_result == -1 && errno != EEXIST) {
        printf("warning: couldn't create log directory: %s\n", strerror(errno));
        //continue anyway 
    } else if (mkdir_result == 0) {
        printf("created logs directory!\n");
    }
    
    FILE *file = fopen(LOG_FILE, "w");
    if (file == NULL) {
        perror("couldn't open log file");
        return EXIT_FAILURE;
    }

    fprintf(file, "Entry, Timestamp, Temperature\n");  //add csv header
    
    int entry_count = 0;
    while (entry_count < MAX_ENTRIES) {
        log_temperature(file, entry_count + 1);
        entry_count++;
        fflush(file);  //make sure data is saved to disk

        //wait a bit before next reading
        Sleep(LOG_INTERVAL_SECONDS*1000);   //change it to sleep (with small s) if you're using Linux, and remove the '*1000', since Linux use seconds
    }

    fclose(file);
    printf("all done! wrote %d entries to %s\n", entry_count, LOG_FILE);
    return EXIT_SUCCESS;
}