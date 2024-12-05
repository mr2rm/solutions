SELECT
    Signups.user_id,
    ROUND(
        AVG(CASE WHEN Confirmations.action = 'confirmed' THEN 1 ELSE 0 END),
        2
    ) AS confirmation_rate
FROM Signups
LEFT JOIN Confirmations
    ON Confirmations.user_id = Signups.user_id
GROUP BY Signups.user_id;
