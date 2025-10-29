#include <stdio.h>
#include <string.h>

void info(char name[], char cnic[]){
    printf("Enter your name: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';   // remove newline space

    printf("Enter your CNIC: ");
    fgets(cnic, 25, stdin);
    cnic[strcspn(cnic, "\n")] = '\0';

    printf("Customer details saved.\n");
}

void display(int code[], int stock[], float price[], int n){
    int i;
    printf("\nProduct Code\tQuantity\tPrice\n");
    for(i=0; i<n; i++){
        printf("%03d\t\t%d\t\t%.2f\n", code[i], stock[i], price[i]);
    }
}

void addandupdate(int code[], int stock[], float price[], int n, int cartCode[], int cartQty[], int *cartCount){
    int c, q, found = 0;
    printf("\nEnter product code to add: ");
    scanf("%d", &c);
    printf("Enter quantity: ");
    scanf("%d", &q);

    for(int i=0; i<n; i++){
        if(code[i] == c){
            found = 1;
            if(q <= stock[i]){
                cartCode[*cartCount] = c;
                cartQty[*cartCount] = q;
                (*cartCount)++;
                stock[i] -= q;
                printf("Added to cart and inventory updated!\n");
            } else {
                printf("Not enough stock\n");
            }
            break;
        }
    }
    if(!found)
        printf("Product not found.\n");
}

void invoice(char name[], char cnic[], int cartCode[], int cartQty[], int cartCount, int code[], float price[], int n){
    printf("\n---INVOICE---\n");
    printf("Customer Name: %s\nCNIC: %s\n", name, cnic);
    printf("\nCode\tQty\tPrice\tSubtotal\n");

    float total = 0;
    for(int i=0; i<cartCount; i++){
        for(int j=0; j<n; j++){
            if(cartCode[i] == code[j]){
                float sub = cartQty[i] * price[j];
                printf("%03d\t%d\t%.2f\t%.2f\n", code[j], cartQty[i], price[j], sub);
                total += sub;
            }
        }
    }

    printf("\nTotal Bill: %.2f\n", total);

    char promo[20];
    printf("Enter promocode (if any): ");
    scanf("%s", promo);

    if(strcmp(promo, "Eid2025") == 0){
        float discount = total * 0.25;
        printf("Promocode applied! 25%% off\n");
        printf("Discount: %.2f\n", discount);
        printf("Final Bill: %.2f\n", total - discount);
    } else {
        printf("No discount applied.\n");
        printf("Final Bill: %.2f\n", total);
    }
    printf("\n\n");
}

int main(){
    int code[4] = {1, 2, 3, 4};
    int stock[4] = {50, 10, 20, 8};
    float price[4] = {100, 200, 300, 150};
    int cartCode[20], cartQty[20];
    int cartCount = 0;
    int choice;
    char name[50], cnic[25];



    while(1){
        printf("\n===== SUPERMARKET MENU =====\n");
        printf("1. Customer Information\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item to Cart (Auto Update Inventory)\n");
        printf("4. Show Invoice\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // clear new line space

        switch(choice){
            case 1:
                info(name, cnic);
                break;
            case 2:
                display(code, stock, price, 4);
                break;
            case 3:
                addandupdate(code, stock, price, 4, cartCode, cartQty, &cartCount);
                break;
            case 4:
                invoice(name, cnic, cartCode, cartQty, cartCount, code, price, 4);
                break;
            case 5:
                printf("Exiting system... Thank you!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

