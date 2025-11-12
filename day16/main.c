#include <stdio.h>

#define max_customers 10
#define max_items 5

int main() {
    int numcustomers, customerindex, itemid, itemquantity;
    char menuitems[max_items][10] = {"coffee", "tea", "sandwich", "burger", "pastry"};
    int itemprices[max_items] = {50, 30, 80, 120, 60};
    int totalsales = 0, itemcounts[max_items] = {0}, mostorderedindex = 0, maxcount = 0;

    printf("welcome to the cafe!\n");
    printf("enter the number of customers (up to 10): ");
    scanf("%d", &numcustomers);

    for (customerindex = 0; customerindex < numcustomers; customerindex++) {
        printf("\ncustomer %d\n", customerindex + 1);
        int customertotal = 0, numitems;
        printf("how many items would you like to order? ");
        scanf("%d", &numitems);

        for (int itemindex = 0; itemindex < numitems; itemindex++) {
            printf("enter item number (1-coffee, 2-tea, 3-sandwich, 4-burger, 5-pastry): ");
            scanf("%d", &itemid);
            printf("enter quantity: ");
            scanf("%d", &itemquantity);

            if (itemid < 1 || itemid > max_items) {
                printf("invalid item number. please try again.\n");
                itemindex--;
            } else {
                customertotal += itemprices[itemid - 1] * itemquantity;
                itemcounts[itemid - 1] += itemquantity;
            }
        }

        printf("total bill for customer %d: Rs.%d\n", customerindex + 1, customertotal);

        totalsales += customertotal;
    }

    // Find most ordered item
    for (int i = 0; i < max_items; i++) {
        if (itemcounts[i] > maxcount) {
            maxcount = itemcounts[i];
            mostorderedindex = i;
        }
    }

    // Calculate total items sold
    int total_items_sold = 0;
    for (int i = 0; i < max_items; i++) {
        total_items_sold += itemcounts[i];
    }

    printf("\n--- daily summary ---\n");
    printf("total revenue: Rs.%d\n", totalsales);
    printf("total items sold: %d\n", total_items_sold);
    printf("most ordered item: %s (%d times)\n", menuitems[mostorderedindex], maxcount);

    return 0;
}
