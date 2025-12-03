CREATE FUNCTION getNthHighestSalary(N INT)
RETURNS INT
DETERMINISTIC
BEGIN
  RETURN (
    SELECT salary
    FROM employee e1
    WHERE (
       SELECT COUNT(DISTINCT e2.salary)
       FROM employee e2
       WHERE e2.salary > e1.salary
    ) = N - 1
    LIMIT 1
  );
END;
