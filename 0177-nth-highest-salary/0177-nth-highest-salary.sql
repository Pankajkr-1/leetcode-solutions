CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    set N=N-1;
  RETURN (
      # Write your MySQL query statement below.
    Select Distinct salary 
    from Employee
    order by salary desc
    limit 1 offset N
  );
END