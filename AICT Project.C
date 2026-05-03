#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Helper Functions for Online Compilers ---

// Clears the screen (Uses "clear" for online Linux servers)
void clearScreen() {
    system("clear"); // Note: If you run this locally on Windows later, change "clear" to "cls"
}

// Cleans the input buffer to prevent skipping inputs
void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Pauses the screen until the user presses Enter
void waitForKey() {
    printf("\n Press Enter to continue...");
    getchar(); 
}

// --- Original Program Functions ---

char getChoice() {
    char ch;
    printf("\n Enter your choice: ");
    scanf(" %c", &ch);
    cleanBuffer(); // Clean up the newline left by scanf
    return ch;
}

int getQuantity() {
    int qty;
    printf("\n Enter quantity: ");
    while (scanf("%d", &qty) != 1) {
        printf(" Invalid input. Enter a number: ");
        cleanBuffer();
    }
    cleanBuffer(); // Clean up the newline left by scanf
    return qty;
}

char displayMenu(char menu[][30], int size, char start, char end) {
    char choice;
    int valid;
    do {
        clearScreen();
        for(int i = 0; i < size; i++)
            printf("\n %d - %s", i + 1, menu[i]);
        printf("\n");
        
        choice = getChoice();
        
        if(choice >= start && choice <= end) {
            valid = 1;
        } else {
            valid = 0;
            printf("\n Invalid choice!");
            waitForKey();
        }
    } while(!valid);
    return choice;
}

void computeBill(int bill, int orderType) {
    int discount = 0;
    int tax = 0;
    int deliveryCharges = 0;
    int finalBill = 0;
    
    clearScreen();
    
    if(bill >= 8000)
        discount = bill * 25 / 100;
    else if(bill >= 5000)
        discount = bill * 20 / 100;
    else if(bill >= 3000)
        discount = bill * 10 / 100;
        
    tax = bill * 5 / 100;
    
    if(orderType == 1) {
        if(bill >= 2000)
            deliveryCharges = 0;
        else if(bill >= 1000)
            deliveryCharges = 50;
        else
            deliveryCharges = 100;
    }
    
    finalBill = bill - discount + tax + deliveryCharges;
    
    printf("\n ==================================");
    if(orderType == 1)
        printf("\n   ONLINE ORDER - HOME DELIVERY");
    else
        printf("\n   DINE-IN ORDER");
    printf("\n ==================================");
    printf("\n Total Bill      : Rs %d", bill);
    printf("\n Discount        : Rs %d", discount);
    printf("\n Tax (5%%)        : Rs %d", tax);
    
    if(orderType == 1) {
        printf("\n Delivery Charges: Rs %d", deliveryCharges);
        if(deliveryCharges == 0)
            printf(" (FREE)");
    }
    
    printf("\n ----------------------------------");
    printf("\n Final Amount    : Rs %d", finalBill);
    printf("\n ==================================");
    
    if(orderType == 1) {
        printf("\n Your order will be delivered in");
        printf("\n 30-45 minutes to your address.");
    }
    printf("\n Thank you for ordering!");
}

