column prod_desc heading Product
column cust_name heading Customer
column price heading Price format $99,999.99
column qty heading Quantity
column total heading 'Total Price' format $99,999.99
break on CUST_NAME skip 1 on report

compute sum label 'Order Price' of total on cust_name

set pagesize 24
set newpage 0
set linesize 120

SELECT c.CUST_NAME, p.prod_desc,
p.price, s.qty, p.price*s.qty total
FROM CUSTOMER c, PRODUCT p, SALE s
WHERE c.CUST_ID = s.CUST_ID
AND p.prod_id = s.prod_id
order by c.CUST_NAME