#include "header.h" 

int main() {
    ST *node = NULL;
    char choice,ch;
       
lable:
        printf("\n--- Students Record Management ---\n");
        printf("[A] Add new Student Record\n");
        printf("[D] Delete Student Record\n");
        printf("[M] Modify Student Record\n");
        printf("[S] Show All the Student Records\n");
        printf("[T] Sort Student Records\n");
        printf("[V] Save Record\n");
        printf("[E] Exit Program\n");
	printf("-------------------------------------\n");
        
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case 'A':
            case 'a':
                add(&node);
                goto lable;
            case 'D':
            case 'd':
                delete(&node);
                goto lable;
            case 'M':
            case 'm':
                modify(&node);
                goto lable;
            case 'S':
            case 's':
                display(node);
                goto lable;
            case 'T':
            case 't':
                sort(&node,node);
                goto lable;
            case 'V':
            case 'v':
                save(node);
                goto lable;
            case 'E':
            case 'e':ex(node);
                printf("Exiting program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
		goto lable;
        }

    return 0;
}
