#include <stdio.h>
#include <string.h>


void toggleBits(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] ^= (1 << 1); 
        str[i] ^= (1 << 4);  
    }
}

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {       
        char temp = str[i];       // store first half string
        str[i] = str[len - i - 1];      // replace with right side char
        str[len - i - 1] = temp;     // store in temp
    }
}


void encodeMessage(char message[]) {
    reverseString(message); 
    toggleBits(message);     
    printf("\nEncoded Message: %s\n", message);
}


void decodeMessage(char message[]) {
    toggleBits(message);    
    reverseString(message);  
    printf("\nDecoded Message: %s\n", message);
}

int main() {
    char message[200];
    int choice;

    do {
        printf("-- Message Encoder/Decoder --\n");
        printf("1 Encode Message\n");
        printf("2 Decode Message\n");
        printf("3 Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar ();
        switch (choice) {
            case 1:
                printf("Enter message to encode: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0';
                encodeMessage(message);
                break;

            case 2:
                printf("Enter message to decode: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0';
                decodeMessage(message);
                break;

            case 3:
                printf("Thankyou\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    } while(1);
}

