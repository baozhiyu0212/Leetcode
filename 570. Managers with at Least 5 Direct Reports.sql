# Write your MySQL query statement below

#select managerid, count(*) from employee where managerid is not null group by managerid;

#select t.managerid from (select managerid, count(*) as num from employee where managerid is not null group by managerid) t where t.num>=5;

select e.name  as Name
from employee e
join (select t.managerid from (select managerid, count(*) as num from employee where managerid is not null group by managerid) t where t.num>=5) m
on e.id = m.managerid
