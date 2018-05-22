# Write your MySQL query statement below
select e1.name as Employee 
from employee e1 
join employee e2 on e1.managerid = e2.id and e2.salary<e1.salary;
