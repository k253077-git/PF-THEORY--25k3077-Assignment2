#include <stdio.h>

void updateSector(int grid[2][2]) {
    int r, c;
    int opt, act;
    int bitValue;

    printf("Enter row (1-2) and column (1-2): ");
    scanf("%d %d", &r, &c);
    r--; c--;  

    printf("Choose what to change:\n");
    printf("1. Power\n");
    printf("2. Overload\n");
    printf("3. Maintenance\n");
    scanf("%d", &opt);

    printf("1. Turn ON / Set\n");
    printf("2. Turn OFF / Clear\n");
    scanf("%d", &act);

    if (opt == 1) bitValue = 1;
    else if (opt == 2) bitValue = 2;
    else if (opt == 3) bitValue = 4;
    else {
        printf("Invalid option!\n");
        return;
    }

    if (act == 1)
        grid[r][c] = grid[r][c] | bitValue;   
    else if (act == 2)
        grid[r][c] = grid[r][c] & (~bitValue); 
    else {
        printf("Invalid action!\n");
        return;
    }

    printf("Sector (%d,%d) updated.\n", r+1, c+1);
}

void checkSector(int grid[2][2]) {
    int r, c;
    printf("Enter row and column to check: ");
    scanf("%d %d", &r, &c);
    r--; c--;

    int value = grid[r][c];

    if (value & 1)
        printf("Power: ON\n");
    else
        printf("Power: OFF\n");

    if (value & 2)
        printf("Overload: YES\n");
    else
        printf("Overload: NO\n");

    if (value & 4)
        printf("Maintenance: REQUIRED\n");
    else
        printf("Maintenance: OK\n");
}

void runCheckup(int grid[2][2]) {
    int overload = 0, maintenance = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (grid[i][j] & 2) 
                overload++;
            if (grid[i][j] & 4) 
                maintenance++;
        }
    }

    printf("\nSystem Checkup Report:\n");
    printf("Overloaded sectors: %d\n", overload);
    printf("Maintenance needed: %d\n", maintenance);
}


int main() {
    int grid[2][2] = {0}; 
    int choice;

    while (1) {
    	printf("--choose option--");
        printf("1.Update a sector\n");
        printf("2.query sector\n");
        printf("3.Run system diagnos\n");
        printf("0.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            updateSector(grid);
        else if (choice == 2)
            checkSector(grid);
        else if (choice == 3)
            runCheckup(grid);
        else if (choice == 0){
		
        printf("Thankyou");
            break;
        }else
            printf("invalid choice\n");
    }
    return 0;
}

