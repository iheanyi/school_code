SELECT sp.salpers_name AS "Salesperson", 
TO_CHAR(NVL(SUM(s.qty*(p.price-p.cost)), 0), '$9,9990.00') AS "Profit"
FROM SALESPERSON sp, PRODUCT p, SALE s
WHERE sp.SALPERS_ID = s.SALPERS_ID (+)
AND p.prod_id (+) = s.prod_id
GROUP BY sp.salpers_name
ORDER BY 2 DESC;