# Write your MySQL query statement below
Select score,
    DENSE_RANK() OVER (ORDER BY score DESC) AS `rank`
from Scores
order by score desc;
