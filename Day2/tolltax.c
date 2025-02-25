/*Toll Tax Calculation for Vehicles   
Problem Statement:A highway toll management system needs a programto calculate toll tax based on vehicle type and distance traveled :  
1.  Vehicle Type & Base Charges:   
   - Car   → ₹5  per km  
   - Truck → ₹10 per km  
   - Bus   → ₹8  per km  
2. If a truck travels more than 500 km, a 10% discount applies.  
3. If a  bus  travels  more than 300 km , a  5% discount  applies.  

Requirements:   
1.  Input:   
   - Vehicle Type (Car/Truck/Bus)  
   - Distance Traveled (km)  
2.  Output:   
   - Total Toll Tax  

 Sample Test Case:   
 Input:   
Enter Vehicle Type (Car/Truck/Bus): Truck  
Enter Distance Traveled: 600  
   
 Output:   

Vehicle Type: Truck  
Distance Traveled: 600 km  
Base Charge: ₹6000  
Discount: ₹600  
Total Toll Tax: ₹5400*/

#include <stdio.h>
#include <string.h>

#define CAR_RATE 5
#define TRUCK_RATE 10
#define BUS_RATE 8

// Function to calculate toll tax
void calculateToll(char vehicleType[], int distance) {
    float baseCharge = 0, discount = 0, totalToll = 0;

    // Determine base charge based on vehicle type
    if (strcmp(vehicleType, "Car") == 0) {
        baseCharge = distance * CAR_RATE;
    } 
    else if (strcmp(vehicleType, "Truck") == 0) {
        baseCharge = distance * TRUCK_RATE;
        if (distance > 500) {
            discount = 0.10 * baseCharge;  // 10% discount for trucks > 500 km
        }
    } 
    else if (strcmp(vehicleType, "Bus") == 0) {
        baseCharge = distance * BUS_RATE;
        if (distance > 300) {
            discount = 0.05 * baseCharge;  // 5% discount for buses > 300 km
        }
    } 
    else {
        printf("Invalid vehicle type! Please enter Car, Truck, or Bus.\n");
        return;
    }

    totalToll = baseCharge - discount;

    // Display the toll tax calculation summary
    printf("\nVehicle Type: %s", vehicleType);
    printf("\nDistance Traveled: %d km", distance);
    printf("\nBase Charge: ₹%.2f", baseCharge);
    printf("\nDiscount: ₹%.2f", discount);
    printf("\nTotal Toll Tax: ₹%.2f\n", totalToll);
}

int main() {
    char vehicleType[10];
    int distance;

    // Get user input
    printf("Enter Vehicle Type (Car/Truck/Bus): ");
    scanf("%[^\n]s", vehicleType);
    printf("Enter Distance Traveled: ");
    scanf("%d", &distance);

    // Call the function to calculate toll
    calculateToll(vehicleType, distance);

    return 0;
}