int main() {
    char orderTypeMenu[][30] = {
        "Dine-In",
        "Online Order (Home Delivery)",
        "Exit"
    };
    char mainMenu[][30] = {
        "Burgers", "Pizza", "Rolls", "Sandwich", 
        "BBQ", "Chinese", "Drinks", "Desserts", "Check Out"
    };
    char burgerMenu[][30] = {
        "Spicy Burger", "Tikka Burger", "Plain Burger", "Cheese Burger", 
        "Double Patty", "Mushroom Burger", "Veggie Burger", "Fish Burger", "Go Back"
    };
    int burgerPrices[] = {500, 550, 450, 600, 750, 650, 480, 700};
    
    char pizzaMenu[][30] = {
        "Large Pizza", "Medium Pizza", "Small Pizza", "Stuffed Crust", 
        "BBQ Pizza", "Pepperoni Pizza", "Veggie Pizza", "Margherita", "Go Back"
    };
    int pizzaPrices[] = {1800, 1400, 1000, 2200, 2000, 1900, 1600, 1500};
    
    char rollMenu[][30] = {
        "Chicken Roll", "Beef Roll", "Veg Roll", "Zinger Roll", 
        "Cheese Roll", "Tikka Roll", "Seekh Kabab Roll", "Egg Roll", "Go Back"
    };
    int rollPrices[] = {400, 450, 350, 500, 550, 480, 520, 380};
    
    char sandwichMenu[][30] = {
        "Club Sandwich", "Chicken Sandwich", "BBQ Sandwich", "Grilled Sandwich", 
        "Veg Sandwich", "Tuna Sandwich", "Egg Sandwich", "Turkey Sandwich", "Go Back"
    };
    int sandwichPrices[] = {600, 550, 650, 500, 450, 680, 480, 720};
    
    char bbqMenu[][30] = {
        "Chicken Tikka", "Chicken Boti", "Malai Boti", "Beef Kabab", 
        "BBQ Platter", "Seekh Kabab", "Reshmi Kabab", "Tandoori Chicken", "Go Back"
    };
    int bbqPrices[] = {900, 850, 950, 800, 1800, 820, 880, 1200};
    
    char chineseMenu[][30] = {
        "Chicken Chowmein", "Chicken Manchurian", "Sweet & Sour", "Fried Rice", 
        "Kung Pao Chicken", "Noodle Soup", "Spring Rolls", "Hot & Sour Soup", "Go Back"
    };
    int chinesePrices[] = {700, 750, 800, 650, 850, 680, 500, 550};
    
    char drinkMenu[][30] = {
        "Cola", "Orange Juice", "Mint Margarita", "Cold Coffee", 
        "Milk Shake", "Lemonade", "Mango Juice", "Green Tea", "Go Back"
    };
    int drinkPrices[] = {200, 250, 300, 350, 400, 220, 280, 180};
    
    char dessertMenu[][30] = {
        "Chocolate Cake", "Ice Cream", "Brownie", "Custard", 
        "Fruit Salad", "Cheesecake", "Pudding", "Tiramisu", "Go Back"
    };
    int dessertPrices[] = {300, 250, 280, 200, 220, 350, 240, 380};

    int bill = 0;
    char choice, subChoice, orderTypeChoice;
    int checkout = 0;
    int quantity = 0;
    int price = 0;
    int orderType = 0;
    
    char customerName[50];
    char customerPhone[15];
    char customerAddress[100];
    
    clearScreen();
    printf("\n\n");
    printf("\n ==========================================");
    printf("\n   WELCOME TO KRISPO RESTAURANT");
    printf("\n ==========================================");
    waitForKey();

    orderTypeChoice = displayMenu(orderTypeMenu, 3, '1', '3');
    
    if(orderTypeChoice == '3') {
        clearScreen();
        printf("\n Thank you for visiting!");
        waitForKey();
        return 0;
    }
    
    if(orderTypeChoice == '1') {
        orderType = 0;
        clearScreen();
        printf("\n ==================================");
        printf("\n   DINE-IN ORDER");
        printf("\n ==================================");
        printf("\n You have selected Dine-In.");
        printf("\n No delivery charges will apply.");
        waitForKey();
    } else if(orderTypeChoice == '2') {
        orderType = 1;
        clearScreen();
        printf("\n ==================================");
        printf("\n   ONLINE ORDER - HOME DELIVERY");
        printf("\n ==================================");
        printf("\n Please provide your details:");
        
        printf("\n\n Enter your name: ");
        fgets(customerName, sizeof(customerName), stdin);
        customerName[strcspn(customerName, "\n")] = 0; // Remove newline character
        
        printf("\n Enter your phone: ");
        fgets(customerPhone, sizeof(customerPhone), stdin);
        customerPhone[strcspn(customerPhone, "\n")] = 0;
        
        printf("\n Enter your address: ");
        fgets(customerAddress, sizeof(customerAddress), stdin);
        customerAddress[strcspn(customerAddress, "\n")] = 0;
        
        printf("\n ----------------------------------");
        printf("\n Delivery Charges:");
        printf("\n Rs 100 (Orders below Rs 1000)");
        printf("\n Rs 50  (Orders Rs 1000-1999)");
        printf("\n FREE   (Orders Rs 2000 & above)");
        printf("\n ==================================");
        waitForKey();
    }
    
    do {
        choice = displayMenu(mainMenu, 9, '1', '9');
        switch(choice) {
            case '1':
                subChoice = displayMenu(burgerMenu, 9, '1', '9');
                if(subChoice >= '1' && subChoice <= '8') {
                    price = burgerPrices[subChoice - '1'];
                    clearScreen();
                    printf("\n ==================================");
                    printf("\n   %s", burgerMenu[subChoice - '1']);
                    printf("\n ==================================");
                    printf("\n Price: Rs %d", price);
                    quantity = getQuantity();
                    if(quantity > 0) {
                        bill += price * quantity;
                        printf("\n ----------------------------------");
                        printf("\n Item added to cart!");
                        printf("\n Quantity: %d", quantity);
                        printf("\n Subtotal: Rs %d", price * quantity);
                        printf("\n ==================================");
                    }
                    waitForKey();
                }
                break;
            case '2':
                subChoice = displayMenu(pizzaMenu, 9, '1', '9');
                if(subChoice >= '1' && subChoice <= '8') {
                    price = pizzaPrices[subChoice - '1'];
                    clearScreen();
                    printf("\n ==================================");
                    printf("\n   %s", pizzaMenu[subChoice - '1']);
                    printf("\n ==================================");
                    printf("\n Price: Rs %d", price);
                    quantity = getQuantity();
                    if(quantity > 0) {
                        bill += price * quantity;
                        printf("\n ----------------------------------");
                        printf("\n Item added to cart!");
                        printf("\n Quantity: %d", quantity);
                        printf("\n Subtotal: Rs %d", price * quantity);
                        printf("\n ==================================");
                    }
                    waitForKey();
                }
                break;
            case '3':
                subChoice = displayMenu(rollMenu, 9, '1', '9');
                if(subChoice >= '1' && subChoice <= '8') {
                    price = rollPrices[subChoice - '1'];
                    clearScreen();
                    printf("\n ==================================");
                    printf("\n   %s", rollMenu[subChoice - '1']);
                    printf("\n ==================================");
                    printf("\n Price: Rs %d", price);
                    quantity = getQuantity();
                    if(quantity > 0) {
                        bill += price * quantity;
                        printf("\n ----------------------------------");
                        printf("\n Item added to cart!");
                        printf("\n Quantity: %d", quantity);
                        printf("\n Subtotal: Rs %d", price * quantity);
                        printf("\n ==================================");
                    }
                    waitForKey();
                }
                break;
            case '4':
                subChoice = displayMenu(sandwichMenu, 9, '1', '9');
                if(subChoice >= '1' && subChoice <= '8') {
                    price = sandwichPrices[subChoice - '1'];
                    clearScreen();
                    printf("\n ==================================");
                    printf("\n   %s", sandwichMenu[subChoice - '1']);
                    printf("\n ==================================");
                    printf("\n Price: Rs %d", price);
                    quantity = getQuantity();
                    if(quantity > 0) {
                        bill += price * quantity;
                        printf("\n ----------------------------------");
                        printf("\n Item added to cart!");
                        printf("\n Quantity: %d", quantity);
                        printf("\n Subtotal: Rs %d", price * quantity);
                        printf("\n ==================================");
                    }
                    waitForKey();
                }
                break;
            case '5':
                subChoice = displayMenu(bbqMenu, 9, '1', '9');
                if(subChoice >= '1' && subChoice <= '8') {
                    price = bbqPrices[subChoice - '1'];
                    clearScreen();
                    printf("\n ==================================");
                    printf("\n   %s", bbqMenu[subChoice - '1']);
                    printf("\n ==================================");
                    printf("\n Price: Rs %d", price);
                    quantity = getQuantity();
                    if(quantity > 0) {
                        bill += price * quantity;
                        printf("\n ----------------------------------");
                        printf("\n Item added to cart!");
                        printf("\n Quantity: %d", quantity);
                        printf("\n Subtotal: Rs %d", price * quantity);
                        printf("\n ==================================");
                    }
                    waitForKey();
                }
                break;
            case '6':
                subChoice = displayMenu(chineseMenu, 9, '1', '9');
                if(subChoice >= '1' && subChoice <= '8') {
                    price = chinesePrices[subChoice - '1'];
                    clearScreen();
                    printf("\n ==================================");
                    printf("\n   %s", chineseMenu[subChoice - '1']);
                    printf("\n ==================================");
                    printf("\n Price: Rs %d", price);
                    quantity = getQuantity();
                    if(quantity > 0) {
                        bill += price * quantity;
                        printf("\n ----------------------------------");
                        printf("\n Item added to cart!");
                        printf("\n Quantity: %d", quantity);
                        printf("\n Subtotal: Rs %d", price * quantity);
                        printf("\n ==================================");
                    }
                    waitForKey();
                }
                break;
            case '7':
                subChoice = displayMenu(drinkMenu, 9, '1', '9');
                if(subChoice >= '1' && subChoice <= '8') {
                    price = drinkPrices[subChoice - '1'];
                    clearScreen();
                    printf("\n ==================================");
                    printf("\n   %s", drinkMenu[subChoice - '1']);
                    printf("\n ==================================");
                    printf("\n Price: Rs %d", price);
                    quantity = getQuantity();
                    if(quantity > 0) {
                        bill += price * quantity;
                        printf("\n ----------------------------------");
                        printf("\n Item added to cart!");
                        printf("\n Quantity: %d", quantity);
                        printf("\n Subtotal: Rs %d", price * quantity);
                        printf("\n ==================================");
                    }
                    waitForKey();
                }
                break;
            case '8':
                subChoice = displayMenu(dessertMenu, 9, '1', '9');
                if(subChoice >= '1' && subChoice <= '8') {
                    price = dessertPrices[subChoice - '1'];
                    clearScreen();
                    printf("\n ==================================");
                    printf("\n   %s", dessertMenu[subChoice - '1']);
                    printf("\n ==================================");
                    printf("\n Price: Rs %d", price);
                    quantity = getQuantity();
                    if(quantity > 0) {
                        bill += price * quantity;
                        printf("\n ----------------------------------");
                        printf("\n Item added to cart!");
                        printf("\n Quantity: %d", quantity);
                        printf("\n Subtotal: Rs %d", price * quantity);
                        printf("\n ==================================");
                    }
                    waitForKey();
                }
                break;
            case '9':
                if(bill > 0) {
                    checkout = 1;
                } else {
                    clearScreen();
                    printf("\n ==================================");
                    printf("\n   Your cart is empty!");
                    printf("\n ==================================");
                    printf("\n Please add items before checkout.");
                    waitForKey();
                }
                break;
        }
    } while(!checkout);
    
    if(orderType == 1) {
        clearScreen();
        printf("\n ==================================");
        printf("\n   DELIVERY INFORMATION");
        printf("\n ==================================");
        printf("\n Customer: %s", customerName);
        printf("\n Phone: %s", customerPhone);
        printf("\n Address: %s", customerAddress);
        printf("\n ==================================");
        waitForKey();
    }
    
    computeBill(bill, orderType);
    waitForKey();
    return 0;
}
