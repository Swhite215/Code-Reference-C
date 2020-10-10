float inputDeposit() {
    float deposit;
    char input[100];

    do {
        printf("Enter the amount to deposit: ");
        scanf("%s",input);

        if (!(deposit = strtof(input, 0))) {
            printf("Please enter a number greater than 0.\n");
            continue;
        }

        if (deposit < 0) {
            printf("Please enter a number greater than 0.\n");
            continue;
        } else{
            break;
        }

    } while (deposit < 0 || !(deposit = strtof(input, NULL)));    

    return balance + deposit;
}