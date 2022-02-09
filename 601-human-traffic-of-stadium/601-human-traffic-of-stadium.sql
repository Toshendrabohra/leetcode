# Write your MySQL query statement below
select distinct r.id, r.visit_date, r.people
from stadium r,
(select a.id as FROM_ID, a.id+2 as TO_ID
from stadium a, stadium b, stadium c
where a.id+1 = b.id
and b.id+1 = c.id
and a.people >= 100
and b.people >= 100
and c.people >= 100) b
where r.id between b.FROM_ID and b.TO_ID;
