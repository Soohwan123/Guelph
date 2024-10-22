#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Person{
    int order_number;
    struct Person* next;
};

void push(struct Person** head, int order_number){
    struct Person* tmp = (struct Person*)malloc(sizeof(struct Person));
    tmp->order_number = order_number;
    tmp->next = *head;
    *head = tmp;
    return;
}

int pop(struct Person** head){
    struct Person* tmp = *head;
    int popped_value = tmp->order_number;

    *head = tmp->next;
    free(tmp);

    return popped_value;
}

int peek(struct Person* head){
    struct Person* tmp = head;
    if(tmp == NULL){
        return -1;
    }

    return tmp->order_number;
}


int main(void){
    //count 변수는 1씩 늘어나면서 원래 들어가야 하는 사람의 순서를 나타내 비교한다.
    int total_people;
    int count = 1;
    int flag = 1;
    char user_input[2002];
    char* token;

    //스택
    struct Person* head = NULL;

    scanf("%d", &total_people);
    //개행
    getchar();

    fgets(user_input, sizeof(user_input), stdin);
    // 입력된 문자열에서 개행 문자를 제거
    user_input[strcspn(user_input, "\n")] = 0;

    // 공백을 기준으로 문자열을 분리
    token = strtok(user_input, " ");


    while(1){
        int number;
        if(token == NULL && head == NULL){
            break;
        }

        if(head != NULL){
            while(peek(head) == count){
                pop(&head);
                count++;
            }

            if(token == NULL && head == NULL){
                break;
            }

            if(token == NULL && peek(head) != count){
                flag = 0;
                break;
            }
        }

        if(token != NULL){
            number = atoi(token);
            if(number == count){
                count++;
            } else {
                push(&head, number);
                int head_num = peek(head);
                int next_num = peek(head->next);

                if(head != NULL && next_num != -1 && head_num > next_num){
                    flag = 0;
                    break;
                }
            }

            // 다음 토큰 찾기
            token = strtok(NULL, " "); 
        }   
    }


    if(flag == 1){
        printf("Nice");
    } else {
        printf("Sad");
    }

    return 0;
}