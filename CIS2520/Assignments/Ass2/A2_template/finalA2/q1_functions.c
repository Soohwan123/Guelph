/*
Name: Soohwan Kim
Student ID: 1349765
Assignment 2, Question 1
Date : 10/10/2024
*/

#define _CRT_SECURE_NO_WARNINGS
#include "q1.h"


/* function will display the primary user interface
    This is already done for you*/
void prompt() {

    printf("1. Add a new car to the available-for-rent list,\n");
    printf("2. Add a returned car to the available-for-rent list,\n");
    printf("3. Add a returned car to the repair list,\n");
    printf("4. Transfer a car from the repair list to the available-for-rent list,\n");
    printf("5. Rent the first available car,\n");
    printf("6. Print all the lists,\n");
    printf("7. Quit.\n");
    printf("Enter your choice: ");
}

/**
 * Inserts a new car into the linked list.
 * @param head Pointer to the head of the list.
 * @param plate Character array containing the car's license plate.
 * @param mileage Integer representing the car's mileage.
 * @param return_date Integer representing the car's return date, you can have -1 represent no return date.
 * @return Pointer to the newly added car in the list.
 */
struct car* insert_to_list(struct car** head, char plate[], int mileage, int return_date) {
    //Make a template car object
    struct car* new_car = (struct car*)malloc(sizeof(struct car));
    strcpy(new_car->plate, plate);
    new_car->mileage = mileage;
    new_car->return_date = return_date;
    new_car->next = NULL;

    // If the list is empty, insert is as a head
    if (*head == NULL) {
        *head = new_car;
    }
    else {
        struct car* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = new_car;
    }

    return new_car;
}

/**
 * Prints all the cars in the list.
 * @param head Pointer to the head of the list.
 * This function prints out the car details, it should not print return date if it does not exist.
 */
void print_list(struct car* head) {
    struct car* temp = head;
    while (temp != NULL) {
        printf("%s, %d, %d \n", temp->plate, temp->mileage, temp->return_date);
        temp = temp->next;
    }
    return;
}

/**
 * Checks if a car's plate is already in the list.
 * @param head Pointer to the head of the list.
 * @param plate Character array containing the car's license plate.
 * @return Boolean value indicating if the plate is found.
 */
bool is_plate_in_list(struct car* head, char plate[]) {
    struct car* temp = head;

    bool result = false;

    // Iterate all the list until it finds the same plate
    do {
        if (strcmp(temp->plate, plate) == 0) {
            result = true;
            break;
        }
        else {
            temp = temp->next;
        }

    } while (temp != NULL);

    return result;
}

/**
 * Swaps two cars in the list.
 * @param a Pointer to the first car.
 * @param b Pointer to the second car.
 * Swaps the plate, mileage, and return date of two cars.
 */
void swap(struct car* a, struct car* b) {
    if (a == NULL || b == NULL) {
        return;
    }

    int temp_mileage;
    int temp_return_date;
    char temp_plate[7];

    // Swap the data from two cars

    temp_mileage = a->mileage;
    a->mileage = b->mileage;
    b->mileage = temp_mileage;

    temp_return_date = a->return_date;
    a->return_date = b->return_date;
    b->return_date = temp_return_date;
 
    strcpy(temp_plate, a->plate);
    strcpy(a->plate, b->plate);
    strcpy(b->plate, temp_plate);

    return;
}

/**
 * Sorts the list of cars based on mileage or return date.
 * @param head Pointer to the head of the list.
 * @param sort_by_mileage Boolean to sort by mileage.
 * @param sort_by_return_date Boolean to sort by return date.
 */
void sort_list(struct car** head, bool sort_by_mileage, bool sort_by_return_date) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    bool is_swapped;
    struct car *car_ptr;
    struct car *last_sorted = NULL; 

    do {
        is_swapped = false;
        car_ptr = *head;

        while (car_ptr->next != last_sorted) {
            // Sort by mileage
            if (sort_by_mileage && car_ptr->mileage > car_ptr->next->mileage) {
                swap(car_ptr, car_ptr->next);
                is_swapped = true;
            }

            // Sort by return date
            if (sort_by_return_date && car_ptr->return_date > car_ptr->next->return_date) {
                swap(car_ptr, car_ptr->next);
                is_swapped = true;
            }

            car_ptr = car_ptr->next;
        }

        last_sorted = car_ptr;

    } while (is_swapped); 


    return;
}

/**
 * Removes a car from the list by its plate number.
 * @param head Pointer to the head of the list.
 * @param plate Character array containing the car's license plate.
 * @return Pointer to the removed car.
 */
