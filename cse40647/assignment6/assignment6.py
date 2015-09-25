#!/usr/bin/python

def create_transaction_list(filename):
    T = []
    infile = open(filename)
    for line in infile:
        T.append(line.strip().split(',')[1:])
    return T

def create_products():
    products = dict()
    infile = open('bakery/products.csv')
    for line in infile:
        product_line = line.strip().split(',')
        products[product_line[0]] = product_line[1]
    print products
    return products
#T = []
#infile = open('bakery/1000/1000-out1.csv')
#for line in infile:
#    T.append(line.strip().split(',')[1:])

transactions = create_transaction_list('bakery/1000/1000-out1.csv')
print transactions
products = create_products()
print products
