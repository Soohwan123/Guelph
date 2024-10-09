#include "q1.h"


/* function will display the primary user interface
    This is already done for you*/
void prompt(){

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
struct car * insert_to_list(struct car ** head, char plate[], int mileage, int return_date){
    //Make a template car object
    struct car* new_car = (struct car*)malloc(sizeof(struct car)); 
    strcpy(new_car->plate, plate);
    new_car->mileage = mileage;
    new_car->return_date = return_date;
    new_car->next = NULL;

    if(*head == NULL){
        *head = new_car; 
    } else {
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
void print_list(struct car *head){
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
bool is_plate_in_list(struct car * head, char plate[]){
    struct car* temp = head;
    bool result = false;
    do {
        if (temp->plate == plate) {
            result = true;
            break;
        } else {
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
void swap(struct car *a, struct car *b){
    return;
}

/**
 * Sorts the list of cars based on mileage or return date.
 * @param head Pointer to the head of the list.
 * @param sort_by_mileage Boolean to sort by mileage.
 * @param sort_by_return_date Boolean to sort by return date.
 */
void sort_list(struct car ** head, bool sort_by_mileage, bool sort_by_return_date){
    return;
}

/**
 * Removes a car from the list by its plate number.
 * @param head Pointer to the head of the list.
 * @param plate Character array containing the car's license plate.
 * @return Pointer to the removed car.
 */
struct car * remove_car_from_list(struct car **head, char plate[]){
    return NULL;
}

/**
 * Removes the first car from the list.
 * @param head Pointer to the head of the list.
 * @return Pointer to the removed car.
 */
struct car * remove_first_from_list(struct car **head){
    return NULL;
}

/**
 * Calculates the profit based on the mileage difference.
 * @param initial_mileage Integer representing the car's starting mileage.
 * @param final_mileage Integer representing the car's final mileage.
 * @return Double value representing the calculated profit.
 */
double profit_calculator(int initial_mileage, int final_mileage){
    return 0.00;
}

/**
 * Writes the list of cars to a file.
 * The file would be in the format: plate,mileage,return_date
 * @param filename Character array with the file name.
 * @param head Pointer to the head of the list.
 * Writes the details of each car in the list to a file.
 */
void write_list_to_file(char *filename, struct car *head){
    FILE* newFile = fopen(filename, "w"); 
    if (newFile == NULL) {
        perror("Error occurred while opening the file");
        return;
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
void read_file_into_list(char *filename, struct car **head){
    FILE* newFile = fopen(filename, "r");
    if (newFile == NULL) {
        perror("Error occurred while opening the file");
        return;
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
            printf("Error: Invalid line format in file: %s\n", line);
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
void date(int date){
    return;
}

/**
 * Frees all the memory allocated for the cars in the list.
 * @param head Pointer to the head of the list.
 * Frees each car node in the list.
 */
void free_list(struct car ** head){
    return;
}
