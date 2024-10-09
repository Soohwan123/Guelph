#include "q1.h"

/*
 * A basic menu based structure has been provided
*/

int main(){

    //Our three Linked Lists
    struct car *available_head = NULL;
	struct car *rented_head = NULL;
	struct car *repair_head = NULL;

    read_file_into_list("available.txt", available_head);
    read_file_into_list("rented.txt", rented_head);
    read_file_into_list("repair.txt", repair_head);

    int choice;

    do
    {
        prompt();

        printf("Enter a Choice: ");
        scanf("%d", &choice);
        
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
                while(!valid_input) {
                    printf("Please enter the plate number : ");
                    scanf("%s", plateNumber);

                    int length = strlen(plateNumber);
                    valid_input = (length >= 2 && length <= 8);

                    for (int i = 0; i < length && valid_input; i++) {
                        // if it's not an alphabet or a number it's false
                        if (!isalnum(plateNumber[i])) {  
                            valid_input = false;
                        }
                    }

                    if (!valid_input) {
                        printf("Invalid. The plate number must be 2-8 characters long and letters and numbers.\n");
                    }
                    else if (is_plate_in_list(available_head, plateNumber)) {
                        printf("Duplicate plate number. Please enter an unique plate number.\n");
                        valid_input = false;
                    }
                };

                //Set it as false to check mileage
                valid_input = false;

                //Checking if the mileage is valid
                while (!valid_input){
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

                insert_to_list(available_head, plateNumber, mileage, -1);
                printf("Car added successfully!\n");
                break;
            }
        
            case 2: {


                break;
            }

            case 3: {
                break;
            }

            case 4: {
                break;
            }           

            case 5: {
                break;
            }            

            case 6: {
                break;
            }


            case 7: {
                break;
            }


            default: {
                break;
            }

        }
        
    } while (true);
    

    return 0;
}