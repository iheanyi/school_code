SELECT p.PROD_DESC
FROM PRODUCT p, SALE s
where p.prod_id = s.prod_id
and s.qty = (SELECT MAX(maxsale.qty) from sale maxsale);