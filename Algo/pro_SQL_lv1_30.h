#pragma once
//조건문 반올림 + Case when, else로 조건문 then으로 변수 설정.
SELECT ROUND(AVG(CASE
    WHEN LENGTH IS NULL THEN 10
    WHEN LENGTH < 10 THEN 10
    ELSE LENGTH
    END), 2) AS AVERAGE_LENGTH
    FROM FISH_INFO