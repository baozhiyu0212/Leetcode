# Write your MySQL query statement below
select distinct c1.seat_id from cinema c1
join cinema c2 
on c2.free = 1 and c1.free = 1 and (c2.seat_id = c1.seat_id + 1 or c2.seat_id = c1.seat_id -1)
