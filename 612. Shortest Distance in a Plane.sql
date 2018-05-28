# Write your MySQL query statement below

select min(round(sqrt((t.x1-t.x2)*(t.x1-t.x2)+(t.y1-t.y2)*(t.y1-t.y2)),2)) as shortest

from (select p1.x as x1, p1.y as y1, p2.x as x2, p2.y as y2 from point_2d p1 join point_2d p2 on p1.x!=p2.x or p1.y!=p2.y) t