struct car* remove_car_from_list(struct car** head, char plate[]) {
    struct car* current = *head;

    // Check if the head node itself needs to be removed
    if (current != NULL && strcmp(current->plate, plate) == 0) {
        // Move head to the next node
        *head = current->next;
        return current;
    }


    while (current != NULL && current->next != NULL) {
        if (strcmp(current->next->plate, plate) == 0) {
            struct car* removed_car = current->next;

            // Remove the node from the list
            current->next = removed_car->next;
            return removed_car;
        }
        current = current->next;
    }

    return NULL;
}

/**
 * Removes the first car from the list.
 * @param head Pointer to the head of the list.
 * @return Pointer to the removed car.
 */
struct car* remove_first_from_list(struct car** head) {
    struct car* current = *head;

    // Check if the head node exists
    if (current == NULL) {
        return NULL;
    }

    *head = current->next;

    return current;
}

/**
 * Calculates the profit based on the mileage difference.
 * @param initial_mileage Integer representing the car's starting mileage.
 * @param final_mileage Integer representing the car's final mileage.
 * @return Double value representing the calculated profit.
 */
double profit_calculator(int initial_mileage, int final_mileage) {
    int mileage_driven = final_mileage - initial_mileage;
    double charge;

    if (mileage_driven <= 200) {
        charge = 80.00;
    }
    else {
        // Additional charge for kilometers beyond 200
        charge = 80.00 + (mileage_driven - 200) * 0.15;
    }

    return charge;
}

/**
 * Writes the list of cars to a file.
 * The file would be in the format: plate,mileage,return_date
 * @param filename Character array with the file name.
 * @param head Pointer to the head of the list.
 * Writes the details of each car in the list to a file.
 */
void write_list_to_file(char* filename, struct car* head) {
    FILE* newFile = fopen(filename, "r+");

    // Create it if the file doesn't exist
    if (newFile == NULL) {
        newFile = fopen(filename, "w+");
        if (newFile == NULL) {
            perror("Error occurred while creating the file");
            return;
        }
        rewind(newFile);
    }

    struct car* current = head;
    while (current != NULL) {
        fprintf(newFile, "%s,%d,%d\n", current->plate, current->mileage, current->return_date);
        current = current->next;
    }

    fclose(newFile);
    return;
}

/**
 * Reads car details from a file and adds them to the list.
 * The file would be in the format: plate,mileage,return_date
 * @param filename Character array with the file name.
 * @param head Pointer to the head of the list.
 * Reads data from the file and inserts each car into the list.
 */
void read_file_into_list(char* filename, struct car** head) {
    FILE* newFile = fopen(filename, "r+");

    // Create it if the file doesn't exist
    if (newFile == NULL) {
        newFile = fopen(filename, "w+");
        if (newFile == NULL) {
            perror("Error occurred while creating the file");
            return;
        }
        rewind(newFile);
    }

    // Buffer that holds a line
    char line[200];
    while (fgets(line, sizeof(line), newFile)) {
        // Tokenize the line
        char* plate = strtok(line, ",");
        char* mileage = strtok(NULL, ",");
        char* returnDate = strtok(NULL, ",");

        // Check if tokens are valid
        if (plate == NULL || mileage == NULL || returnDate == NULL) {
            printf("Error occured due to invalid format in line");
            continue;
        }

        // Convert data to int
        int convertedMileage = atoi(mileage);
        int convertedReturnDate = atoi(returnDate);

        // Insert the new car into the list
        insert_to_list(head, plate, convertedMileage, convertedReturnDate);
    }

    fclose(newFile);
    return;
}

/**
 * Prints the date in the format of year/month/day.
 * @param date Integer representing the date in YYMMDD format.
 */
void date(int date) {
    int year = date / 10000;
    int month = (date / 100) % 100;
    int day = date % 100;

    printf("%02d/%02d/%02d\n", year, month, day);

    return;
}

/**
 * Frees all the memory allocated for the cars in the list.
 * @param head Pointer to the head of the list.
 * Frees each car node in the list.
 */
void free_list(struct car** head) {
    struct car* current = *head;
    struct car* next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;

    return;
}


/**
 * Checks the validity of the return date format
 * @param date Integer representing the date.
 * @return boolean represents the validity of the return date format.
 */
bool date_validity_check(int date) {
    int year = date / 10000;
    int month = (date / 100) % 100;
    int day = date % 100;

    if (month < 1 || month > 12) {
        return false;
    }

    // To check if day is valid for the given month
    int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // To adjust for leap year in February
    if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
        days_in_month[1] = 29;
    }

    if (day < 1 || day > days_in_month[month - 1]) {
        return false;
    }

    return true;
}
