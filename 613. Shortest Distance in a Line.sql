# Write your MySQL query statement below
#select p1.x as x1,p2.x as x2 from point p1 join point p2 on p1.x!=p2.x;
select min(abs(t.x1-t.x2)) as shortest
from (select p1.x as x1,p2.x as x2 from point p1 join point p2 on p1.x!=p2.x) t;
