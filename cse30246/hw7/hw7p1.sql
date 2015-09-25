SELECT sp.SALPERS_NAME, sp.OFFICE
from SALESPERSON sp
WHERE EXISTS (
select *
from product p
where exists (
select *
from sale s
where sp.SALPERS_ID = s.SALPERS_ID
and p.prod_id = s.prod_id
and (p.price - p.cost) > 10
)
);