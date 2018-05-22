# Write your MySQL query statement below
(SELECT salary AS SecondHighestSalary FROM Employee GROUP BY salary ORDER BY salary DESC LIMIT 1,1)
union
(SELECT NULL AS SecondHighestSalary)
LIMIT 1;
