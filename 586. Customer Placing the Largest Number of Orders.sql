# Write your MySQL query statement below
#select count(*) as times from orders group by customer_number order by times desc limit 1;
#select customer_number,count(*) as times from orders group by customer_number;
select t.customer_number from (select customer_number,count(*) as times from orders group by customer_number) t
where t.times = (select count(*) as times from orders group by customer_number order by times desc limit 1);
