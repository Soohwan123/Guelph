#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int value;
    struct Node* next;
};

void push(struct Node** node, int value){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->value = value;
    head->next = *node;
    *node = head;
    
    return;
}

int pop(struct Node** node){
    struct Node* temp = *node;
    if(!temp){
        return -1;
    }
    int value = temp->value;
    //맨 위 삭제
    *node = temp->next;
    free(temp);

    return value;
}


int main(void){
    struct Node* head = NULL;
    int num_of_command;
    char command[256];
    // push 나 pop 이 될떄마다 갯수 추적을 위한 count ( 정수 갯수 세기의 시간복잡도 최적화 )
    int count = 0;

    //명령어 갯수
    scanf("%d", &num_of_command);
    getchar(); // 개행 문자 제거

    for(int i = 0; i < num_of_command; i++){
        // 한 줄을 입력받기
        fgets(command, sizeof(command), stdin);

        int num1, num2;
        int n = sscanf(command, "%d %d", &num1, &num2); // 두 개의 정수 읽기

        if(n == 2){
            char *token = strtok(command, " ");

            push(&head, num2);
            count++;    // 하나가 들어왔으니 추가
        } else {
            num1 = atoi(command);

            switch (num1) {
                case 2 : {
                    if(head == NULL){
                        printf("%d\n", -1);
                    } else {
                        int result = pop(&head);
                        printf("%d\n", result);
                        count--; // 빠졌으니 제거
                    }
                    break;
                }

                case 3 : {
                    printf("%d\n", count);

                    break;
                }

                case 4 : {
                    if(head == NULL){
                        printf("%d\n", 1); 
                    } else {
                        printf("%d\n", 0);
                    }

                    break;
                }

                case 5 : {
                    if(head == NULL){
                        printf("%d\n", -1);
                    } else{
                        printf("%d\n", head->value);
                    }
                    break;
                }
            
            }
        }

        
    }

    return 0;
}