#include <stdio.h>

int main() {
    int productid[10];               
    char productname[10][50];       
    int stock[10];             
    float rate[10];            

    int count, index, opt;
    float value, maxval, minval;
    int maxidx, minidx;
    int findid, match;

    printf("=== simple inventory system ===\n");

    //products
    printf("how many products? (max 10): ");
    scanf("%d", &count);

    for(index = 0; index < count; index++) {
        printf("\nproduct %d:\n", index + 1);

        printf("id: ");
        scanf("%d", &productid[index]);

        printf("name: ");
        scanf("%s", productname[index]);

        printf("stock: ");
        scanf("%d", &stock[index]);

        printf("rate: ");
        scanf("%f", &rate[index]);
    }

    do {
        printf("\n--- menu ---\n");
        printf("1. list products\n");
        printf("2. total value\n");
        printf("3. max and min value product\n");
        printf("4. search by id\n");
        printf("5. exit\n");
        printf("option: ");
        scanf("%d", &opt);

        if(opt == 1) {
            printf("\nproducts:\n");
            for(index = 0; index < count; index++) {
                printf("\nid: %d\n", productid[index]);
                printf("name: %s\n", productname[index]);
                printf("stock: %d\n", stock[index]);
                printf("rate: %.2f\n", rate[index]);
            }
        }
        else if(opt == 2) {
            value = 0;
            for(index = 0; index < count; index++) {
                value += stock[index] * rate[index];
            }
            printf("\ntotal inventory value: %.2f\n", value);
        }
        else if(opt == 3) {
            maxval = stock[0] * rate[0];
            minval = stock[0] * rate[0];
            maxidx = 0;
            minidx = 0;
            for(index = 1; index < count; index++) {
                float prodval = stock[index] * rate[index];
                if(prodval > maxval) {
                    maxval = prodval;
                    maxidx = index;
                }
                if(prodval < minval) {
                    minval = prodval;
                    minidx = index;
                }
            }
            printf("\nmax value product:\n");
            printf("id: %d\nname: %s\nvalue: %.2f\n", productid[maxidx], productname[maxidx], maxval);

            printf("\nmin value product:\n");
            printf("id: %d\nname: %s\nvalue: %.2f\n", productid[minidx], productname[minidx], minval);
        }
        else if(opt == 4) {
            printf("enter id: ");
            scanf("%d", &findid);
            match = 0;
            for(index = 0; index < count; index++) {
                if(productid[index] == findid) {
                    match = 1;
                    printf("\nfound!\n");
                    printf("id: %d\n", productid[index]);
                    printf("name: %s\n", productname[index]);
                    printf("stock: %d\n", stock[index]);
                    printf("rate: %.2f\n", rate[index]);
                    break;
                }
            }
            if(match == 0) {
                printf("\nnot found: %d\n", findid);
            }
        }
        else if(opt == 5) {
            printf("\nbye!\n");
        }
        else {
            printf("\ninvalid!\n");
        }

    } while(opt != 5);

    return 0;
}
