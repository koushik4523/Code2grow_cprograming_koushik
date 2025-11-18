#include <stdio.h>

#define MAX_PRODUCTS 20
#define RACK_SIZE 3

// These arrays store product information
int productID[MAX_PRODUCTS];
int productQuantity[MAX_PRODUCTS];
int productPrice[MAX_PRODUCTS];
int totalProducts = 0;

// 3x3 rack for storage
int rack[RACK_SIZE][RACK_SIZE];

// Function declarations
void addProduct();
void searchProduct();
void updateQuantity();
void rackReport();
void stockReport();
void showAllProducts();
int findProduct(int id);

int main() {

    int choice;

    
    for(int i = 0; i < RACK_SIZE; i++)
        for(int j = 0; j < RACK_SIZE; j++)
            rack[i][j] = 0;

    while(1) {

        // Main menu
        printf("\n=========== WAREHOUSE MENU ===========\n");
        printf("1. Add a new product\n");
        printf("2. Search a product\n");
        printf("3. Update product quantity\n");
        printf("4. Rack information report\n");
        printf("5. Stock value report\n");
        printf("6. Show all products\n");
        printf("7. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        
        switch(choice) {

            case 1: addProduct(); break;
            case 2: searchProduct(); break;
            case 3: updateQuantity(); break;
            case 4: rackReport(); break;
            case 5: stockReport(); break;
            case 6: showAllProducts(); break;
            case 7: 
                printf("Thank you! Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Adds a new product to the warehouse
void addProduct() {

    if(totalProducts >= MAX_PRODUCTS) {
        printf("Warehouse is full! Cannot add more products.\n");
        return;
    }

    int id, qty, price;

    printf("Enter product ID: ");
    scanf("%d", &id);

    // Check if product with same ID already exists
    if(findProduct(id) != -1) {
        printf("A product with this ID already exists!\n");
        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &qty);

    printf("Enter price: ");
    scanf("%d", &price);

    // Store the product details
    productID[totalProducts] = id;
    productQuantity[totalProducts] = qty;
    productPrice[totalProducts] = price;

    totalProducts++;

    printf("Product added successfully!\n");
}

// Finds a product by ID and returns its index
int findProduct(int id) {

    for(int i = 0; i < totalProducts; i++) {
        if(productID[i] == id)
            return i;
    }

    return -1;
}

// Searches for a product and shows its details
void searchProduct() {

    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);

    int index = findProduct(id);

    if(index == -1) {
        printf("Product not found.\n");
    } 
    else {
        printf("\nProduct Found!\n");
        printf("ID: %d\n", productID[index]);
        printf("Quantity: %d\n", productQuantity[index]);
        printf("Price: %d\n", productPrice[index]);
    }
}

// Updates the quantity of a product
void updateQuantity() {

    int id;
    printf("Enter product ID to update quantity: ");
    scanf("%d", &id);

    int index = findProduct(id);

    if(index == -1) {
        printf("Product not found.\n");
        return;
    }

    int change;
    printf("Enter change in quantity (positive or negative): ");
    scanf("%d", &change);

    if(productQuantity[index] + change < 0) {
        printf("Quantity cannot go below zero.\n");
        return;
    }

    productQuantity[index] += change;
    printf("Updated quantity: %d\n", productQuantity[index]);
}

// Gives rack information like max, min, total items
void rackReport() {

    printf("Enter values for 3x3 rack:\n");

    int total = 0;
    int max = 0, min = 0;
    int maxR = 0, maxC = 0, minR = 0, minC = 0;

    // Fill rack
    for(int i = 0; i < RACK_SIZE; i++) {
        for(int j = 0; j < RACK_SIZE; j++) {
            printf("Rack[%d][%d]: ", i, j);
            scanf("%d", &rack[i][j]);
        }
    }

    max = min = rack[0][0];

    // Calculate max, min, total
    for(int i = 0; i < RACK_SIZE; i++) {
        for(int j = 0; j < RACK_SIZE; j++) {

            if(rack[i][j] > max) {
                max = rack[i][j];
                maxR = i;
                maxC = j;
            }

            if(rack[i][j] < min) {
                min = rack[i][j];
                minR = i;
                minC = j;
            }

            total += rack[i][j];
        }
    }

    printf("\n=== Rack Report ===\n");
    printf("Highest stock: %d at (%d, %d)\n", max, maxR, maxC);
    printf("Lowest stock: %d at (%d, %d)\n", min, minR, minC);
    printf("Total stock in rack: %d\n", total);
}

// Shows value of stock for each product
void stockReport() {

    if(totalProducts == 0) {
        printf("No products in warehouse.\n");
        return;
    }

    int totalValue = 0;
    int maxVal = productQuantity[0] * productPrice[0];
    int minVal = maxVal;
    int maxIndex = 0, minIndex = 0;

    printf("\n=== Stock Value Report ===\n");

    for(int i = 0; i < totalProducts; i++) {

        int value = productQuantity[i] * productPrice[i];
        printf("Product %d -> Value: %d\n", productID[i], value);

        totalValue += value;

        if(value > maxVal) {
            maxVal = value;
            maxIndex = i;
        }

        if(value < minVal) {
            minVal = value;
            minIndex = i;
        }
    }

    printf("\nHighest Value Product: %d (Value: %d)\n", productID[maxIndex], maxVal);
    printf("Lowest Value Product: %d (Value: %d)\n", productID[minIndex], minVal);
    printf("Total Warehouse Value: %d\n", totalValue);
}

// Shows all products in list
void showAllProducts() {

    if(totalProducts == 0) {
        printf("No products to show.\n");
        return;
    }

    printf("\nID\tQuantity\tPrice\tValue\n");

    for(int i = 0; i < totalProducts; i++) {
        int value = productQuantity[i] * productPrice[i];
        printf("%d\t%d\t\t%d\t%d\n",
               productID[i], productQuantity[i], 
               productPrice[i], value);
    }
}
