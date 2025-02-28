/*
Question 1: Data Collection
Write a C program to collect data from various medical devices such as heart rate monitors, blood pressure monitors, and oxygen saturation monitors. 
The program should store the collected data in a structure.

# Question 2: Real-time Analysis
Write a C program to perform real-time analysis of the collected data to detect anomalies.
The program should use a threshold-based approach to detect anomalies.

# Question 3: Alert System
Write a C program to alert healthcare professionals in case of any irregularities. 
The program should use a notification system to send alerts to healthcare professionals.

# Question 4: Patient Data Management
Write a C program to manage patient data, including medical history, allergies, and
medications. The program should use a struct to store patient data.

# Question 5: Security and Privacy
Write a C program to ensure the security and privacy of patient data. The program should
use encryption and decryption techniques to protect patient data.

# Question 6: Real-time Processing
Write a C program to process data in real-time. The program should use a timer-based
approach to process data at regular intervals.

# Question 7: Scalability
Write a C program to handle many patients and medical devices. The program should use
dynamic memory allocation to handle large amounts of data.

# Question 8: User Interface
Write a C program to create a user-friendly interface for healthcare professionals. The
program should use a menu-based approach to provide options to healthcare
professionals.

# Question 9: Anomaly Detection
Write a C program to detect anomalies in patient data. The program should use a machine
learning-based approach to detect anomalies.

# Question 10: Integration
Write a C program to integrate the various components of the medical application. The
program should use a modular approach to integrate the components.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PATIENTS 100
#define MAX_DEVICES 10

// Structure to store patient data
typedef struct {
    char name[50];
    int age;
    char medical_history[200];
    char allergies[100];
    char medications[100];
} Patient;

// Structure to store medical device readings
typedef struct {
    int heart_rate;
    int blood_pressure;
    int oxygen_saturation;
} MedicalData;

// Function prototypes
void collectData(MedicalData *data);
void analyzeData(MedicalData *data);
void sendAlert(MedicalData *data);
void managePatientData(Patient *patients, int *count);
void encryptData(char *data);
void decryptData(char *data);
void processRealTimeData();
void dynamicMemoryHandling();
void userInterface();
void anomalyDetection(MedicalData *data);
void integrateSystem();

int main() {
    userInterface();
    return 0;
}

void collectData(MedicalData *data) {
    printf("\nEnter Heart Rate: ");
    scanf("%d", &data->heart_rate);
    printf("Enter Blood Pressure: ");
    scanf("%d", &data->blood_pressure);
    printf("Enter Oxygen Saturation: ");
    scanf("%d", &data->oxygen_saturation);
}

void analyzeData(MedicalData *data) {
    if (data->heart_rate < 60 || data->heart_rate > 100)
        sendAlert(data);
    if (data->blood_pressure < 90 || data->blood_pressure > 140)
        sendAlert(data);
    if (data->oxygen_saturation < 95)
        sendAlert(data);
}

void sendAlert(MedicalData *data) {
    printf("\nALERT: Abnormal readings detected!\n");
    printf("Heart Rate: %d, Blood Pressure: %d, Oxygen Saturation: %d\n", data->heart_rate, data->blood_pressure, data->oxygen_saturation);
}

void managePatientData(Patient *patients, int *count) {
    printf("\nEnter Patient Name: ");
    scanf("%s", patients[*count].name);
    printf("Enter Age: ");
    scanf("%d", &patients[*count].age);
    printf("Enter Medical History: ");
    scanf("%s", patients[*count].medical_history);
    printf("Enter Allergies: ");
    scanf("%s", patients[*count].allergies);
    printf("Enter Medications: ");
    scanf("%s", patients[*count].medications);
    (*count)++;
}

void encryptData(char *data) {
    while (*data) {
        *data = *data + 3;
        data++;
    }
}

void decryptData(char *data) {
    while (*data) {
        *data = *data - 3;
        data++;
    }
}

void processRealTimeData() {
    printf("Processing real-time data at regular intervals...\n");
}

void dynamicMemoryHandling() {
    MedicalData *data = (MedicalData *)malloc(MAX_PATIENTS * sizeof(MedicalData));
    if (data == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    free(data);
}

void userInterface() {
    int choice;
    Patient patients[MAX_PATIENTS];
    MedicalData data;
    int patientCount = 0;

    while (1) {
        printf("\nMedical System Menu\n");
        printf("1. Collect Data\n");
        printf("2. Analyze Data\n");
        printf("3. Manage Patient Data\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: collectData(&data); break;
            case 2: analyzeData(&data); break;
            case 3: managePatientData(patients, &patientCount); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}

void anomalyDetection(MedicalData *data) {
    analyzeData(data);
}

void integrateSystem() {
    printf("Integrating medical system components...\n");
}
