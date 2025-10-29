#include <stdio.h>
#include<string.h>

// add book
void addbook(int isbns[], char titles[][50], float prices[], int quantities[], int *count){
    if(*count >= 100){
        printf("Full stock\n");
        return;
    }
    int isbn, i, duplicate = 0;
    printf("Enter ISBN: ");
    scanf("%d", &isbn);

    // Check for duplicate ISBN
    for(i = 0; i < *count; i++){
        if(isbns[i] == isbn){
            printf("Error, ISBN already exists.\n");
            duplicate = 1;
            break;
        }
    }

    if(duplicate){
        return; // Don't add book if duplicate exists
    }

    // Add book details
    isbns[*count] = isbn;
    
    getchar(); // Clear input buffer
    printf("Enter title of book: ");
    fgets(titles[*count], 50, stdin);
    titles[*count][strcspn(titles[*count], "\n")] = '\0';
    
    printf("Enter Price: ");
    scanf("%f", &prices[*count]);
    
    printf("Enter Quantity: ");
    scanf("%d", &quantities[*count]);
    
    printf("Book successfully added\n");
    (*count)++; // Increment count only here
}

// process sale
void process(int isbns[], char titles[][50], float prices[], int quantities[], int count){
    if(count == 0){
        printf("No book available\n");
        return;
    }
    int isbn, qty, i, found = 0;
    printf("Enter ISBN for sale: ");
    scanf("%d", &isbn);

    for(i = 0; i < count; i++){
        if(isbns[i] == isbn){
            found = 1;
            printf("Book: %s\n", titles[i]);
            printf("Available quantity: %d\n", quantities[i]);
            printf("Enter copies sold: ");
            scanf("%d", &qty);
            if(qty > quantities[i])
                printf("Not enough stock!\n");
            else{
                quantities[i] -= qty;
                float total = prices[i] * qty;
                printf("Sale successful! Total: Rs %.2f, Remaining: %d\n", total, quantities[i]);
            }
            break;
        }
    }
    if(!found)
        printf("Book not found!\n");
}

// report
void report(int isbns[], char titles[][50], float prices[], int quantities[], int count){
    printf("\n\tLow Stock Report\n");
    if(count == 0){
        printf("No book available\n");
        return;
    }
    
    int i, found = 0;
    for(i = 0; i < count; i++){
        if(quantities[i] < 5){
            found = 1;
            printf("ISBN: %d\n", isbns[i]);
            printf("Title: %s\n", titles[i]);
            printf("Price: Rs %.2f\n", prices[i]);
            printf("Quantity: %d\n\n", quantities[i]);
        }
    }
    if(!found){
        printf("All books have sufficient stock (5 or more)\n");
    }
}

int main(){
    int isbns[100], quantities[100], count = 0, ch;
    float prices[100];
    char titles[100][50];    
    
    while(ch != 5){
        printf("\t-- Liberty Books --\n");
        printf("1. Add Book\n");
        printf("2. Process Sale\n"); 
        printf("3. Low Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch){
            case 1:
                addbook(isbns, titles, prices, quantities, &count);
                break;
            case 2:
                process(isbns, titles, prices, quantities, count);
                break;
            case 3:
                report(isbns, titles, prices, quantities, count);
                break;
            case 4:
                printf("Thank you for using Liberty Books!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
