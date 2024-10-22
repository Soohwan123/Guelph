/*
Name: Soohwan Kim
Student ID: 1349765
Assignment 2, Question 1
Date : 10/10/2024
*/

#include "q1.h"

/*
* A basic menu based structure has been provided
*/

int main() {

    //Our three Linked Lists
    struct car* available_head = NULL;
    struct car* rented_head = NULL;
    struct car* repair_head = NULL;

    //Read the text files first
    read_file_into_list("available.txt", &available_head);
    read_file_into_list("rented.txt", &rented_head);
    read_file_into_list("repair.txt", &repair_head);

    //Sort available list and rented list according to the requirements
    sort_list(&available_head, true, false);
    sort_list(&rented_head, false, true);

    int choice;

    do
    {
        prompt();
        // Check for valid numeric input
        bool is_valid = false;
        char input[10];

        while (!is_valid) {
            scanf("%s", input);
            is_valid = true;

            // Check if all characters in the input are digits
            for (int i = 0; input[i] != '\0'; i++) {
                if (!isdigit(input[i])) {
                    is_valid = false;
                    printf("Invalid input. Please enter a numeric choice: ");
                    break;
                }
            }

            // If the input is valid, convert the string to an integer
            if (is_valid) {
                choice = atoi(input);
            }
        }



        /*
         * You will need to add all the cases
         * Call the appropriate functions
         * You would also need to save data to disc upon exit
         * File Format: plate,mileage,return_date
         * Error Handling needs to happen too
        */

        switch (choice) {
            case 1: {
                char plateNumber[7];
                int mileage;
                bool valid_input = false;

                //Checking if the plate number is valid
                while (!valid_input) {
                    printf("Please enter the plate number : ");
                    scanf("%s", plateNumber);

                    int length = strlen(plateNumber);

                    if (length >= 2 && length < 8) {
                        valid_input = true;
                    }


                    for (int i = 0; i < length && valid_input; i++) {
                        // if it's not an alphabet or a number it's false
                        if (!isalnum(plateNumber[i])) {
                            valid_input = false;
                        }
                    }

                    if (!valid_input) {
                        printf("Invalid. The plate number must be 2-8 characters long and letters and numbers.\n");
                    }
                    else if (available_head == NULL) {
                        valid_input = true;
                    }
                    else if (is_plate_in_list(available_head, plateNumber)) {
                        printf("Duplicate plate number. Please enter an unique plate number.\n");
                        valid_input = false;
                    }
                };

                //Set it as false to check mileage
                valid_input = false;

                //Checking if the mileage is valid
                while (!valid_input) {
                    printf("\nPlease enter the current total mileage: ");
                    if (scanf("%d", &mileage) != 1 || mileage < 0) {
                        printf("Invalid. Please enter a positive number.\n");

                        // freeing input buffer
                        while (getchar() != '\n');
                        valid_input = false;
                    }
                    else {
                        valid_input = true;
                    }
                };

                insert_to_list(&available_head, plateNumber, mileage, -1);
                printf("A new car %s added to the available car list successfully!\n\n", plateNumber);
                sort_list(&available_head, true, false);
                break;
            }

            case 2: {
                // If there is no rented car, break the case
                if (rented_head == NULL) {
                    printf("There is no car rented at the moment. Please try another time.\n\n ");
                    break;
                }

                char plateNumber[7];
                int mileage;
                struct car* rented_car = NULL;
                bool valid_input = false;

                //Checking if the plate number is valid
                while (!valid_input) {
                    printf("Please enter the plate number : ");
                    scanf("%s", plateNumber);

                    int length = strlen(plateNumber);
                    if (length >= 2 && length <= 8) {
                        valid_input = true;
                    }

                    for (int i = 0; i < length && valid_input; i++) {
                        // if it's not an alphabet or a number it's false
                        if (!isalnum(plateNumber[i])) {
                            valid_input = false;
                        }
                    }

                    if (!valid_input) {
                        printf("Invalid. The plate number must be 2-8 characters long and letters and numbers.\n");
                    }
                    else if (!is_plate_in_list(rented_head, plateNumber)) {
                        printf("Invalid. The plate number is not in the rented car list.\n");
                        valid_input = false;
                    }
                    else if (is_plate_in_list(available_head, plateNumber)) {
                        printf("Duplicate plate number exists in the available car list. Please enter an unique plate number.\n");
                        valid_input = false;
                    }
                };

                rented_car = remove_car_from_list(&rented_head, plateNumber);

                //Set it as false to check mileage
                valid_input = false;

                //Checking if the mileage is valid
                while (!valid_input) {
                    printf("\nPlease enter the current total mileage: ");
                    scanf("%d", &mileage);
                    if (mileage < 0) {
                        printf("Invalid. Please enter a positive number.\n");

                        // freeing input buffer
                        while (getchar() != '\n');
                        valid_input = false;
                    }
                    else if (mileage <= rented_car->mileage) {
                        printf("Invalid. The mileage has to be larger than before.\n");

                        // freeing input buffer
                        while (getchar() != '\n');
                        valid_input = false;
                    }
                    else {
                        valid_input = true;
                    }
                };


                insert_to_list(&available_head, plateNumber, mileage, -1);

                printf("Money charged : $%.2f\n\n", profit_calculator(rented_car->mileage, mileage));
                printf("Car %s returned to the available list from the rented car list successfully!\n\n", plateNumber);
                sort_list(&available_head, true, false);
                free(rented_car);
                break;
            }

            case 3: {
                // If there is no rented car, break the case
                if (rented_head == NULL) {
                    printf("There is no car rented at the moment. Please try another time. \n\n");
                    break;
                }

                char plateNumber[7];
                int mileage;
                struct car* rented_car = NULL;
                bool valid_input = false;

                //Checking if the plate number is valid
                while (!valid_input) {
                    printf("Please enter the plate number : ");
                    scanf("%s", plateNumber);

                    int length = strlen(plateNumber);
                    if (length >= 2 && length <= 8) {
                        valid_input = true;
                    }

                    for (int i = 0; i < length && valid_input; i++) {
                        // if it's not an alphabet or a number it's false
                        if (!isalnum(plateNumber[i])) {
                            valid_input = false;
                        }
                    }

                    if (!valid_input) {
                        printf("Invalid. The plate number must be 2-8 characters long and letters and numbers.\n");
                    }
                    else if (!is_plate_in_list(rented_head, plateNumber)) {
                        printf("Invalid. The plate number is not in the rented car list.\n");
                        valid_input = false;
                    }
                };

                rented_car = remove_car_from_list(&rented_head, plateNumber);

                //Set it as false to check mileage
                valid_input = false;

                //Checking if the mileage is valid
                while (!valid_input) {
                    printf("\nPlease enter the current total mileage: ");
                    scanf("%d", &mileage);
                    if (mileage < 0) {
                        printf("Invalid. Please enter a positive number.\n");

                        // freeing input buffer
                        while (getchar() != '\n');
                        valid_input = false;
                    }
                    else if (mileage <= rented_car->mileage) {
                        printf("Invalid. The mileage has to be larger than before.\n");

                        // freeing input buffer
                        while (getchar() != '\n');
                        valid_input = false;
                    }
                    else {
                        valid_input = true;
                    }
                };


                insert_to_list(&repair_head, plateNumber, mileage, -1);

                printf("Money charged : $%.2f\n\n", profit_calculator(rented_car->mileage, mileage));
                printf("Car %s returned to the repair list from the rented car list successfully!\n\n", plateNumber);
                free(rented_car);
                break;
            }

            case 4: {
                // If there is no car in repair, break the case
                if (repair_head == NULL) {
                    printf("There is no car in repair at the moment. Please try another time.\n\n ");
                    break;
                }

                char plateNumber[7];
                struct car* repaired_car = NULL;
                bool valid_input = false;


                //Checking if the plate number is valid
                while (!valid_input) {
                    printf("Please enter the plate number : ");
                    scanf("%s", plateNumber);

                    int length = strlen(plateNumber);

                    if (length >= 2 && length <= 8) {
                        valid_input = true;
                    }


                    for (int i = 0; i < length && valid_input; i++) {
                        // if it's not an alphabet or a number it's false
                        if (!isalnum(plateNumber[i])) {
                            valid_input = false;
                        }
                    }

                    if (!valid_input) {
                        printf("Invalid. The plate number must be 2-8 characters long and letters and numbers.\n");
                    }
                    else if (!is_plate_in_list(repair_head, plateNumber)) {
                        printf("Invalid. The plate number is not in the repair car list.\n");
                        valid_input = false;
                    }
                    else if (is_plate_in_list(available_head, plateNumber)) {
                        printf("Duplicate plate number exists in the available car list. Please enter an unique plate number.\n");
                        valid_input = false;
                    }
                };

                repaired_car = remove_car_from_list(&repair_head, plateNumber);


                insert_to_list(&available_head, plateNumber, repaired_car->mileage, -1);
                sort_list(&available_head, true, false);
                printf("Car %s added to the available car list from the repaired car list successfully!\n\n", plateNumber);
                free(repaired_car);
                break;
            }

            case 5: {
                // If there is no rented car, break the case
                if (available_head == NULL) {
                    printf("There is no car available at the moment. Please try another time.\n\n ");
                    break;
                }

                int return_date = 0;
                int current_date = 0;
                struct car* available_car = NULL;
                bool valid_input = false;

                //Checking if the expected returned date is valid
                while (!valid_input) {
                    printf("Please enter the return date (yymmdd) : ");
                    scanf("%d", &return_date);

                    //To check if the date is in a valid format and a valid date.
                    if (date_validity_check(return_date)) {
                        //To get current date
                        time_t t = time(NULL);
                        struct tm tm = *localtime(&t);
                        int year = tm.tm_year % 100;
                        int month = tm.tm_mon + 1;
                        int day = tm.tm_mday;

                        current_date = (year * 10000) + (month * 100) + day;

                        valid_input = (return_date > current_date);
                    }
                    else {
                        valid_input = false;
                    }


                    if (!valid_input) {
                        printf("The return date is invalid.\n");
                    }
                };

                available_car = remove_first_from_list(&available_head);

                insert_to_list(&rented_head, available_car->plate, available_car->mileage, return_date);
                sort_list(&rented_head, true, false);
                printf("Car %s has been rented successfully!\n", available_car->plate);
                printf("Car %s added to the rented car list from the available car list successfully!\n\n", available_car->plate);

                free(available_car);
                break;
            }

            case 6: {
                printf("\n\n--------------------------\n");
                printf("Available Cars\n\n");
                print_list(available_head);
                printf("\n\n--------------------------\n");
                printf("\n\nRented Cars\n\n");
                print_list(rented_head);
                printf("\n\n--------------------------\n");
                printf("\n\nIn Repair Cars\n\n");
                print_list(repair_head);
                printf("\n\n--------------------------\n");
                printf("\n");


                break;
            }


            case 7: {
                write_list_to_file("available.txt", available_head);
                write_list_to_file("rented.txt", rented_head);
                write_list_to_file("repair.txt", repair_head);
                free_list(&available_head);
                free_list(&rented_head);
                free_list(&repair_head);
                return 0;
            }
            
            default: {
                printf("Please enter a valid code...\n\n");
                break;
            }
        }
    } while (true);


    return 0;
}
