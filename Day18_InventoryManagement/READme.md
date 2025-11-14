# Day18_inventoryManagemnt
*Student Name:* digamarthi koushik  
*Roll No:* AP25110090192
*Challenge:* Day 18 -  Inventory Management

## Description
This program is a simple inventory manager for up to 10 products.  
It stores each product’s ID, name, stock, and price.  
Users can list products, find total value, 
check the highest and lowest valued items, or search by ID.  
It keeps running until the user exits

## Build Commands
### Linux/macOS:
```bash
mkdir -p build
gcc -std=c11 -Wall -Wextra -O2 main.c -o build/program

how many products? (max 10): 2

product 1:
id: 1
name: earphones
stock: 10
rate: 400

product 2:
id: 2
name: headphones
stock: 20
rate: 600

--- menu ---
1. list products
2. total value
3. max and min value product
4. search by id
5. exit
option: 1

products:

id: 1
name: earphones
stock: 10
rate: 400.00

id: 2
name: headphones
stock: 20
rate: 600.00

--- menu ---
1. list products
2. total value
3. max and min value product
4. search by id
5. exit
option: 2

total inventory value: 16000.00

--- menu ---
1. list products
2. total value
3. max and min value product
4. search by id
5. exit
option: 3

max value product:
id: 2
name: headphones
value: 12000.00

min value product:
id: 1
name: earphones
value: 4000.00

--- menu ---
1. list products
2. total value
3. max and min value product
4. search by id
5. exit
option: 4
enter id: 3

not found: 3

--- menu ---
1. list products
2. total value
3. max and min value product
4. search by id
5. exit
option: 4
enter id: 2

found!
id: 2
name: headphones
stock: 20
rate: 600.00

--- menu ---
1. list products
2. total value
3. max and min value product
4. search by id
5. exit
option: 5

bye!
