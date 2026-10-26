# Write your MySQL query statement below
SELECT DISTINCT num AS ConsecutiveNums
FROM (
    SELECT num,
           id - ROW_NUMBER() OVER (PARTITION BY num ORDER BY id) AS grp
    FROM Logs
) t
GROUP BY num, grp
HAVING COUNT(*) >= 3;