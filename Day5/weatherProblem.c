/*A weather station records temperature and humidity for different cities. The system should:  
- Store records using structures
- Allow searching for temperature of a specific city  
- Save data to a file  

Input Example:
Enter number of cities: 3
City 1: Mumbai, 32°C, 80%
City 2: Delhi, 38°C, 60%
City 3: Chennai, 35°C, 75%

Enter city name to search: Delhi

Output Example: 
Weather in Delhi: 38°C, 60% Humidity
Data saved in "weather_data.txt" */

#include <stdio.h>
#include <string.h>

#define MAX_CITIES 30

typedef struct {
    char cityName[50];
    int temperature;
    float humidity;
} City;

void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

int main() {
    City city[MAX_CITIES];
    int number, found = 0;
    char searchCity[50], tempCity[50];
    FILE *fileptr = fopen("weather_data.txt", "w");

    if (fileptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter number of cities: ");
    scanf("%d", &number);
    getchar();  // Consume newline left by scanf

    for (int i = 0; i < number; i++) {
        printf("City %d (Format: Name Temperature Humidity): ", i + 1);
        scanf("%49[^\n] %d %f", city[i].cityName, &city[i].temperature, &city[i].humidity);
        getchar();  // Consume newline left by scanf
        fprintf(fileptr, "%s %d°C %.2f%% Humidity\n", city[i].cityName, city[i].temperature, city[i].humidity);
    }

    printf("Enter city name to search: ");
    scanf("%49[^\n]", searchCity);
    strcpy(tempCity, searchCity);
    toLowerCase(tempCity);

    for (int i = 0; i < number; i++) {
        char storedCity[50];
        strcpy(storedCity, city[i].cityName);
        toLowerCase(storedCity);

        if (strcmp(tempCity, storedCity) == 0) {
            printf("Weather in %s: %d°C, %.2f%% Humidity\n", city[i].cityName, city[i].temperature, city[i].humidity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("City not found in records.\n");
    }

    fclose(fileptr);
    printf("Data saved in 'weather_data.txt'\n");

    return 0;
}

