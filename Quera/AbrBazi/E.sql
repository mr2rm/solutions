-- Section1
INSERT INTO Player(id, team, age)
    SELECT Person.id, "Chelsea" team, 24 age
    FROM Person
        LEFT JOIN Player ON Player.id = Person.id
        LEFT JOIN Coach ON Coach.id = Person.id
        LEFT JOIN Refree ON Refree.id = Person.id
    WHERE Player.id IS NULL AND Coach.id IS NULL AND Refree.id IS NULL
-- Section2
SELECT Person.id, Person.name
FROM Coach
    INNER JOIN Player on Player.id = Coach.id
    INNER JOIN Person on Person.id = Coach.id
WHERE Coach.team <> Player.team
-- Section3
ALTER TABLE Player
ADD FOREIGN KEY (team) REFERENCES Team(name)
ON DELETE CASCADE;
