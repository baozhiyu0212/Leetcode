# Write your MySQL query statement below
SELECT
    w1.Id AS Id
FROM
    Weather as w1
    INNER JOIN Weather as w2
    ON w1.RecordDate - INTERVAL 1 DAY = w2.RecordDate
WHERE
    w1.Temperature > w2.Temperature
;
