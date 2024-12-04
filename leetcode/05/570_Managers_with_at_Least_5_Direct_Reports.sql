-- Solution 1
SELECT Manager.name
FROM Employee
JOIN Employee AS Manager
    ON Manager.id = Employee.managerId
GROUP BY Employee.managerId, Manager.name
HAVING COUNT(*) >= 5;

-- Solution 2
SELECT name
FROM Employee
WHERE id IN (
    SELECT managerId
    FROM Employee
    GROUP BY managerId
    HAVING COUNT(*) >= 5
);

-- Solution 3
SELECT name
FROM Employee
JOIN (
    SELECT managerId AS id
    FROM Employee
    GROUP BY managerId
    HAVING COUNT(*) >= 5
) AS busy_manager
    ON busy_manager.id = Employee.id;
